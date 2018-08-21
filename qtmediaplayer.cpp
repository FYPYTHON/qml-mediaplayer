
#include "qtmediaplayer.h"
#include <QVideoWidget>
#include <QFile>
#include <QMap>

void QtMediaPlayer::qplay()
{
    qDebug()<<"play..."<<m_filName;
    QMediaPlayer::setMedia(QUrl::fromLocalFile(m_filName));
    QMediaPlayer::play();
//    qreal real = 1;
//    QMediaPlayer::setPlaybackRate(real);
    QString strTitle = QMediaPlayer::metaData("Title").toString();
    QString strSize= QMediaPlayer::metaData("Size").toString();
    qDebug()<<"title: " + strTitle + "size: "+ strSize;
    qDebug()<<QMediaPlayer::supportedAudioRoles()<<endl;
}
void QtMediaPlayer::ready()
{
    QFile file(m_filName);
    if(!file.open(QIODevice::ReadOnly))
        qDebug() << "Could not open file";
    this->setMedia(QUrl::fromLocalFile(m_filName));
    this->setPlaybackRate(qreal(2));
//    this->BufferedMedia
    this->play();
    connect(this, &QMediaPlayer::positionChanged, [this](qint64 position){


            qDebug()<<position<<this->duration()<<endl;
            this->_duration = this->duration();
    });
    this->setPosition(qint64(1));
    qDebug()<<"test:"<<this->duration()<<this->_duration;
}
QtMediaPlayer::QtMediaPlayer(QObject* parent, Flags flags): QMediaPlayer(parent, flags)
{
    if(m_widget){
        qDebug()<<"video widget init ok"<<endl;
    }
    else{
        qDebug()<<"video widget init fail"<<endl;
    }
    connect(this, SIGNAL(metaDataAvailableChanged(bool)), this, SLOT(OnMetaDataAvailableChanged(bool)));
}
void QtMediaPlayer::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Changing surface";
    m_surface = surface;
    setVideoOutput(m_surface);
}
QAbstractVideoSurface* QtMediaPlayer::getVideoSurface()
{
    return m_surface;
}

void QtMediaPlayer::setVideoWidget(QVideoWidget* widget)
{
    qDebug() << "Changing widget";
    m_widget = widget;
    setVideoOutput(m_widget);
}
QVideoWidget* QtMediaPlayer::getVideoWidget()
{
    return m_widget;
}
void QtMediaPlayer::setVideoGraphics(QGraphicsVideoItem* graphcs)
{
    qDebug() << "Changing grphics";
    m_grphics = graphcs;
    setVideoOutput(m_grphics);
}
QGraphicsVideoItem* QtMediaPlayer::getVideoGraphics()
{
    return m_grphics;
}
void QtMediaPlayer::OnMetaDataAvailableChanged(bool available)
{
    // display metadata
    qDebug() << "OnMetaDataAvailableChanged";
    if(available){
        foreach(QString str,availableMetaData()){
            qDebug()<<str<<"   :"<<metaData(str).toString().toUtf8().data();
        }
//        playlist->setCurrentIndex(++count);
    }
}

QString QtMediaPlayer::fileName() const
{
    return m_filName;
}

void QtMediaPlayer::setFileName(const QString &fileName)
{
    m_filName = fileName;
}

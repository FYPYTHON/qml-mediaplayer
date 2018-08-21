#include <QApplication>
//#include <QQmlApplicationEngine>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QFile>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QWindow>
#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVideoFrame>
#include <QVideoProbe>



//int main(int argc, char *argv[])
//{

//    QApplication app(argc, argv);
//    QWidget ui;
//    QMediaPlayer *player;

//    QVBoxLayout *layout = new QVBoxLayout;
//    QHBoxLayout *hlayout = new QHBoxLayout;
//    QPushButton * pPushButton = new QPushButton();
//    pPushButton->setText("打开");
//    QPushButton * playbtn = new QPushButton();
//    playbtn->setText("播放");
//    QPushButton * stopbtn = new QPushButton();
//    stopbtn->setText("暂停");
//    QLabel *label = new QLabel();
//    label->setText("");

//    hlayout->addWidget(pPushButton);
//    hlayout->addWidget(playbtn);
//    hlayout->addWidget(stopbtn);


//    QVideoWidget* vw = new QVideoWidget();
//    layout->addLayout(hlayout);
//    layout->addWidget(vw);


//    player=new QMediaPlayer();

//    player->setVideoOutput(vw);

//    QFile file("C:/Users/Faye/Documents/GroundStation/Video/2018-07-31_13.50.46.mov"); /*2018-07-31_14.25.33.mkv*/
//    if(!file.open(QIODevice::ReadOnly))
//        qDebug() << "Could not open file";
//    player->setMedia(QUrl::fromLocalFile("C:/Users/Faye/Documents/GroundStation/Video/2018-07-31_13.50.46.mov"));
////    player->setMedia(&file);
//    qDebug()<<player->supportedAudioRoles()<<endl;
//    player->setPlaybackRate(qreal(5.0));
//    player->play();
//    qDebug()<<"video duration:"<<player->duration()<<endl;
//    foreach(QString str,player->availableMetaData()){
//        qDebug()<<str<<"   :"<<player->metaData(str).toString().toUtf8().data();
//    }
//    qDebug()<<"slkd:"<<file.size()<<endl;
//    ui.setLayout(layout);
//    ui.resize(500,600);
//    ui.show();

//    return app.exec();
//}

//---------------------------------------------

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qtmediaplayer.h"
#include "QVideoWidget"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

//    QtMediaPlayer* player = new QtMediaPlayer();
    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("qtmediaplayer", player);
    qmlRegisterType<QtMediaPlayer>("QtMediaPlayer",1,0,"QtMediaPlayer");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}


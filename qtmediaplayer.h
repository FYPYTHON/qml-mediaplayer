#ifndef QTMEDIAPLAY_H
#define QTMEDIAPLAY_H

#include <QMediaPlayer>
#include <QAbstractVideoSurface>
#include <QVideoWidget>
#include <QGraphicsVideoItem>






class QtMediaPlayer: public QMediaPlayer
{
Q_OBJECT
public:
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ getVideoSurface WRITE setVideoSurface )
    Q_PROPERTY(QVideoWidget* videoWidget READ getVideoWidget WRITE setVideoWidget )
    Q_PROPERTY(QGraphicsVideoItem* videoGraphics READ getVideoGraphics WRITE setVideoGraphics )
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)

    Q_INVOKABLE void qplay();
    Q_INVOKABLE void ready();
public:
    QtMediaPlayer(QObject * parent = 0, Flags flags = 0);

    QString fileName() const;
    void setFileName(const QString &);

public slots:

    void setVideoSurface(QAbstractVideoSurface* surface);
    QAbstractVideoSurface* getVideoSurface();

    void setVideoWidget(QVideoWidget* widget);
    QVideoWidget* getVideoWidget();

    void setVideoGraphics(QGraphicsVideoItem* graph);
    QGraphicsVideoItem* getVideoGraphics();

    void OnMetaDataAvailableChanged(bool available);

private:
    QAbstractVideoSurface* m_surface;
    QGraphicsVideoItem *m_grphics;
    QVideoWidget * m_widget;
    QString m_filName;
    qint64 _duration;
};

#endif // QTMEDIAPLAY_H

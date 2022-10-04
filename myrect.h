#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QSoundEffect>

//#define DEBUG

class MyRect:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  MyRect(QGraphicsItem *parent = nullptr);

protected:
  void keyPressEvent(QKeyEvent *event);

public slots:
  void spawn();
  bool healthStatus();

private:
  QSoundEffect *bulletsound;
};

#endif // MYRECT_H

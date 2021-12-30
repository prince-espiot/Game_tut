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
class MyRect:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  MyRect(QGraphicsItem *parent = nullptr);

 // QRectF  boundingRect() const;
  //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
  void keyPressEvent(QKeyEvent *event);

public slots:
  void spawn();

private:
  QSoundEffect *bulletsound;
};

#endif // MYRECT_H

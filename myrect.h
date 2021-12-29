#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QSoundEffect>
class MyRect:public QObject,public QGraphicsRectItem
{
  Q_OBJECT
public:
 explicit MyRect(QObject *parent = nullptr);

  QRectF  boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
  void keyPressEvent(QKeyEvent *event);

public slots:
  void spawn();

private:
  QSoundEffect *bulletsound;
};

#endif // MYRECT_H

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Enemy(QGraphicsItem * parent = nullptr);
  void fireBullet();
public slots:
  void move();

private:
  QTimer *timer;
  QTimer *bulletTimer;

};

#endif // ENEMY_H

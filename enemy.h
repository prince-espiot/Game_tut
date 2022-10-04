#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#define DEBUG 


class Enemy:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Enemy(QGraphicsItem * parent = nullptr);
public slots:
  void move();

private:
  QTimer *timer;

};

#endif // ENEMY_H

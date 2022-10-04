#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "score.h"
//#define DEBUG

class Bullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
  Bullet(QGraphicsItem * parent = nullptr);

public slots:
  void move();

private:
  QTimer *timer;

};

#endif // BULLET_H

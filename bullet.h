#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

#include "score.h"


class Bullet:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
  Bullet();

public slots:
  void move();

private:
  QTimer *timer;

};

#endif // BULLET_H

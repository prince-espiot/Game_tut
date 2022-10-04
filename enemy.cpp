#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand really large integer

#include "mainwindow.h"

extern MainWindow *w;  //and extern on the mainwindow that allow dreasement of the health


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  //Set random position
  int random_num = rand()%500;
  setPos(random_num,0);

  //drew rect
  //setRect(0,0,100,100);
  setPixmap(QPixmap(":/images/Resources/jetenemy.png"));

  //connect
 timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}

void Enemy::move()
{
  //move bullet DOWN
  setPos(x(),y()+5);
  if(pos().y() > 850){
      w->health->decreaseScore();
      scene()->removeItem(this);
      delete this;
      #ifdef DEBUG
      qDebug()<< "enemey delete";
      #endif
    }
}

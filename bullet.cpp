#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "mainwindow.h"

extern MainWindow *w;


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  //drew image
  //setRect(0,0,10,30);
  setPixmap(QPixmap(":/images/Resources/resizefirebullet.png"));


  //connect
 timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}

void Bullet::move()
{
  //if bullet collide with with enemy destory both
  QList<QGraphicsItem *> colliding_Items = collidingItems();
  for(int i =0, n = colliding_Items.size(); i<n ; ++i){
      if(typeid(*(colliding_Items[i])) == typeid (Enemy)){
          w->score->increaseScore();
          scene()->removeItem(colliding_Items[i]);
          scene()->removeItem(this);
          delete colliding_Items[i];
          delete this;
          return;
        }
    }
  //move bullet up
  setPos(x(),y()-10);
  if(pos().y() < 0){
      scene()->removeItem(this);
      delete this;
      qDebug()<< "bullet delete";
    }
}

#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
//#include "mainwindow.h"
#include "introWindow.h"

extern MainWindow *w;


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
  //drew image
  //setRect(0,0,10,30);
  setPixmap(QPixmap(":/images/Resources/resizefirebullet.png"));

  //mainWindow = new MainWindow;

  //connect
 timer = new QTimer(this);
 connect(timer,&QTimer::timeout,this,QOverload<>::of(&Bullet::move));

 timer->start(25); // change this when switching up the levels
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
  setPos(x(),y()-30);
  if(pos().y() < 0){
      scene()->removeItem(this);
      delete this;
      qDebug()<< "bullet delete";
    }
}

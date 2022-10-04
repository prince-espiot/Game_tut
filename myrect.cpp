#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include "mainwindow.h"

extern MainWindow *w;

MyRect::MyRect(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
  bulletsound = new QSoundEffect(this);
  bulletsound->setSource(QUrl("qrc:/sounds/gun-gunshot-01.wav"));
  //bulletsound->setLoopCount(QSoundEffect::Infinite);
 // bulletsound->setVolume(0.15f);
  setPixmap(QPixmap(":/images/Resources/playerresize.png"));
  setTransformOriginPoint(50,50);
  setRotation(270);
  setFlag(ItemIsFocusable);
  setFocus();
}


void MyRect::keyPressEvent(QKeyEvent *event)
{
  if(event->key()==Qt::Key_Left){
      if (pos().x() > 0){
        setPos(x()-10,y());}
    }
  else if (event->key()==Qt::Key_Right){
      if (pos().x()+boundingRect().width()+8 <scene()->width()){
      setPos(x()+10,y());}
    }

 else if (event->key()==Qt::Key_Space){
      //creat a bullet

      Bullet *bullet = new Bullet();
      bullet->setPos(x()+45,y());
      scene()->addItem(bullet);
      //play bulletsound
      if (bulletsound->isPlaying()){
          bulletsound->stop();
        }
      bulletsound->play();

      /*if (bulletsound->playbackState() == QMediaPlayer::PlayingState){
          bulletsound->setPosition(0);
        } //play sound in recall
      else if(bulletsound->playbackState() == QMediaPlayer::StoppedState){
      bulletsound->play();} */

    }
    #ifdef DEBUG
  qDebug()<< "Key preesseed";
    #endif
}


void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

bool MyRect::healthStatus()
{
  if (w->health->getScore()==0)
  //timer->stop();
  #ifdef DEBUG
  qDebug()<< "Healthss is below zero";
  #endif
  return true;

}

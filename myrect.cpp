#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>

MyRect::MyRect(QObject *parent): QObject(parent)
{
  bulletsound = new QSoundEffect(this);
  bulletsound->setSource(QUrl("qrc:/sounds/gun-gunshot-01.wav"));
  //bulletsound->setLoopCount(QSoundEffect::Infinite);
 // bulletsound->setVolume(0.15f);
 
  setFlag(ItemIsFocusable);
  setFocus();
}

QRectF MyRect::boundingRect() const
{
   return QRectF (0,0,100,100);
}

void MyRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

  QRectF rec = boundingRect();
  QBrush brush (Qt::transparent);
  painter->fillRect(rec,brush);
  painter->drawRect(rec);

  Q_UNUSED(option);
  Q_UNUSED(widget);

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
  qDebug()<< "Key preesseed";
}

void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>



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
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - 15, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + boundingRect().width() + 10 < scene()->width()) {
            setPos(x() + 15, y());
        }
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0) {
            setPos(x(), y() - 15);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + boundingRect().height() + 8 < scene()->height()) {
            setPos(x(), y() + 15);
        }
    }
    else if (event->key() == Qt::Key_Space) {
        // Create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 30, y());  // to the side of the jet
        scene()->addItem(bullet);

        // Play bulletsound
        if (bulletsound->isPlaying()) {
            bulletsound->stop();
        }
        bulletsound->play();
    }

    qDebug() << "Key pressed";
}


void MyRect::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

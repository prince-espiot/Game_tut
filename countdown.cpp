#include "countdown.h"
#include <QFont>

countdown::countdown(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
  //time = 120;
  ttime  = new QTime  (0, 2, 0);
  setPlainText(QString("Time Left: ")+ (ttime->toString("m:ss")));
  setDefaultTextColor(Qt::red);
  setFont(QFont("time", 16));
  setPos(450,0);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(updateCountdown()));
    timer->start(1000);

}

void countdown::updateCountdown()
{
 ttime->setHMS (0, ttime->addSecs (-1).minute (), ttime->addSecs (-1).second ());
 setPlainText(QString("Time Left: ")+ (ttime->toString("m:ss")));
 if ((ttime->toString("m:ss")) == (ttime->toString("0:00"))){
     timer->stop();
   }
#ifdef DEBUG
 qDebug()<<"timer downworking";
#endif
}

QTime *countdown::getTime()
{
    return ttime;
}

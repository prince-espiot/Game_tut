#include "health.h"
#include <QFont>



Health::Health(QGraphicsItem *parent)
{
  //initialise score to zero
  score = 20;

  //draw text
  setPlainText(QString("Health: ")+ QString::number(score));  //score: 0
  setDefaultTextColor(Qt::red);
  setFont(QFont("time", 16));
  setPos(0,20);
}

void Health::decreaseScore()
{
  score --;
  setPlainText(QString("Health: ")+ QString::number(score));
}

int Health::getScore()
{
  return score;
}

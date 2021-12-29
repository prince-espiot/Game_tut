#include "score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
  //initialise score to zero
  score = 0;

  //draw text
  setPlainText(QString("Score: ")+ QString::number(score));  //score: 0
  setDefaultTextColor(Qt::green);
  setFont(QFont("time", 16));
}

void Score::increaseScore()
{
    score++;
    setPlainText(QString("Score: ")+ QString::number(score));
}

int Score::getScore()
{
  return score;
}

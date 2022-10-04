#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Health:public QGraphicsTextItem
{
public:
  Health(QGraphicsItem * parent = nullptr);

  void decreaseScore();
  int getScore();
private:
  int score;
};

#endif // HEALTH_H

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>


class Health:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
  Health(QGraphicsItem * parent = nullptr);

  void decreaseScore();
  //void decreaseHealth();
  void increaseHealth();
  void updateHealthDisplay();
  int getScore();
  int getCurrentHealth();
signals:
  void healthReachedZero();
  void restartGameSignal();
  void closeGameSignal();
public slots:
    void decreaseHealth();
private:
  int score;
  int maxHealth;
  int currentHealth;
  QList<QGraphicsPixmapItem*> hearts; // QList to store heart items
};

#endif // HEALTH_H

#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QTime>
#include <QTimer>
#include <QObject>

//#define DEBUG

class countdown: public QGraphicsTextItem
{
  Q_OBJECT
public:
  countdown(QGraphicsItem * parent = nullptr);
  QTime *getTime();


public slots:
  void updateCountdown();

private:
  int time;
  QTime *ttime;
  QTime *ref;
  QTimer *timer;
};

#endif // COUNTDOWN_H

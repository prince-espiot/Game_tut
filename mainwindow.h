#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSoundEffect>
#include <QBrush>
#include "myrect.h"
#include "score.h"
#include "health.h"
#include "countdown.h"
#include <QTimer>
#include <QList>

#define DEBUG

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void playerPos();
  void spawnEnemy();
  Score *score;
  Health *health;
  countdown *count;
private slots:
  //void on_actionNew_triggered();



private:
  Ui::MainWindow *ui;
  MyRect *player;
  QGraphicsScene *scene;
  QTimer *timer;


};
#endif // MAINWINDOW_H

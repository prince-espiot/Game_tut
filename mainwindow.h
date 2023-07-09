#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSoundEffect>
#include <QBrush>
#include "myrect.h"
#include "score.h"
#include "health.h"
#include <QTimer>
#include <QList>
#include "DialogWindow.h"

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
  void showDialogWindow();
  void closeDialogWindow();
 // MainWindow* w;

  Score *score;
  Health *health;
private slots:
  //void on_actionNew_triggered();
  void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);
  //void onIntroWindowStartGame();

public slots:
  void restartGame();
  void closeGame();



private:
  Ui::MainWindow *ui;
  MyRect *player;
  QGraphicsScene *scene;
  QTimer *timer;
  QGraphicsView *view;
  DialogWindow *dialogWindow ;



};
#endif // MAINWINDOW_H

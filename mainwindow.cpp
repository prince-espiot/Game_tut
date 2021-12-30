#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  scene = new QGraphicsScene(this);
  player = new MyRect();
  scene->addItem(player);
  ui->graphicsView->setScene(scene);
  scene->setBackgroundBrush(QBrush(QImage(":/images/Resources/backgroundresized.png")));
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setFixedSize(600,800);
  scene->setSceneRect(0,0,600,800);
  player->setPos((scene->width())/2,scene->height() - player->boundingRect().height());

  //create score
  score = new Score();
  scene->addItem(score);

  // creat health
  health = new Health();
  scene->addItem(health);
  spawnEnemy();

  //play background music

  QMediaPlayer *music = new QMediaPlayer(this);
  music->setSource(QUrl("qrc:/sounds/Shatta Wale-Kakai.mp3"));
  //music->setVolume(0.15f); 
  music->play();
  connect(ui->actionQuit, &QAction::triggered,this, &QApplication::quit);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::playerPos()
{

  player->setPos(ui->graphicsView->width()/2,ui->graphicsView->height()- player->boundingRect().height());
}

void MainWindow::spawnEnemy()
{
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
}


/*void MainWindow::on_actionNew_triggered()
{

  ///there is a segmentations error here deal with is later
      QList<QGraphicsItem *> scene_item;
      scene_item.push_back(player);
      for (auto i:scene_item){
          delete i;
        }
}*/




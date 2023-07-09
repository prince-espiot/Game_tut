#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 600, 800); // Set the desired dimensions of the scene
    scene->setBackgroundBrush(QBrush(QImage(":/images/Resources/backgroundresized.png")));

    // Create the view and set its properties
    view = new QGraphicsView(scene, this);
    view->setFixedSize(600, 800); // Set the fixed size of the view
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Set the view as the central widget of the main window
    setCentralWidget(view);

    // Create the player
    player = new MyRect();
    player->setPos(scene->width() / 2, scene->height() - player->boundingRect().height());
    scene->addItem(player);

    // Create the score
    score = new Score();
    scene->addItem(score);

    // Create the health
    health = new Health();
    scene->addItem(health);

    // Spawn enemies
    spawnEnemy();

    // Play background music
    QMediaPlayer *music = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/DZ.mp3"));
    audioOutput->setVolume(50);
    // Connect mediaStatusChanged signal to a slot
    connect(music, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::handleMediaStatusChanged);
    music->play();


    // Connect the restartGameSignal() and closeGameSignal() from the Health class to slots in the MainWindow class
    connect(health, &Health::restartGameSignal, this, &MainWindow::showDialogWindow);
    //connect(dialogWindow, &DialogWindow::closeGameSignal, this, &MainWindow::closeGame);


    // Connect the quit action
    connect(ui->actionQuit, &QAction::triggered, this, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::spawnEnemy()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
}

void MainWindow::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        // Restart the playback
        QMediaPlayer *music = qobject_cast<QMediaPlayer*>(sender());
        if (music)
        {
            music->setPosition(0);
            music->play();
        }
    }
}

void MainWindow::restartGame()
{
    // Reset the game state, clear the scene, etc.
    scene->clear(); // Clear the scene
    // Other game state reset operations...

    // Create the player
    player = new MyRect();
    player->setPos(scene->width() / 2, scene->height() - player->boundingRect().height());
    scene->addItem(player);

    // Create the score
    score = new Score();
    scene->addItem(score);

    // Create the health
    health = new Health();
    scene->addItem(health);

    // Spawn enemies
    spawnEnemy();

    // Show the MainWindow again
    show();
    dialogWindow->close();
}


void MainWindow::closeGame() //uselesss thingsssss
{
    // Perform the necessary actions to close the game
    // For example, save the game state, clean up resources, etc.
    qDebug()<< "Closeing";
    // Close the application
    QApplication::quit();
}

void MainWindow::showDialogWindow()
{
    // Create the dialog window
    dialogWindow = new DialogWindow(this);
    dialogWindow->show();
    connect(dialogWindow, &DialogWindow::restartGameSignal, this, &MainWindow::restartGame);

}


void MainWindow::closeDialogWindow()
{
    // Perform the necessary actions to reset the game
    // For example, reset the game state, clear the scene, etc.
    QApplication::quit();
    // Close the dialog window
    dialogWindow->close();

    // Show the MainWindow again
}


#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand really large integer
#include "bullet.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>



extern MainWindow* w; // extern on the mainwindow that allows decrement of health

Enemy::Enemy(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // Set random position
    int random_num = rand() % 1000;
    setPos(random_num, 0);

    // Set pixmap
    setPixmap(QPixmap(":/images/Resources/jetenemy.png"));

    // Connect timer to move slot
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Enemy::move));

    timer->start(25); // Change this when switching up the levels makes the enermy moves faster

    bulletTimer = new QTimer();
    connect(bulletTimer, &QTimer::timeout, this, &Enemy::fireBullet);
    bulletTimer->start(7000);
}

void Enemy::move()
{
    // Check for collision with the player (MyRect)
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (QGraphicsItem *item : collidingItemsList)
    {
        if (dynamic_cast<MyRect *>(item))
        {
            // Reduce the player's health
            w->health->decreaseHealth();

            // Remove the enemy from the scene
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    // Move the enemy downwards
    setPos(x(), y() + 5);

    // Check if the enemy is out of bounds
    if (pos().y() > 900)
    {
        //w->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy deleted";
    }
}

void Enemy::fireBullet()
{
    // Create a bullet
    Bullet *bullet = new Bullet();
    bullet->setPos(x() + pixmap().width() / 2 - bullet->pixmap().width() / 2, y() + pixmap().height());
    scene()->addItem(bullet);
}


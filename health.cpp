#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // Initialize score to zero
    maxHealth = 5;
    currentHealth = 5;

    int startX = 0;
    int startY = 25;

    QPixmap image(":/images/Resources/red_hearts.png"); // Load the image

    int desiredWidth = 30;  // Set the desired width
    int desiredHeight = 30; // Set the desired height

    // Create and store the heart items in the 'hearts' vector
    for (int i = 0; i < maxHealth; ++i)
    {
        QGraphicsPixmapItem* heartItem = new QGraphicsPixmapItem(this);
        heartItem->setPixmap(image.scaled(desiredWidth, desiredHeight));
        heartItem->setPos(startX + (desiredWidth * i), startY);
        hearts.push_back(heartItem); // Store the heart item in the 'hearts' vector

        if (parentItem())
        {
            parentItem()->scene()->addItem(heartItem);
        }
    }
}

void Health::decreaseHealth()
{
    if (currentHealth > 0)
    {
        currentHealth--;
        hearts[currentHealth]->setVisible(false); // Hide the heart item at the current health index
        qDebug() << "Decreased health: " << currentHealth;
    }

    // Check if health drops to 0
        if (currentHealth == 0)
        {
            emit restartGameSignal();

        }
}

int Health::getCurrentHealth()
{
    return currentHealth;
}

int Health::getScore()
{
    return score;
}



// DialogWindow.cpp
#include "DialogWindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>


DialogWindow::DialogWindow(QWidget *parent) : QDialog(parent)
{
    QLabel *messageLabel = new QLabel("Your health has dropped to 0. Do you want to restart or close the game?");
    QPushButton *restartButton = new QPushButton("Restart");
    QPushButton *closeButton = new QPushButton("Close");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(messageLabel);
    layout->addWidget(restartButton);
    layout->addWidget(closeButton);

    setLayout(layout);

    connect(restartButton, &QPushButton::clicked, this, &DialogWindow::onRestartClicked);
    connect(closeButton, &QPushButton::clicked, this, &DialogWindow::onCloseClicked);
}

void DialogWindow::onRestartClicked()
{
    // Handle restart action
    // For example, emit a signal to restart the game
    emit restartGameSignal();
}

void DialogWindow::onCloseClicked()
{
    // Handle close action
    // For example, emit a signal to close the game
    emit closeGameSignal();
    qDebug()<< "Hi I miit close";
    QApplication::quit();
}

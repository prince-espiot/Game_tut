
#include "introWindow.h"



IntroWindow::IntroWindow(QWidget *parent) : QMainWindow(parent)
{
    // Set up the layout, buttons, etc. for the intro window
    // Connect signals and slots for user interactions
    QLabel *messageLabel = new QLabel("Your health has dropped to 0. Do you want to restart or close the game?");

    // Create input fields for name and age
    nameLineEdit = new QLineEdit(this);
    ageLineEdit = new QLineEdit(this);

    // Create buttons
     startGameButton = new QPushButton("Start Game", this);
     closeButton = new QPushButton("Close", this);

 // Create a layout for the intro window
     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(new QLabel("Name:"));
     layout->addWidget(nameLineEdit);
     layout->addWidget(new QLabel("Age:"));
     layout->addWidget(ageLineEdit);
     layout->addWidget(startGameButton);
     layout->addWidget(closeButton);

     QWidget *widget = new QWidget(this);
     widget->setLayout(layout);
     setCentralWidget(widget);


    // Connect button signals to slots
    connect(startGameButton, &QPushButton::clicked, this, &IntroWindow::onStartGameClicked);
    connect(closeButton, &QPushButton::clicked, this, &IntroWindow::onCloseClicked);

}

IntroWindow::~IntroWindow()
{

}

void IntroWindow::onStartGameClicked()
{
    // Get the entered name and age
    QString name = nameLineEdit->text();
    int age = ageLineEdit->text().toInt();

    // Emit the startGameSignal


    // Close the intro window
    close();

}

void IntroWindow::onCloseClicked()
{
    // Close the application
    qDebug()<< "Close the application";
                            //there is a memory leaked here fix later....
    QApplication::quit();
}







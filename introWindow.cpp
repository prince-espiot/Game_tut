
#include "introWindow.h"



IntroWindow::IntroWindow(QWidget *parent) : QMainWindow(parent)
{
    // Set up the layout, buttons, etc. for the intro window
    // Connect signals and slots for user interactions

    // Create a QSqlTableModel
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("users"); // Replace "users" with your table name
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Age");
    model->select();

    // Create the QTableView and set the model
    QTableView *tableView = new QTableView(this);
    tableView->setModel(model);

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
    layout->addWidget(tableView); // Add the QTableView to the layout

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

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("C:/Users/okumo/Documents/FUN STUFFS/Game_tut/gamedb.db");
    if (db.open()) {
        // Connection successful
        qDebug() << "Connected to MySQL server";
    } else {
        // Connection failed
        qDebug() << "Failed to connect to MySQL server: " << db.lastError().text();
    }

    //now query the database
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(50), age INT)");
    query.prepare("INSERT INTO users (name, age) VALUES (:name, :age)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    if (query.exec()) {
        qDebug() << "Data inserted successfully";
    } else {
        qDebug() << "Failed to insert data: " << query.lastError().text();
    }

    // Emit the startGameSignal
    emit startGameSignal();
    qDebug()<< "Emit the startGameSignal";
    // Close the intro window
    close();

    // Prepare the SELECT query
    query.prepare("SELECT name, age FROM users");

    // Execute the query
    if (query.exec()) {
        // Iterate over the result set
        while (query.next()) {
            // Retrieve the values of the columns
            QString name = query.value(0).toString();
            int age = query.value(1).toInt();

            // Process the retrieved data
            // For example, print the values to the console
            qDebug() << "Name:" << name << "Age:" << age;
        }
    } else {
        // Handle the query execution error
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }

}

void IntroWindow::onCloseClicked()
{
    // Close the application
    qDebug()<< "Close the application";
                            //there is a memory leaked here fix later....
    QApplication::quit();
}







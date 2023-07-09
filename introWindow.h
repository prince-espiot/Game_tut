#ifndef INTROWINDOW_H
#define INTROWINDOW_H

#include <QMainWindow>
// Include the header file for the main window
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>


class IntroWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntroWindow(QWidget *parent = nullptr);
    ~IntroWindow();

signals:
    void startGameSignal();

private slots:
    void onStartGameClicked();
    void onCloseClicked();

private:

    QLineEdit *nameLineEdit;
    QLineEdit *ageLineEdit;
    QPushButton *startGameButton;
    QPushButton *closeButton;


};

#endif // INTROWINDOW_H

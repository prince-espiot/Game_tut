#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QDialog>
#include <QApplication>
#include <QDebug>


class DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
signals:
    void restartGameSignal();
    void closeGameSignal();
private slots:
    void onRestartClicked();
    void onCloseClicked();
};

#endif // DIALOGWINDOW_H

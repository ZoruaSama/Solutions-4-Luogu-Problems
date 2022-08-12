#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_btnNewGame_clicked();
    void on_btnRegret_clicked();
    void on_btnRotate_clicked();
    void requestReceived(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *event);



    void mousePressEvent(QMouseEvent *event);



};

#endif // MAINWINDOW_H

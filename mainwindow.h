#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_a1_clicked();

    void on_actionNew_game_with_human_triggered();

    void on_a2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

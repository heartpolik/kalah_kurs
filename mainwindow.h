#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

struct sData
{
    int idBtn;
    int count;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_a1_clicked();
    void on_a2_clicked();

    void on_actionNew_game_with_human_triggered();

    void on_a6_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

    void on_a5_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_actionExit_triggered();

private:
    void _init_game();
    void _update_btns();

    void _btn_processing(int aCount, int aIDBtn);

private:
    Ui::MainWindow *ui;

private:
    QVector<sData> mVector;
};

#endif // MAINWINDOW_H

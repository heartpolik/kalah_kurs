#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

/**
* @brief sData is a container for store
* info about each key (play field)
* idBtn  - id of each button
* count  - number of seeds in field
* player - what player this field belongs to 
*/
struct sData
{
    int idBtn;
    int count;
    char player;
    bool isDisabled;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief TEST DESCRIPTION
     */
    ~MainWindow();

private slots:

    void on_a1_clicked();
    void on_a2_clicked();
    void on_a3_clicked();
    void on_a4_clicked();
    void on_a5_clicked();
    void on_a6_clicked();

    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();

    void on_actionNew_game_with_human_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_triggered();

private:

    /*
     * @brief TEST DESCRIPTION
     */
    void _init_game();
    void _update_btns();

    void _btn_processing(int aIDBtn);

    char _switchTurn(int pButtonId);

    void _setTurn(char player);

    bool _checkEndGame(char player);

    void _setEndGame();

private:
    Ui::MainWindow *ui;

private:
    QVector<sData> mVector;
};

#endif // MAINWINDOW_H

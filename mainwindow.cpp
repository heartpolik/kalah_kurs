#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVBoxLayout>
#include <QMessageBox>
#include <string.h>
#include <QtTest/QTest>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _init_game();
//    _update_btns();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isTurn = true;

void
    MainWindow::_init_game()
{
    mVector.resize(14); // count btns

    sData tmp;

    tmp.count = 6;  //  !!!
    tmp.player = 'a';

    // btn a1
    tmp.idBtn  = 1;
    mVector[0] = tmp;

    // btn a2
    tmp.idBtn  = 2;
    mVector[1] = tmp;

    // btn a3
    tmp.idBtn = 3;
    mVector[2] = tmp;

    // btn a4
    tmp.idBtn = 4;
    mVector[3] = tmp;

    // btn a5
    tmp.idBtn = 5;
    mVector[4] = tmp;

    // btn a6
    tmp.idBtn = 6;
    mVector[5] = tmp;

    // btn ak
    tmp.player='A';
    tmp.idBtn = 7;
    tmp.count = 0;
    mVector[6] = tmp;

    // btn b1
    tmp.count = 6;  //!!!
    tmp.idBtn = 8;
    tmp.player = 'b';
    mVector[7] = tmp;

    // btn b2
    tmp.idBtn = 9;
    mVector[8] = tmp;

    // btn b3
    tmp.idBtn = 10;
    mVector[9] = tmp;

    // btn b4
    tmp.idBtn = 11;
    mVector[10] = tmp;

    // btn b5
    tmp.idBtn = 12;
    mVector[11] = tmp;

    // btn b6
    tmp.idBtn = 13;
    mVector[12] = tmp;

    // btn bk
    tmp.player='B';
    tmp.count = 0;
    tmp.idBtn = 14;
    mVector[13] = tmp;

    ui->label->setText("Натисніть F2!");
}

void
    MainWindow::_update_btns()
{
    ui->a1->setText(QString::number(mVector[0].count));
    ui->a2->setText(QString::number(mVector[1].count));
    ui->a3->setText(QString::number(mVector[2].count));
    ui->a4->setText(QString::number(mVector[3].count));
    ui->a5->setText(QString::number(mVector[4].count));
    ui->a6->setText(QString::number(mVector[5].count));
    ui->ak->setText(QString::number(mVector[6].count));

    ui->b1->setText(QString::number(mVector[7].count));
    ui->b2->setText(QString::number(mVector[8].count));
    ui->b3->setText(QString::number(mVector[9].count));
    ui->b4->setText(QString::number(mVector[10].count));
    ui->b5->setText(QString::number(mVector[11].count));
    ui->b6->setText(QString::number(mVector[12].count));

    ui->bk->setText(QString::number(mVector[13].count));

    ui->a1->setDisabled(mVector[0].isDisabled);
    ui->a2->setDisabled(mVector[1].isDisabled);
    ui->a3->setDisabled(mVector[2].isDisabled);
    ui->a4->setDisabled(mVector[3].isDisabled);
    ui->a5->setDisabled(mVector[4].isDisabled);
    ui->a6->setDisabled(mVector[5].isDisabled);

    ui->b1->setDisabled(mVector[7].isDisabled);
    ui->b2->setDisabled(mVector[8].isDisabled);
    ui->b3->setDisabled(mVector[9].isDisabled);
    ui->b4->setDisabled(mVector[10].isDisabled);
    ui->b5->setDisabled(mVector[11].isDisabled);
    ui->b6->setDisabled(mVector[12].isDisabled);

    ui->ak->setDisabled(true);
    ui->bk->setDisabled(true);
}

char
    MainWindow::_switchTurn(int pButtonId)
{
    if (mVector[pButtonId].player == 'a')
    {
        return 'b';
    }
    if (mVector[pButtonId].player == 'b')
    {
        return 'a';
    }
}

bool
    MainWindow::_checkEndGame(char player)
    {
        for (int i = 0; i < 14; ++i)
        {
            if (mVector[i].player == player && mVector[i].count!=0)
            {
                return false;
            }
        }
        return true;
    }


void
    MainWindow::_setEndGame()
{
    int a = 0,
        b = 0;
    char message[255] = "  Гру закінчено,\nвиграв гравець А";
    for (int i = 0; i < 14; ++i)
    {
        if (mVector[i].player == 'a')
        {
            a += mVector[i].count;
            mVector[i].count=0;
        }
        if (mVector[i].player == 'b')
        {
            b += mVector[i].count;
            mVector[i].count = 0;
        }
    }
    mVector[6].count += a;
    mVector[13].count += b;

    if (mVector[6].count < mVector[13].count)
    {
        strcpy(message,"  Гру закінчено,\nвиграв гравець Б");
    }
    else if (mVector[6].count==mVector[13].count)
    {
        strcpy(message,"Нічия!");
    }
    ui->label->setText("F2 for new game!");

    QMessageBox::warning(0,"Вітання!", message);
}

void
    MainWindow::_setTurn(char player)
{
    ui->label->setText("Хід гравця :");
    char* textLabel = "А";
    
    if (player == 'b')
    {
        textLabel="Б";
    }

    ui->count->setText(textLabel);

    for (int i=0; i<=13;++i)
    {
        if (mVector[i].player!=player || mVector[i].count==0)
        {
            mVector[i].isDisabled = true;
        }
        else
        {
            mVector[i].isDisabled = false;
        }
    }
    MainWindow::_update_btns();
}

void
    MainWindow::_btn_processing(int aIDBtn)
{
    static char aturn = 'a'; // player, who turns first

    // init of players and enemy kalah cells
    int aSkip  = 13,
        aKalah = 6;

    if (mVector[aIDBtn].player=='b')
    {
        aSkip = 6;
        aKalah  = 13;
    }
    // eof init

    isTurn = false; //lock buttons to push while processing

    int tmp = mVector[aIDBtn].count;
    mVector[aIDBtn].count = 0;

    int i=0;
    while (tmp>0)
    {
        ++i;

        if ((aIDBtn+i)==aSkip)
        {
            continue;
        }

        if ((aIDBtn+i)==14)
        {
            i=-aIDBtn;
        }

    --tmp;
        ui->count->setText(QString::number(tmp));
        mVector[aIDBtn+i].count++;

        MainWindow::_update_btns();
        QTest::qWait(300);



    }

    if(mVector[aIDBtn+i].player==mVector[aIDBtn].player)
    {
        if (mVector[aIDBtn+i].count==1 && mVector[12-(aIDBtn+i)].count>0)
        {
            int tmpCount = 1+mVector[12-(aIDBtn+i)].count;
            mVector[12-(aIDBtn+i)].count=0;
            mVector[aIDBtn+i].count=0;
            mVector[aKalah].count+=tmpCount;
        }
        aturn = MainWindow::_switchTurn(aIDBtn);

    }
    else if (aIDBtn+i==aKalah)
    {
        // do nothing
    }
    else
    {
        aturn = MainWindow::_switchTurn(aIDBtn);
    }

   // MainWindow::_setTurn(aturn);

    if (MainWindow::_checkEndGame(aturn))
    {
        MainWindow::_setEndGame();
        //exit(0);
    }
    MainWindow::_setTurn(aturn);

    isTurn = true;
}


// button slots (game field)
void MainWindow::on_a1_clicked()
{
    if (isTurn)
    _btn_processing(0);
}

void MainWindow::on_a2_clicked()
{
    if (isTurn)
    _btn_processing(1);
}

void MainWindow::on_a3_clicked()
{
    if (isTurn)
    _btn_processing(2);
}

void MainWindow::on_a4_clicked()
{
    if (isTurn)
    _btn_processing(3);
}

void MainWindow::on_a5_clicked()
{
    if (isTurn)
    _btn_processing(4);
}

void MainWindow::on_a6_clicked()
{
    if (isTurn)
    _btn_processing(5);
}

void MainWindow::on_b1_clicked()
{
    if (isTurn)
    _btn_processing(7);
}

void MainWindow::on_b2_clicked()
{
    if (isTurn)
    _btn_processing(8);
}

void MainWindow::on_b3_clicked()
{
    if (isTurn)
    _btn_processing(9);
}

void MainWindow::on_b4_clicked()
{
    if (isTurn)
    _btn_processing(10);
}

void MainWindow::on_b5_clicked()
{
    if (isTurn)
    _btn_processing(11);
}

void MainWindow::on_b6_clicked()
{
    if (isTurn)
    _btn_processing(12);
}

//menu slots
void MainWindow::on_actionNew_game_with_human_triggered()
{
    _init_game();
    _update_btns();
    MainWindow::_setTurn('a');
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(0, "About", "Гра Калах v0.4 \n    by Polik");
}

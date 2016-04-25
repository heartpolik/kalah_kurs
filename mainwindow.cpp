#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVBoxLayout>

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

void MainWindow::_init_game()
{
    mVector.resize(14); // count btns

    sData tmp;

    tmp.count = 6;
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
    tmp.idBtn = 7;
    tmp.count = 0;
    mVector[6] = tmp;

    // btn b1
    tmp.count = 6;
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
    tmp.count = 0;
    tmp.idBtn = 14;
    mVector[13] = tmp;
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

//    ui->a1->setDisabled(mVector[0].count == 0);
//    ui->a2->setDisabled(mVector[1].count == 0);
//    ui->a3->setDisabled(mVector[2].count == 0);
//    ui->a4->setDisabled(mVector[3].count == 0);
//    ui->a5->setDisabled(mVector[4].count == 0);
//    ui->a6->setDisabled(mVector[5].count == 0);

//    ui->b1->setDisabled(mVector[7].count == 0);
//    ui->b2->setDisabled(mVector[8].count == 0);
//    ui->b3->setDisabled(mVector[9].count == 0);
//    ui->b4->setDisabled(mVector[10].count == 0);
//    ui->b5->setDisabled(mVector[11].count == 0);
//    ui->b6->setDisabled(mVector[12].count == 0);

    ui->ak->setDisabled(true);
    ui->bk->setDisabled(true);
}

char
    MainWindow::_switchTurn(int pButtonId)
{
    if (mVector[pButtonId].player == 'a')
    {return 'b';}
    else
    {return 'a';}
}

void
    MainWindow::_setTurn(char player)
{
    for (int i=0; i<=mVector.length();++i)
    {
        if (mVector[i].player==player)
        {
            mVector[i].isDisabled = false;
        }else
        {mVector[i].isDisabled = true;}

        if (!mVector[i].count)
        {
            mVector[i].isDisabled = true;
        }
        else
        {
            mVector[i].isDisabled = false;
        }
    }
}

void
    MainWindow::_btn_processing(int aIDBtn)
{
    char aturn = 'a';
    int aSkip = 13,
        aKalah = 6;

    MainWindow::_setTurn(aturn);
    _update_btns();

    int tmp = mVector[aIDBtn].count;
    if (mVector[aIDBtn].player=='b')
    {
        aSkip = 6;
        aKalah  = 13;
    }
    mVector[aIDBtn].count = 0;
//    if(aIDBtn+1 <=  mVector.size())
//    {mVector[aIDBtn + 1].count += tmp;}
//    else
//       { mVector[0].count += tmp;};
    int i=0;
    while (tmp>0)
    {
        ++i;

        if ((aIDBtn+i)==aSkip)
        {
            ++i;
            continue;
        }
        if ((aIDBtn+i)==14)
        {
            i=-aIDBtn;
        }
        mVector[aIDBtn+i].count+=1;
        --tmp;
    }
    if(mVector[aIDBtn+i].player==mVector[aIDBtn].player)
    {
        if (mVector[aIDBtn+i].count==1 && mVector[12-(aIDBtn+i)].count>0)
        {
            int tmpCount = mVector[12-(aIDBtn+i)].count+1;
            mVector[12-(aIDBtn+i)].count=0;
            mVector[aIDBtn+i].count=0;
            mVector[aKalah].count+=tmpCount;
            aturn = MainWindow::_switchTurn(aIDBtn);

        }
    }else{
        aturn = MainWindow::_switchTurn(aIDBtn);
    }

    _update_btns();
}



void MainWindow::on_a1_clicked()
{
    _btn_processing(0);
}

void MainWindow::on_a2_clicked()
{
    _btn_processing(1);
}

void MainWindow::on_a3_clicked()
{
    _btn_processing(2);
}

void MainWindow::on_a4_clicked()
{
    _btn_processing(3);
}

void MainWindow::on_a5_clicked()
{
    _btn_processing(4);
}

void MainWindow::on_a6_clicked()
{
    _btn_processing(5);
}


void MainWindow::on_actionNew_game_with_human_triggered()
{
    _init_game();
    _update_btns();
}

void MainWindow::on_b1_clicked()
{
    _btn_processing(7);
}

void MainWindow::on_b2_clicked()
{
    _btn_processing(8);
}

void MainWindow::on_b3_clicked()
{
    _btn_processing(9);
}

void MainWindow::on_b4_clicked()
{
    _btn_processing(10);
}

void MainWindow::on_b5_clicked()
{
    _btn_processing(11);
}

void MainWindow::on_b6_clicked()
{
    _btn_processing(12);
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

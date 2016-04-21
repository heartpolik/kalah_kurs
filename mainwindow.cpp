#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_a1_clicked()
{
    ui->a1->setDisabled(true);
    ui->a1->setText("0");

}

void MainWindow::on_actionNew_game_with_human_triggered()
{
   // QPushButton->setText("6");
    //QPushButton.setEnabled(true);
    this->setDisabled(true);
}

void MainWindow::on_a2_clicked()
{

}

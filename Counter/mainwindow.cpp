#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int current_value = ui->label->text().toInt();
    ui->label->setNum(current_value+1);
    ui->statusbar->showMessage("button push");
}

void MainWindow::on_actionFile_triggered()
{
    exit(0);
}

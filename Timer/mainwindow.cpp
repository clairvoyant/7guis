#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.stop();

    connect(&timer, SIGNAL(timeout()), this, SLOT(timeoutcb()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timeoutcb()
{
    auto progressBar = ui->progressBar;
    auto slider      = ui->horizontalSlider;

    if (progressBar->value() < slider->value())
        progressBar->setValue(progressBar->value()+1);
}


void MainWindow::on_pushButton_clicked()
{
   ui->progressBar->setValue(0);
   ui->progressBar->setMaximum(ui->horizontalSlider->value());
   timer.start(1000);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->progressBar->setMaximum(position);
}

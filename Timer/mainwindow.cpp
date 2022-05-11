#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qtimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chrono = new QTimer(this);
    connect(chrono, SIGNAL(timeout()), this, SLOT(doTimerActivaton()));
    chrono->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doTimerActivaton()
{
   int n = ui->lcdNumber->intValue();
   ui->lcdNumber->display(n+1);
}

void MainWindow::on_actionExit_triggered()
{
   exit(0);
}

void MainWindow::on_pushButton_clicked()
{
   int n = ui->lcdNumber->intValue();
   ui->lcdNumber->display(n+1);

   chrono->blockSignals(!chrono->signalsBlocked());
}

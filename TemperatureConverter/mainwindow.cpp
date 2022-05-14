#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->lineEdit->setValidator( new QDoubleValidator(-100, 100,   2, ui->centralwidget) );
    ui->lineEdit_2->setValidator( new QDoubleValidator(-100, 100, 2, ui->centralwidget) );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_text(double d, QLineEdit* w)
{
   auto v = w->validator();
   w->blockSignals(true);
   w->setText(QString::number(d, 'f', 1 ));
   w->setValidator(v);
   w->blockSignals(false);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
   auto F = arg1.toDouble()*(9.0/5.0) + 32;

   update_text(F, ui->lineEdit_2);
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
   auto C = (arg1.toDouble()-32)*(5.0/9.0);
   update_text(C, ui->lineEdit);
}


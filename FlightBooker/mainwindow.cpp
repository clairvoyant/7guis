#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

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

bool
is_one_way_ticket(const QComboBox* box)
{
   bool result = false;

   if (box->currentIndex()==0) {
       result = true;
   }

   return result;
}

void MainWindow::check_combo_status()
{
    QDate now = QDate::currentDate();
    bool  enable_button = false;

    if (is_one_way_ticket(ui->comboBox)) {
        ui->dateEdit_2->setDisabled(true);
    } else {
        ui->dateEdit_2->setDisabled(false);
    }

    if (is_one_way_ticket(ui->comboBox)) {
        if (ui->dateEdit->date() > now)  {
            enable_button = true;
        }
    } else {
        if ( (ui->dateEdit->date() > now) and (ui->dateEdit_2->date() > now)) {
            enable_button = true;
        }
    }
    ui->pushButton->setEnabled(enable_button);
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    check_combo_status();
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    QString     msg = QString("You have booked a %1 on %2.").arg(ui->comboBox->currentText(), ui->dateEdit->text());
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
  check_combo_status();
}

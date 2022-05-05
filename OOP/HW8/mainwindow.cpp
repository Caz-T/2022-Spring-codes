#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->operand1->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::checklegality()
{
    QString str1, str2;
    const long long INF = 100000000;
    str1 = ui->operand1->toPlainText();
    str2 = ui->operand2->toPlainText();
    for (int i = 0; i < str1.size(); i++)
    {
        QChar ch = str1[i];
        if (ch < '0' or ch > '9')
        {
            if (ch != '-' or i != 0)
            {
                QMessageBox::StandardButtons ret = QMessageBox::warning(this, "Illegal operand",
                                                                        "Illegal characters detected in operand 1.\nCheck your input.\nDo you want to clear the input box?",
                                                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                if (ret == QMessageBox::Yes) ui->operand1->clear();
                ui->operand1->setFocus();
                return false;
            }
        }
    }
    for (int i = 0; i < str2.size(); i++)
    {
        QChar ch = str2[i];
        if (ch < '0' or ch > '9')
        {
            if (ch != '-' or i != 0)
            {
                QMessageBox::StandardButtons ret = QMessageBox::warning(this, "Illegal operand",
                                                                        "Illegal characters detected in operand 2.\nCheck your input.\nDo you want to clear the input box?",
                                                                        QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                if (ret == QMessageBox::Yes) ui->operand2->clear();
                ui->operand2->setFocus();
                return false;
            }
        }
    }
    long long oper1 = str1.toLongLong(), oper2 = str2.toLongLong();
    if (abs(oper1) > INF)
    {
        QMessageBox::StandardButtons ret = QMessageBox::warning(this, "Overflow",
                                                                "Operand 1 has too big an absolute value.\nCheck your input.\nDo you want to clear the input box?",
                                                                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) ui->operand1->clear();
        ui->operand1->setFocus();
        return false;
    }
    if (abs(oper2) > INF)
    {
        QMessageBox::StandardButtons ret = QMessageBox::warning(this, "Overflow",
                                                                "Operand 2 has too big an absolute value.\nCheck your input.\nDo you want to clear the input box?",
                                                                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) ui->operand2->clear();
        ui->operand2->setFocus();
        return false;
    }
    return true;
}


void MainWindow::showans(double num)
{
    QString str;
    if (num == (long long)num) str = str.setNum(num, 'g', 20);
    else str = str.setNum(num, 'g', 10);
    ui->answer->setPlainText(str);
}

void MainWindow::on_plusbutton_clicked() {if (checklegality()) showans(ui->operand1->toPlainText().toLongLong() + ui->operand2->toPlainText().toLongLong());}
void MainWindow::on_minusbutton_clicked() {if (checklegality()) showans(ui->operand1->toPlainText().toLongLong() - ui->operand2->toPlainText().toLongLong());}
void MainWindow::on_mulbutton_clicked() {if (checklegality()) showans(ui->operand1->toPlainText().toLongLong() * ui->operand2->toPlainText().toLongLong());}
void MainWindow::on_divbutton_clicked()
{
    if (checklegality())
    {
        if (ui->operand2->toPlainText().toLongLong() != 0) showans(ui->operand1->toPlainText().toLongLong() * 1.0 / ui->operand2->toPlainText().toLongLong());
        else
        {
            QMessageBox::StandardButtons ret = QMessageBox::warning(this, "Division by zero",
                                                                    "The divisor is zero.\nCheck your input.\nDo you want to clear the input box?",
                                                                    QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if (ret == QMessageBox::Yes) ui->operand2->clear();
            ui->operand2->setFocus();
        }
    }
}


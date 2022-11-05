#include "change.h"
#include "ui_change.h"

#include <QMessageBox>

Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
}

Change::~Change()
{
    delete ui;
}

void Change::showMessage1(QString pass, QString name)
{
    passer = pass;
    ui->lineEdit->setText(pass);
    ui->lineEdit_2->setText(name);
}

void Change::showMessage2( double chinese, double math, double english, double physics, double chemistry, double biology)
{
    ui->lineEdit_3->setText(QString::number(chinese));
    ui->lineEdit_5->setText(QString::number(math));
    ui->lineEdit_6->setText(QString::number(english));
    ui->lineEdit_4->setText(QString::number(physics));
    ui->lineEdit_7->setText(QString::number(chemistry));
    ui->lineEdit_8->setText(QString::number(biology));
}

void Change::on_pushButton_clicked()
{
    QString pass = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    double chinese = ui->lineEdit_3->text().toDouble();
    double math = ui->lineEdit_5->text().toDouble();
    double english = ui->lineEdit_6->text().toDouble();
    double physics = ui->lineEdit_4->text().toDouble();
    double chemistry = ui->lineEdit_7->text().toDouble();
    double biology = ui->lineEdit_8->text().toDouble();
    if(pass != passer)
    {
        QMessageBox::warning(this, tr("warn"), tr("考号不可修改"));
    }
    else
    {
//        query->exec(SET SQL_SAFE_UPDATES = 0);
        QString sql = QString("update Student set stuname ='"+name+"', chinese=%0, math=%1, english=%2, physics=%3, chemistry=%4, biology=%5 where pass='"+pass+"'").arg(chinese).arg(math).arg(english).arg(physics).arg(chemistry).arg(biology);
        query = new QSqlQuery;
        query->exec(sql);
    }
    emit sendsignal();
}

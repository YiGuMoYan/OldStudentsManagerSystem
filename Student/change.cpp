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

void Change::getanswer(QString st1, QString st2)
{
    pass = st1;
    answer = st2;
}

void Change::on_pushButton_3_clicked()
{
    QString st1 = ui->lineEdit->text();
    QString st2 = ui->lineEdit_2->text();
    QString st3 = ui->lineEdit_3->text();
    if(st1 == answer && st2 == st3)
    {
        qDebug() << st2 << pass;
        QString sql = "update Student set answer = '"+st2+"' where pass = '"+pass+"'";
        query = new QSqlQuery;
        query->exec(sql);
        QMessageBox::about(this, "infor", "修改成功");
        emit sendclose();
        delete this;
    }
    else
    {
        QMessageBox::about(this, "infor", "与原密码或再次输入密码不同");
    }
}

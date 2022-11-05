#include "insert.h"
#include "ui_insert.h"

Insert::Insert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Insert)
{
    ui->setupUi(this);
}

Insert::~Insert()
{
    delete ui;
}

void Insert::on_pushButton_clicked()
{
    QString pass = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    double chinese = ui->lineEdit_3->text().toDouble();
    double math = ui->lineEdit_5->text().toDouble();
    double english = ui->lineEdit_6->text().toDouble();
    double pyhsical = ui->lineEdit_4->text().toDouble();
    double chemistry = ui->lineEdit_7->text().toDouble();
    double biology = ui->lineEdit_8->text().toDouble();
    QString sql = QString("insert into Student value('"+pass+"', '"+pass+"', '"+name+"', default, %0, %1, %2, %3, %4, %5)").arg(chinese).arg(math).arg(english).arg(pyhsical).arg(chemistry).arg(biology);
    query = new QSqlQuery;
    query->exec(sql);
    emit sendsignal();
}

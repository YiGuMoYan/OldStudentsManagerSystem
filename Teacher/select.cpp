#include "select.h"
#include "ui_select.h"

Select::Select(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    QString pass = ui->lineEdit->text();
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student where pass like '%"+pass+"%'");
    ui->tableView->setModel(qmodel);

}

void Select::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_2->text();
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student where stuname like '%"+name+"%'");
    ui->tableView->setModel(qmodel);

}

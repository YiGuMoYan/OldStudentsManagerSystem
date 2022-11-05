#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->hide();
    Form * fm = new Form;
    fm->show();
    connect(fm,SIGNAL(sendsignal()),this,SLOT(reshow()));
    chan = new Change;
    connect(this,SIGNAL(sendmessage1(QString, QString)),chan,SLOT(showMessage1(QString, QString)));
    connect(this,SIGNAL(sendmessage2(double, double, double, double, double, double)),chan,SLOT(showMessage2(double, double, double, double, double, double)));
    connect(chan,SIGNAL(sendsignal()),this,SLOT(showTable()));
}

void Widget::reshow()
{
    this->show();
    qDebug() << "收到信号";
    query = new QSqlQuery();
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student");
    ui->tableView->setModel(qmodel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTable()
{
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student");
    ui->tableView->setModel(qmodel);
}


void Widget::on_pushButton_clicked()
{
    ins = new Insert;
    ins->show();
    connect(ins,SIGNAL(sendsignal()),this,SLOT(showTable()));
}

void Widget::on_pushButton_2_clicked()
{
    QString pass = currentIndexModel.siblingAtColumn(0).data().toString();
    QString sql = "delete from Student where pass='"+pass+"'";
    query->exec(sql);
    qmodel->setQuery("select pass as 账号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student");
    ui->tableView->setModel(qmodel);
}

void Widget::on_tableView_clicked(const QModelIndex &index)
{
    currentIndexModel = index;
    pass = index.siblingAtColumn(0).data().toString();
    name = index.siblingAtColumn(2).data().toString();
    chinese = index.siblingAtColumn(3).data().toDouble();
    math = index.siblingAtColumn(4).data().toDouble();
    english = index.siblingAtColumn(5).data().toDouble();
    physics = index.siblingAtColumn(6).data().toDouble();
    chemistry = index.siblingAtColumn(7).data().toDouble();
    biology = index.siblingAtColumn(8).data().toDouble();
    emit sendmessage1(pass, name);
    emit sendmessage2(chinese, math, english, physics, chemistry, biology);
    qDebug() << chinese << math << english << physics << chemistry << biology;
}

void Widget::on_pushButton_3_clicked()
{
    chan->show();
}

void Widget::on_pushButton_4_clicked()
{
    sel = new Select;
    sel->show();
    connect(sel,SIGNAL(sendsignal()),this,SLOT(showTable()));

}

void Widget::on_pushButton_5_clicked()
{
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student");
    ui->tableView->setModel(qmodel);
}

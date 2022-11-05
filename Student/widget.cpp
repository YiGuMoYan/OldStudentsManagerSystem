#include "widget.h"
#include "ui_widget.h"

#include <QSqlRecord>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->hide();
    Form * fm = new Form;
    fm->show();
    connect(fm,SIGNAL(sendsignal(QString, QString)),this,SLOT(reshow(QString, QString)));
}

void Widget::reshow(QString st, QString st2)
{
    this->show();
    pass = st;
    answer = st2;
    qDebug() << "收到信号";
    query = new QSqlQuery();
    query->exec("create table Teacher(pass varchar(20),answer varchar(20))");
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student where pass = '"+pass+"'");
    ui->tableView->setModel(qmodel);
    query->exec("select * from Student where pass = '"+pass+"'");
    QSqlRecord rec = query->record();
    int col = rec.indexOf("stuname");
    QString name;
    while (query->next())
    {
        name = query->value(col).toString();
    }
    ui->label->setText("欢迎，"+name+"同学");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student where pass = '"+pass+"'");
    ui->tableView->setModel(qmodel);
}

void Widget::on_pushButton_3_clicked()
{
    chan = new Change;
    chan->show();
    query->exec("select * from Student where pass = '"+pass+"'");
    QSqlRecord rec = query->record();
    int col1 = rec.indexOf("answer");
    while (query->next())
    {
        answer = query->value(col1).toString();
    }
    connect(this,SIGNAL(sendanswer(QString, QString)),chan,SLOT(getanswer(QString, QString)));
    connect(chan,SIGNAL(sendclose()),this,SLOT(close()));
    emit sendanswer(pass, answer);
}

void Widget::close()
{
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 考号, answer as 密码, stuname as 姓名, chinese as 语文, math as 数学, english as 英语, physics as 物理,chemistry as 化学, biology as 生物 from Student where pass = '"+pass+"'");
    ui->tableView->setModel(qmodel);
}


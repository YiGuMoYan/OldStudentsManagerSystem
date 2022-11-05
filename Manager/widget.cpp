#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QSqlRecord>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->hide();
    Form * fm = new Form;
    fm->show();
    connect(fm,SIGNAL(sendsignal()),this,SLOT(reshow()));
    connect(fm,SIGNAL(sendanswer(QString, QString)),this,SLOT(getanswer(QString, QString)));
}

void Widget::reshow()
{
    this->show();
    qDebug() << "收到信号";
    query = new QSqlQuery();
    query->exec("create table Teacher(pass varchar(20),answer varchar(20))");
    qmodel = new QSqlQueryModel();
    qmodel->setQuery("select pass as 账号, answer as 密码 from Teacher");
    ui->tableView->setModel(qmodel);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString passWord = ui->lineEdit->text();
    QString answerWord = ui->lineEdit_2->text();QSqlTableModel * model = new QSqlTableModel;
    model->setTable("Teacher");
    model->setFilter(tr("pass = '%0'").arg(passWord));
    model->select();
    if(model->rowCount()==0)
    {
        QString sql = "insert into Teacher value('"+passWord+"', '"+answerWord+"')";
        query->exec(sql);
        qmodel->setQuery("select pass as 账号, answer as 密码 from Teacher");
    }
    else
    {
        QMessageBox::warning(this, tr("warn"), tr("账户已经存在"));
    }

}

void Widget::on_pushButton_2_clicked()
{
    QString pass = currentIndexModel.siblingAtColumn(0).data().toString();
    QString sql = "delete from Teacher where pass='"+pass+"'";
    query->exec(sql);
    qmodel->setQuery("select pass as 账号, answer as 密码 from Teacher");
}

void Widget::on_tableView_clicked(const QModelIndex &index)
{
    QString userName = index.siblingAtColumn(0).data().toString();
    ui->lineEdit->setText(userName);
    QString passWord = index.siblingAtColumn(1).data().toString();
    ui->lineEdit_2->setText(passWord);
    currentIndexModel = index;
}



void Widget::on_pushButton_3_clicked()
{
    QString passWord = ui->lineEdit->text();
    QString answerWord = ui->lineEdit_2->text();
    QString sql = "update Teacher set answer='"+answerWord+"' where pass='"+passWord+"'";
    query->exec(sql);
    qmodel->setQuery("select pass as 账号, answer as 密码 from Teacher");
}

void Widget::on_pushButton_4_clicked()
{
    chan = new Change();
    chan->show();
    connect(this,SIGNAL(sendanswer(QString, QString)),chan,SLOT(getanswer(QString, QString)));
    query->exec("select * from Manager where pass = '"+pass+"'");
    QSqlRecord rec = query->record();
    int col1 = rec.indexOf("answer");
    while (query->next())
    {
        answer = query->value(col1).toString();
    }
    emit sendanswer(pass, answer);
}

void Widget::getanswer(QString st1, QString st2)
{
    pass = st1;
    answer = st2;
}


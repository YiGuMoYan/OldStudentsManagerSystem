#include "form.h"
#include "ui_form.h"

#include <QMessageBox>
#include <QSqlError>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}


void Form::on_pushButton_clicked()
{
    QString passWord = ui->lineEdit->text();
    QString answerWord = ui->lineEdit_2->text();
    QSqlTableModel * model = new QSqlTableModel;
    model->setTable("Manager");
    model->setFilter(tr("pass = '%0' and answer = '%1'").arg(passWord).arg(answerWord));
    model->select();
    if(model->rowCount()==1)
    {
        emit sendsignal();
        emit sendanswer(passWord, answerWord);
        this->close();
        delete this;
    }
    else
    {
        QMessageBox::warning(this, tr("warn"), tr("用户名或者密码不正确"));
    }
}


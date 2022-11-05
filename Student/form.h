#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QSqlTableModel>


#include <QDebug>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

signals:
    void sendsignal(QString, QString);

private:
    Ui::Form *ui;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QSqlTableModel * model;

};

#endif // FORM_H

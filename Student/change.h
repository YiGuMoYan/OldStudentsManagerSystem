#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QSqlTableModel>


#include <QDebug>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = nullptr);
    ~Change();

private slots:
    void getanswer(QString, QString);

    void on_pushButton_3_clicked();

signals:
    void sendclose();

private:
    Ui::Change *ui;
    QString answer;
    QString pass;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QSqlTableModel * model;
};

#endif // CHANGE_H

#ifndef SELECT_H
#define SELECT_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QSqlTableModel>


namespace Ui {
class Select;
}

class Select : public QWidget
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = nullptr);
    ~Select();

signals:
    void sendsignal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Select *ui;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QSqlTableModel * model;
};

#endif // SELECT_H

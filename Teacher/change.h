#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>

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

signals:
    void sendsignal();

private slots:
    void on_pushButton_clicked();

    void showMessage1(QString, QString);
    void showMessage2(double, double, double, double, double, double);

private:
    Ui::Change *ui;
    QSqlQuery * query;

    QString passer;
};

#endif // CHANGE_H

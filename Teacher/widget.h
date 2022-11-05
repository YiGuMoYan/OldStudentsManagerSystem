#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>

#include <QDebug>


#include "form.h"
#include "insert.h"
#include "change.h"
#include "select.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void reshow();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void showTable();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

signals:
    void sendmessage1(QString, QString);
    void sendmessage2(double, double, double, double, double, double);

private:
    Ui::Widget *ui;
    Form * fm;
    Insert * ins;
    Change * chan;
    Select * sel;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QModelIndex currentIndexModel;

    QString pass;
    QString name;
    double chinese;
    double math;
    double english;
    double physics;
    double chemistry;
    double biology;
};
#endif // WIDGET_H

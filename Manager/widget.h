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
#include "change.h"

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

    void getanswer(QString, QString);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void sendanswer(QString, QString);

private:
    Ui::Widget *ui;
    Form * fm;
    Change * chan;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QModelIndex currentIndexModel;
    QString pass;
    QString answer;
};
#endif // WIDGET_H

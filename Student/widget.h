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
    void reshow(QString, QString);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void close();

signals:
    void sendanswer(QString, QString);

private:
    QString pass;
    QString answer;

    Ui::Widget *ui;
    Form * fm;
    Change * chan;
    QSqlQuery * query;
    QSqlDatabase db;
    QSqlQueryModel * qmodel;
    QModelIndex currentIndexModel;
};
#endif // WIDGET_H

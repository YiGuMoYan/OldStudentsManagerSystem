#ifndef INSERT_H
#define INSERT_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>

#include <QDebug>
namespace Ui {
class Insert;
}

class Insert : public QWidget
{
    Q_OBJECT

public:
    explicit Insert(QWidget *parent = nullptr);
    ~Insert();

signals:
    void sendsignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Insert *ui;
    QSqlQuery * query;
};

#endif // INSERT_H

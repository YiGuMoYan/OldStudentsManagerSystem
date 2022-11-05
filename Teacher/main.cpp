#include "widget.h"


#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("23.224.53.118");
    db.setPort(3306);
    db.setDatabaseName("s3019956");
    db.setUserName("s3019956");
    db.setPassword("Hnhwyxwgx9");
    bool ok = db.open();
    if (ok){
        QMessageBox::about(NULL, "infor", "MySQL数据库连接成功");
    }
    else {
        QMessageBox::about(NULL, "infor", "MySQL数据库连接失败");
        qDebug()<<"error open database because";
        qDebug() << db.lastError();
    }
//    w.show();
    return a.exec();
}

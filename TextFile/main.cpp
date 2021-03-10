#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QDir>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir::setCurrent(a.applicationDirPath());//qt中解决相对路径问题
    QFile file("textFilel.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       qDebug() << file.errorString();
    }
    else
    {
//        while (!file.atEnd())//实现整个文件读取
//        {
//            char buffer[2048];
//            qint64 lineLen =file.readLine(buffer, sizeof(buffer));
//            if(lineLen != -1)
//            {
//                qDebug() << buffer;
//            }
//        }
//        qDebug() << QString::fromLocal8Bit("QTextStream读取一行");
//        QTextStream mytextstream(&file);
//        while (!mytextstream.atEnd())
//        {
//            QString str = mytextstream.readLine();//读取一行
//            qDebug() << str;
//        }
//        qDebug() <<QString::fromLocal8Bit("QTextStream读取整个文件");
//         QTextStream mytextstream2(&file);
//        while (!mytextstream2.atEnd())
//        {
//            QString strAll = mytextstream2.readAll();//读取整个文件
//            qDebug() << strAll;
//        }
        qDebug() << QString::fromLocal8Bit("QTextStream读取单个单词");
         QTextStream mytextstream3(&file);
        while (!mytextstream3.atEnd())
        {
            QString str2;
            mytextstream3 >> str2;  //读取单个单词，以空格隔开
            qDebug() << str2;
        }
    }
    return a.exec();
}

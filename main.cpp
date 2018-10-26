#include <QCoreApplication>
#include <QList>
#include <time.h>
#include <stdlib.h>
#include <QDebug>

struct TSortTest
{
    int n;
    QString qstrData;
};
Q_DECLARE_METATYPE(TSortTest)

void display(QList<TSortTest> &qlistSort)
{
    for(auto it : qlistSort)
    {
        qDebug() << "n: " << it.n << "qstrData: " << it.qstrData;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<TSortTest> qlistSort;
    srand((unsigned)time(NULL));
    for(int i = 0;i < 10; ++ i)
    {
        int a = rand() % 100;
        TSortTest t_sort;
        t_sort.n = a;
        t_sort.qstrData = QString("test data %1").arg(a);
        qlistSort.append(t_sort);
    }
    // 排序
    qSort(qlistSort.begin(),qlistSort.end(),[](TSortTest &t1, TSortTest &t2){
        return t1.n <= t2.n;
    });
    display(qlistSort);
    return a.exec();
}

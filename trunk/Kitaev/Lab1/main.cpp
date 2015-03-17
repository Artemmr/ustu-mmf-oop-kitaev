#include <QtCore/QCoreApplication>

#include <QString>

#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    std::vector<int> b;
    b.push_back(3);//[3]
    b.push_back(2);//[3 2]
    b.push_back(1);//[3 2 1]

    int c = b[1];//c = 2

    b[0] = 5;//[5 2 1]

    int size = b.size();//size = 3

    b.push_back(7);

    size = b.size();//size = 4

    return a.exec();
}

#include <iostream>

#include <qcoreapplication>
#include <QTextCodec>
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int lenght; // the first
    int width;
    int area;
    /*
    int lenght1; // second
    int width1;
    int area1;
    */
    lenght = 8;
    width = 6;

    area = lenght * width ;

    cout << "fasdfas\n";
    cout << lenght  ;
    cout << "\n" ;
    cout << area ;

    /*
    cout << "===============";
    cout << "\npls, enter lenght\n";
    cin >> lenght1;
    cout << "pls, enter width\n";
    cin >> width1;

    area1 = lenght1 * width1 ;

    cout << "Area is  " << area1 << "\n";
    */

    int count ;

    cout << "\n ";
    for (count = 0 ; count <= 100; count++) {
        cout << count << " " ;
    }

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp866"));

    qDebug()<<"lalala аыва" << " " << area;

    cout << "\n"
         << "Здесь должны быть крокозябрачки" // Как это победить?
         << "\n";


    return a.exec();
}

#include <iostream>
#include <cstdlib>
#include <cmath>

//#include <qcoreapplication>
//#include <QTextCodec>
//#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);

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


    int count ;

    cout << "\n ";

    for (count = 0 ; count <= 100; count++) {
        cout << count << " " ;
    }

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp866"));

    qDebug()<<"lalala аыва" << " " << area;

    cout << "\n"
         << "Здесь должны быть крокозябрачки" // WHY?
         << "\n";

    */
    int foot = 1;
    double metr;

    cout << "\n";
    for ( ; foot<=100; foot++){
        metr = foot/3.28;
        cout << foot << " ft is " << metr << " m\n" ;
        if (foot % 25 == 0)
            cout << "\n";
    }

    //next

    double result; // for more programm

    result = abs (-10);

    cout << result;
    cout << "\n";
    result = 0.0;
/*
 *
 * */
    int ft_earth;
    double ft_moon;
    cout << "\n";
    for ( ft_earth=1; ft_earth<=100; ft_earth++){

        ft_moon = ft_earth*0.17;

        cout << ft_earth << " weight on the Earth, - " << ft_moon << " moon\n";
        if (ft_earth % 25 == 0)
            cout << "\n";
    }
    ft_earth = 0;
    ft_moon = 0;

    double marsyear_exit;
    double earthyear;

    cout << "\npls, enter mars year or \"0\" for exit.\n";
    cin >> marsyear_exit;

    for (; marsyear_exit != 0;){

        earthyear = 12*marsyear_exit;

        cout << "On Mars: " << marsyear_exit << " on Earth: " << earthyear;

        cout << "\npls, enter mars year or \"0\" for exit.\n";
        cin >> marsyear_exit;
    }

    double number;

    int i;

    result = 0;
    cout << "\n";
    for (i=0; i<5; i++){
        cout << "Enter number: ";
        cin >> number;
        result=result + abs(number);
    }

    cout << "\n" << result/i << "<--- result\n";

    return 0;
}

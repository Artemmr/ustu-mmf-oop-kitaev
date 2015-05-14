#include <QtGui/QApplication>
#include "MainWindow.h"

#include "Common.h"

int main(int argc, char *argv[])
{
    int
            a1 = CONST1*2,
            b = CONST2*2,
            c = CONST3*2;

    int
            d = MIN(a1, b),
            e = MIN(a1-10, c)*2;

    int f = 1*MIN(a1==c, b==c);
    bool g = (((a1==c)<b)==c);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

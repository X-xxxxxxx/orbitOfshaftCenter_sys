#include "orbitOfshaftCenter_sys.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    orbitOfshaftCenter_sys w;
    w.show();
    //
    //stack_main* test = new stack_main();
    //test->show();


    return a.exec();
}

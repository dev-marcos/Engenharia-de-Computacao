#include "xadrezwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    XadrezWindow window;
    window.show();
    return app.exec();
}

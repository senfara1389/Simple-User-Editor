#include "gui.h"
#include <QtWidgets>
#include <QApplication>

int main(int arcg, char *argv[]){
    QApplication app(arcg, argv);
    QWidget window;
    GUI gui(window);
    return app.exec();
}

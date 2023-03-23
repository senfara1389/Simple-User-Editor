#include "gui.h"
#include <QtWidgets>
#include <QApplication>

void setStyle(QApplication* app);

int main(int arcg, char *argv[]){
    QApplication *app = new QApplication(arcg, argv);

    //Setting the QSS style sheet
    setStyle(app);

    QWidget window;
    GUI gui(&window);
    return app->exec();
    delete app;
}

//Function that sets the style for all the widgets we will be using
void setStyle(QApplication* app)
{
    QFile styleSheetFile("../style.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QString(styleSheetFile.readAll());
    app->setStyleSheet(styleSheet);
    styleSheetFile.close();
}

#ifndef GUI_H
#define GUI_H

#include <QtWidgets>
#include <QDebug>
#include "guiwidgetfunctions.h"
#include "guiinteractivityfunctions.h"

class GUI
{
private:
    QWidget* window;

public:
    GUI(QWidget *window);
    ~GUI();

    void makeGUI();
    void connectWidgets();
};

#endif // GUI_H

#ifndef GUI_H
#define GUI_H

#include <QtWidgets>
#include <QDebug>
#include "guiwidgetfunctions.h"
#include "guiinteractivityfunctions.h"

class GUI
{

public:
    GUI(QWidget& window);
    ~GUI();

    void makeGUI(QWidget& window);
};

#endif // GUI_H

#ifndef GUI_H
#define GUI_H

#include <QtWidgets>
#include <QDebug>
#include "guiwidgetfunctions.h"
#include "guiinteractivityfunctions.h"

class GUI : public QWidget
{
private:
    QWidget* window;
    void makeGUI();
    void connectWidgets();
public:
    void getUserData();
    GUI(QWidget *window);
    ~GUI();
signals:
    void updateModel();
};

#endif // GUI_H

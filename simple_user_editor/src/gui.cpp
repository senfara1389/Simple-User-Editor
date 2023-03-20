//Class made specifically for making the GUI for this particular application so main.cpp doesn't get too messy
#include "gui.h"

GUI::GUI(QWidget& window)
{
    makeGUI(window);
}

GUI::~GUI()
{

}

//Function that's responsible for creating all QWidgets and Layouts and displaying them in the window
void GUI::makeGUI(QWidget& window)
{
    QVector<QWidget*> allWidgets; //This vector contains  pointers to all widgets we can see in the gui and
    window.resize(600,600);      //we use it to connect their slots and signals in a dedicated function for that

    QVBoxLayout *usersLayout = new QVBoxLayout();
    usersLayout->setObjectName("usersLayout");

    allWidgets.append(makeUserListLabel(*usersLayout)); //This way we have all widgets in one Vector, but graphically they're
    allWidgets.append(makeSearchBar(*usersLayout));     //organized in their respective layouts due to the layout argument

    QHBoxLayout *controlButtonsLayout = new QHBoxLayout();
    controlButtonsLayout->setObjectName("controlButtonsLayout");

    ModelViewer *modelViewer = new ModelViewer(); //This model viewer is passed to the functions that make the brief
                                                  //users and detailed users list so their models have a shared space

    allWidgets.append(makeNewUserButton(*controlButtonsLayout));
    allWidgets.append(makeDeleteUserButton(*controlButtonsLayout));
    allWidgets.append(makeBriefUserTable(*usersLayout, modelViewer));

    usersLayout->addLayout(controlButtonsLayout);

    QVBoxLayout *userDetailsLayout = new QVBoxLayout();
    usersLayout->setObjectName("userDetailsLayout");

    allWidgets.append(makeUserDetailsLabel(*userDetailsLayout));
    allWidgets.append(makeUserImage(*userDetailsLayout));
    allWidgets.append(makeDetailedUserTable(*userDetailsLayout, modelViewer));

    QHBoxLayout *usersDetailsDivisionLayout = new QHBoxLayout();
    usersDetailsDivisionLayout->addLayout(usersLayout);
    usersDetailsDivisionLayout->addLayout(userDetailsLayout);

    connectBriefAndDetailedModels(allWidgets, "briefDetailsTableView", "detailedTableView");

    window.setLayout(usersDetailsDivisionLayout);
    window.show();
}





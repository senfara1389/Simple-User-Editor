//Class made specifically for making the GUI for this particular application so main.cpp doesn't get too messy
#include "gui.h"

GUI::GUI(QWidget* window)
{   
    this->window = window;
    makeGUI();
    connectWidgets();
}

GUI::~GUI()
{

}

//Function that's responsible for creating all QWidgets and Layouts and displaying them in the window
void GUI::makeGUI()
{ 
    this->window->resize(600,600);
    this->window->setObjectName("window");

    QVBoxLayout *usersLayout = new QVBoxLayout();
    usersLayout->setObjectName("usersLayout");

    makeUserListLabel(*usersLayout, this->window); //This way we have all widgets in one Vector, but graphically they're
    makeSearchBar(*usersLayout, this->window);     //organized in their respective layouts due to the layout argument

    QHBoxLayout *controlButtonsLayout = new QHBoxLayout();
    controlButtonsLayout->setObjectName("controlButtonsLayout");

    ModelViewer *modelViewer = new ModelViewer(); //This model viewer is passed to the functions that make the brief
                                                  //users and detailed users list so their models have a shared space

    makeNewUserButton(*controlButtonsLayout, this->window);


    makeDeleteUserButton(*controlButtonsLayout, this->window);
    makeBriefUserTable(*usersLayout, modelViewer, this->window);

    usersLayout->addLayout(controlButtonsLayout);

    QVBoxLayout *userDetailsLayout = new QVBoxLayout();
    usersLayout->setObjectName("userDetailsLayout");

    makeUserDetailsLabel(*userDetailsLayout, this->window);
    makeUserImage(*userDetailsLayout, this->window);
    makeDetailedUserTable(*userDetailsLayout, modelViewer, this->window);

    QHBoxLayout *usersDetailsDivisionLayout = new QHBoxLayout();
    usersDetailsDivisionLayout->addLayout(usersLayout);
    usersDetailsDivisionLayout->addLayout(userDetailsLayout);

    this->window->setLayout(usersDetailsDivisionLayout);
    this->window->show();
}

//Method that calls all the other functions that connect the signals and slots between related elements
void GUI::connectWidgets()
{
    connectBriefAndDetailedModels(this->window);
    saveSelectedRow(this->window);
    deleteSelectedUser(this->window);
    clearDetailsOnDialogButtonPress(this->window);
    connectNewButtonWithNewUserDialog(this->window);
}









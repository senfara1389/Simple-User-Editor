//This file takes care of all the functions needed to make the GUI elements and does their initial setup
#include "guiwidgetfunctions.h"

//This function is responsible for making the QTableView that contains the
//list of all users and adds the data into it through the model
void makeBriefUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent)
{
    UsersBriefTableView *briefDetailsTableView = new UsersBriefTableView(modelViewer, parent);
    briefDetailsTableView->setObjectName("briefDetailsTableView");
    briefDetailsTableView->verticalHeader()->hide();
    briefDetailsTableView->setSelectionBehavior(QAbstractItemView::SelectRows); //When any cell in row is selected, the whole row is selected
    briefDetailsTableView->setSelectionMode(QAbstractItemView::SingleSelection);//We can only select one row at a time
    briefDetailsTableView->setShowGrid(false);

    layout.addWidget(briefDetailsTableView);
}

//The function that makes the QTableView that contains the details about the selected user
void makeDetailedUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent)
{
    UserDetailsTableView *detailedTableView = new UserDetailsTableView(modelViewer, parent);
    detailedTableView->setObjectName("detailedTableView");
    detailedTableView->verticalHeader()->hide();
    detailedTableView->horizontalHeader()->hide();
    detailedTableView->setSelectionMode(QAbstractItemView::NoSelection);
    detailedTableView->setShowGrid(false);

    layout.addWidget(detailedTableView);
}

//Function that creates the User Image property
void makeUserImage(QVBoxLayout& layout, QWidget* parent, QString filepath)
{
    UpdatableImage *imageHolder = new UpdatableImage(parent);
    imageHolder->setObjectName("imageHolder");
    imageHolder->setAlignment(Qt::AlignCenter);
    imageHolder->resize(90, 150);
    imageHolder->updateImage(filepath);

    layout.addWidget(imageHolder);
}

//Function that adds the label that says "Users" in the top left corner
void makeUserListLabel(QVBoxLayout& layout, QWidget* parent)
{
    QLabel *usersLabel = new QLabel("Users", parent);
    usersLabel->setObjectName("usersLabel");

    layout.addWidget(usersLabel);
}

//Function that makes the search bar for the users
void makeSearchBar(QVBoxLayout& layout, QWidget* parent)
{
    QLineEdit *searchBar = new QLineEdit(parent);
    searchBar->setObjectName("searchBarTextEdit");

    layout.addWidget(searchBar);
}

//Function that makes the New User button
void makeNewUserButton(QHBoxLayout& layout, QWidget* parent)
{
    QPushButton *newUserButton = new QPushButton("New", parent);
    newUserButton->setObjectName("newUserPushButton");

    layout.addWidget(newUserButton);
}

//Function that makes the Delete User button
void makeDeleteUserButton(QHBoxLayout& layout, QWidget* parent)
{
    QPushButton *deleteUserButton = new QPushButton("Delete", parent);
    deleteUserButton->setObjectName("deleteUserPushButton");

    layout.addWidget(deleteUserButton);
}

//Function that adds the label that says "User Details" above user image
void makeUserDetailsLabel(QVBoxLayout& layout, QWidget* parent)
{
    QLabel *userDetailsLabel = new QLabel("User Details: ", parent);
    userDetailsLabel->setObjectName("userDetailsLabel");
    layout.addWidget(userDetailsLabel);
}

//Function that creates the label at the top of the page
void makeAddListLabel(QVBoxLayout &layout, QWidget* parent)
{
    QLabel *addUserLabel = new QLabel("New User: ", parent);
    addUserLabel->setObjectName("addUserLabel");

    layout.addWidget(addUserLabel);
}

//Function that makes all the Label that pertain to the inputs next to them
void makeUserParameterLabel(QHBoxLayout& layout, QString text, QString objectName, QWidget* parent)
{
    QLabel *parameterLabel = new QLabel(text, parent);
    parameterLabel->setObjectName(objectName);

    layout.addWidget(parameterLabel);
}

//Function that makes the text inputs where the user puts in the info about the new user
void makeUserTextInput(QHBoxLayout& layout, QString objectName, QWidget* parent)
{
    QLineEdit *parameterInput = new QLineEdit(parent);
    parameterInput->setObjectName(objectName);

    layout.addWidget(parameterInput);
}

//Function that makes the radio buttons for gender selection
void makeUserRadioButton(QHBoxLayout& layout, QButtonGroup& buttonGroup, QString text, QString objectName, QWidget* parent)
{
    QRadioButton *radioParameterInput = new QRadioButton(text, parent);
    radioParameterInput->setObjectName(objectName);

    layout.addWidget(radioParameterInput);
    buttonGroup.addButton(radioParameterInput);
}

//Function that creates the calendar widget for selecting date of birth
void makeCalendar(QHBoxLayout& layout, QString objectName, QWidget* parent)
{
    QCalendarWidget *dateInput = new QCalendarWidget(parent);
    dateInput->setObjectName(objectName);
    dateInput->setMaximumDate(QDate::currentDate());

    layout.addWidget(dateInput);
}

//Function that creates all the buttons in the dialog
void makeButton(QHBoxLayout &layout, QString text, QString objectName, QWidget* parent)
{
    QPushButton *dialogButton = new QPushButton(text, parent);
    dialogButton->setObjectName(objectName);

    layout.addWidget(dialogButton);
}


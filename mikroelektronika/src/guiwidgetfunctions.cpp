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


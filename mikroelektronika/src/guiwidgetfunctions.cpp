//This file takes care of all the functions needed to make the GUI elements and does their initial setup
#include "guiwidgetfunctions.h"



//This function is responsible for making the QTableView that contains the
//list of all users and adds the data into it through the model
QWidget* makeBriefUserTable(QVBoxLayout& layout, ModelViewer* modelViewer)
{
    UsersBriefTableView *briefDetailsTableView = new UsersBriefTableView(modelViewer);
    briefDetailsTableView->setObjectName("briefDetailsTableView");
    briefDetailsTableView->verticalHeader()->hide();
    briefDetailsTableView->setSelectionBehavior(QAbstractItemView::SelectRows); //When any cell in row is selected, the whole row is selected
    briefDetailsTableView->setSelectionMode(QAbstractItemView::SingleSelection);//We can only select one row at a time
    briefDetailsTableView->setShowGrid(false);

    layout.addWidget(briefDetailsTableView);
    return briefDetailsTableView;
}

//The function that makes the QTableView that contains the details about the selected user
QWidget* makeDetailedUserTable(QVBoxLayout& layout, ModelViewer* modelViewer)
{
    UserDetailsTableView *detailedTableView = new UserDetailsTableView(modelViewer);
    detailedTableView->setObjectName("detailedTableView");
    detailedTableView->verticalHeader()->hide();
    detailedTableView->horizontalHeader()->hide();
    detailedTableView->setSelectionMode(QAbstractItemView::NoSelection);
    detailedTableView->setShowGrid(false);

    layout.addWidget(detailedTableView);
    return detailedTableView;
}

//Function that creates the User Image property
QWidget* makeUserImage(QVBoxLayout& layout, QString filepath)
{
    UpdatableImage *imageHolder = new UpdatableImage();
    imageHolder->setObjectName("imageHolder");
    imageHolder->setAlignment(Qt::AlignCenter);
    imageHolder->resize(90, 150);
    imageHolder->updateImage(filepath);

    layout.addWidget(imageHolder);
    return imageHolder;
}

//Function that adds the label that says "Users" in the top left corner
QWidget* makeUserListLabel(QVBoxLayout& layout)
{
    QLabel *usersLabel = new QLabel(
                QApplication::translate("guilayouts", "Users: "));
    usersLabel->setObjectName("usersLabel");

    layout.addWidget(usersLabel);
    return usersLabel;
}

//Function that makes the search bar for the users
QWidget* makeSearchBar(QVBoxLayout& layout)
{
    QLineEdit *searchBar = new QLineEdit();
    searchBar->setObjectName("searchBarTextEdit");

    layout.addWidget(searchBar);
    return searchBar;
}

//Function that makes the New User button
QWidget* makeNewUserButton(QHBoxLayout& layout)
{
    QPushButton *newUserButton = new QPushButton(
                QApplication::translate("guilayouts", "New"));
    newUserButton->setObjectName("newUserPushButton");

    layout.addWidget(newUserButton);
    return newUserButton;
}

//Function that makes the Delete User button
QWidget* makeDeleteUserButton(QHBoxLayout& layout)
{
    QPushButton *deleteUserButton = new QPushButton(
                QApplication::translate("guilayouts", "Delete"));
    deleteUserButton->setObjectName("deleteUserPushButton");

    layout.addWidget(deleteUserButton);
    return deleteUserButton;
}

//Function that adds the label that says "User Details" above user image
QWidget* makeUserDetailsLabel(QVBoxLayout& layout)
{
    QLabel *userDetailsLabel = new QLabel(
                QApplication::translate("guilayouts", "User details: "));
    userDetailsLabel->setObjectName("userDetailsLabel");

    layout.addWidget(userDetailsLabel);
    return userDetailsLabel;
}

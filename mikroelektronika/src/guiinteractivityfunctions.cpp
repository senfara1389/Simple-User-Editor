//This file contains all the functions needed for slots and signals operations

#include "guiinteractivityfunctions.h"

//Function that sends the signal from Brief User TableView that the user has
//clicked on a row
//The Signal is picked up by Detailed User TableView slot and launches
//the function that picks up details about the wanted user from the JSON file
//and parses them into a DetailedUserModel, displaying it on the TableView
void connectBriefAndDetailedModels(QWidget* window)
{
    UsersBriefTableView *sender = window->findChild<UsersBriefTableView*>("briefDetailsTableView");
    UserDetailsTableView *reciever = window->findChild<UserDetailsTableView*>("detailedTableView");

    QObject::connect(sender, &UsersBriefTableView::clicked, reciever, &UserDetailsTableView::loadUserDetails);

    UpdatableImage *imageHolder = window->findChild<UpdatableImage*>("imageHolder");
    QObject::connect(reciever, &UserDetailsTableView::loadedImagePath, imageHolder, &UpdatableImage::updateImage);
}

//This function saves the index of a selected row in the UsersBriefTableView
//every time it is selected
void saveSelectedRow(QWidget* window)
{
    UsersBriefTableView *senderReciever = window->findChild<UsersBriefTableView*>("briefDetailsTableView");

    QObject::connect(senderReciever, &UsersBriefTableView::clicked, senderReciever, &UsersBriefTableView::loadSelectedUser);
}

//Function that sends the signal to the UsersBriefTableView each time the delete button
//is clicked, to delete the selected user
void deleteSelectedUser(QWidget* window)
{
    QPushButton *sender = window->findChild<QPushButton*>("deleteUserPushButton");
    UsersBriefTableView *reciever = window->findChild<UsersBriefTableView*>("briefDetailsTableView");

    QObject::connect(sender, &QPushButton::clicked, reciever, &UsersBriefTableView::deleteSelected);
}

//Function that sends the signal to the UserDetailedTableView when a user is deleted
//to clear up its model as well as reset the image
void clearDetailsOnDialogButtonPress(QWidget* window)
{
    UsersBriefTableView *sender = window->findChild<UsersBriefTableView*>("briefDetailsTableView");
    UserDetailsTableView *reciever = window->findChild<UserDetailsTableView*>("detailedTableView");

    QObject::connect(sender, &UsersBriefTableView::clearDetailedTableView, reciever, &UserDetailsTableView::clearModel);

    UpdatableImage *imageHolder = window->findChild<UpdatableImage*>("imageHolder");
    QObject::connect(sender, &UsersBriefTableView::clearDetailedTableView, imageHolder, &UpdatableImage::resetImageSlot);
}


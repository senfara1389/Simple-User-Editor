//This file contains all the functions needed for slots and signals operations

#include "guiinteractivityfunctions.h"

//Function that searches all Widgets by name and returns the pointer to the widget
//we provided the name for
QWidget* findWidget(QVector<QWidget*> allWidgets, QString widgetName)
{
    QVectorIterator<QWidget*> i(allWidgets);
    while(i.hasNext())
    {
        QWidget* currentWidget = i.next();
        if(currentWidget->objectName() == widgetName)
        {
            return currentWidget;
        }
    }
    return nullptr;
}

//Function that sends the signal from Brief User TableView that the user has
//clicked on a row
//The Signal is picked up by Detailed User TableView slot and launches
//the function that picks up details about the wanted user from the JSON file
//and parses them into a DetailedUserModel, displaying it on the TableView
void connectBriefAndDetailedModels(QVector<QWidget*> allWidgets, QString senderName, QString recieverName)
{
    QWidget* sender = findWidget(allWidgets, senderName);
    QWidget* reciever = findWidget(allWidgets, recieverName);

    QObject::connect(sender, SIGNAL(clicked(const QModelIndex &)), reciever, SLOT(loadUserDetails(const QModelIndex &)));

    QWidget* imageHolder = findWidget(allWidgets, "imageHolder");
    QObject::connect(reciever, SIGNAL(loadedImagePath(QString)), imageHolder, SLOT(updateImage(QString)));
}


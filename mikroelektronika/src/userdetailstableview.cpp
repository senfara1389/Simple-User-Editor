//This class inherits everything from the regular TableView class
//but adds the slot for the UsersBriefTableView class to send
//the signal when the selection changes, so this TableView updates its model
#include "userdetailstableview.h"

UserDetailsTableView::UserDetailsTableView(ModelViewer* modelViewer, QWidget* parent)
{
    this->setParent(parent);
    this->modelViewer = modelViewer;
}

UserDetailsTableView::~UserDetailsTableView()
{

}

//This method is the slot for the signal from UsersBriefTableView
//and it makes a new model object, fetches the data from JSON and updates the model
void UserDetailsTableView::loadUserDetails(const QModelIndex &index)
{
    QList<QString> briefUserModelRow = this->modelViewer->getBriefUserModelAtIndex(index);
    DetailedUserModel *dum = new DetailedUserModel(2); //We know there will be two columns so we put 2 as the colNumber
    dum->convertUserToModel(briefUserModelRow); //This method fetches the data from JSON and makes a model out of it

    QString imagePath = dum->getImagePath();
    emit loadedImagePath(imagePath); //We're emitting a signal that the imagepath is changed

    this->modelViewer->setDetailedUserModel(dum); //We update the shared model viewer with the latest data in the brief view
    this->setModel(dum);
    this->resizeRowsToContents();
    this->resizeColumnsToContents();
}

//This method clears the detailed user view after a user has been deleted
void UserDetailsTableView::clearModel()
{
    DetailedUserModel *dum = new DetailedUserModel(1);
    this->modelViewer->setDetailedUserModel(dum);
    this->setModel(dum);
}


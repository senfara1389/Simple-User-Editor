//This class is used as a mediator between BriefUserModel and DetailedUserModel
//It saves the current state of both models and allows them to access eachother's
//data when given permission by the other one (e.g. user clicked on the tableView
//that contains the briefUserModel, it sends a signal to DetailedUserModel's slot
//and DetailedUserModel recieved the index of the item the user clicked on. This
//gives permission to the DetailedUserModel to access the part of BriefUserModel's
//data - the one he has the index of)
//When an instance of this object is created, its pointer is passed to the models
//that should share space through the constructor of the models' widgets
//Also this class can be used by Brief and Detailed Table Views to access their
//own memebers, since they don't have any other way of accessing the model as it's
//created inside of a method but not saved in a member property
#include "modelviewer.h"

ModelViewer::ModelViewer()
{

}

ModelViewer::~ModelViewer()
{

}

//We call this method when we've updated the model that's showing in the
//UsersBriefTableView
void ModelViewer::setBriefUserModel(BriefUserModel* bum)
{
    this->bum = bum;
}

//We call this method when we've updated the model that's showing in the
//UserDetailsTableView
void ModelViewer::setDetailedUserModel(DetailedUserModel* dum)
{
    this->dum = dum;
}

//We call this method when we've acquired the right to access the element
//in UsersBriefTableView at given Index
QList<QString> ModelViewer::getBriefUserModelAtIndex(const QModelIndex &index) const
{
    return bum->getRow(index);
}

//We call this method when we've acquired the right to access the element
//in UserDetailsTableView at given Index
QList<QString> ModelViewer::getDetailedUserModelAtIndex(const QModelIndex &index) const
{
    return dum->getRow(index);
}

//Method that accepts the index, retrieves the data and passes it to the JSON
//handler inside the model
void ModelViewer::deleteRowAtIndex(const QModelIndex &index)
{
    QList<QString> parameters = bum->getRow(index);
    bum->deleteUser(parameters);
}


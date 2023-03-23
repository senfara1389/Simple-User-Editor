//This class inherits the regular QTableView class and adds the getModel() method
//which fetches the brief data about all users from JSON file and parses it into
//BriefUserModel and sets it as this TableView's model

#include "usersbrieftableview.h"

UsersBriefTableView::UsersBriefTableView(ModelViewer* modelViewer, QWidget *parent)
{
    this->setParent(parent);
    this->modelViewer = modelViewer;
    getModel();
}

//Method that fetches the model that displays the data in the table
void UsersBriefTableView::getModel()
{
    BriefUserModel *bum = new BriefUserModel(3); //3 is the passed argument becuase that's the number of columns in the table
    bum->convertUserListToModel(); //This method gets the data from the JSON file
    this->modelViewer->setBriefUserModel(bum); //We update the shared model viewer with the latest data in the brief view
    this->setModel(bum);
    this->resizeRowsToContents();
    this->resizeColumnsToContents();
}

//Slot methods that loads the index of a selected row when it's clicked
void UsersBriefTableView::loadSelectedUser(const QModelIndex& selectedRow)
{
    this->selectedRow = selectedRow;
}

//Slot method that's invoked when the user clicks the delete button
//It takes the selected row and deletes it using the JSON handler
void UsersBriefTableView::deleteSelected()
{
    QModelIndex index = this->selectedRow;
    int result = this->showDeleteDialog(); // We call the dialog which will ask us if we're sure we want to delete the specified user

    if(result == QMessageBox::Cancel)
    {
        return; //We will return and nothing will be deleted if the user selected cancel
    }

    if (index.isValid() == false)
    {
        qDebug() << "No item selected";
        return;
    }
    //The model object has a method for deleting the row at selected index
    //So we just pass the index we store in the object property selectedRow
    //through ModelViewer
    this->modelViewer->deleteRowAtIndex(index);
    this->getModel();
    this->selectedRow = QModelIndex(); // Clearing the selection
}

//Method that takes first and last name from currently selected user
QString UsersBriefTableView::getFullNameOfSelectedUser() const
{
    QModelIndex index = this->selectedRow;

    if (index.isValid() == false)
    {
        qDebug() << "No item selected";
        return "";
    }

    QList<QString> userData = this->modelViewer->getBriefUserModelAtIndex(index);

    QString fullName = userData.at(0) + " " + userData.at(1);
    return fullName;
}

//This method creates the dialog which, determined by what the user selects, will
//decide if the user will be deleted
int UsersBriefTableView::showDeleteDialog()
{
    QWidget *parent = this->parentWidget(); //We get the parent Widget and make it a parent widget of our Dialog so it's modal and will close if the main window is closed
    QMessageBox *deleteDialog = new QMessageBox(parent);
    deleteDialog->setObjectName("deleteDialog");
    deleteDialog->setWindowFlag(Qt::FramelessWindowHint);
    QString fullName = this->getFullNameOfSelectedUser();

    if(fullName == "")
    {
        return QMessageBox::Cancel; //We return this symbol because this means no name could be fetched, and the callback method won't proceed further if it recieves this symbol
    }

    deleteDialog->setText("Delete User \"" + fullName + "\"?");
    deleteDialog->setInformativeText("Are you sure you want to delete \"" + fullName + "\"?");
    deleteDialog->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int result = deleteDialog->exec();

    if(result == QMessageBox::Ok)
    {
       emit this->clearDetailedTableView();
    }

    delete deleteDialog; //since this dialog is a temporary object we need to delete it because it would make too many copies of itself in window's children
    return result;
}


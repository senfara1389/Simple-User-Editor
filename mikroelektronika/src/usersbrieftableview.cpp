//This class inherits the regular QTableView class and adds the getModel() method
//which fetches the brief data about all users from JSON file and parses it into
//BriefUserModel and sets it as this TableView's model

#include "usersbrieftableview.h"

UsersBriefTableView::UsersBriefTableView(ModelViewer* modelViewer)
{
    this->modelViewer = modelViewer;
    getModel();
}

void UsersBriefTableView::getModel()
{
    BriefUserModel *bum = new BriefUserModel(3); //3 is the passed argument becuase that's the number of columns in the table
    bum->convertUserListToModel(); //This method gets the data from the JSON file
    this->modelViewer->setBriefUserModel(bum); //We update the shared model viewer with the latest data in the brief view
    this->setModel(bum);
    this->resizeRowsToContents();
    this->resizeColumnsToContents();
}

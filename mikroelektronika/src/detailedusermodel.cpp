#include "detailedusermodel.h"

DetailedUserModel::DetailedUserModel(int colNumber, QObject *parent)
    :colNumber(colNumber), QAbstractItemModel{parent}
{

}

DetailedUserModel::~DetailedUserModel()
{

}

QVariant DetailedUserModel::headerData(int section, Qt::Orientation orientation, int role
                                    ) const
{
    if(role == Qt::DisplayRole) //Setting up the header names when data is displayed in Table View
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                default: return QAbstractItemModel::headerData(section, orientation, role);
            }
        }
    }

    return QAbstractItemModel::headerData(section, orientation, role);
}

QVariant DetailedUserModel::data(const QModelIndex& index, int role) const
{
    if(index.isValid() == false) return QVariant(); //This method defines the way the data is returned when called by
                                                    //a TableView adjacent widget when setting the model.
                                                    //We set up our index to be in a (row, column) format
                                                    //So the widget will send data as such and we will return
                                                    //Data cell by cell, first by fetching the row from the index
                                                    //and then seeing what column is needed and selecting it out of the
                                                    //bunch in the QList that makes up the row
    if(role == Qt::DisplayRole) //DisplayRole is a type of String that can be displayed on the GUI
    {
        if(items.count() == 0) return QVariant();

        const QList<QString>& item = items[index.row()];

        switch(index.column())
        {
            case 0: return item[0];
            case 1: return item[1];
        }
    }
    return QVariant();
}

QModelIndex DetailedUserModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    int rowMax = items.count();
    if(row < rowMax && row >=0 && column < colNumber && column >=0)
    {
        return createIndex(row, column); //This method is used to create the way our index works
    }                                    //Since this is a table, we have a row and a column
                                         //which are processed when calling the data method
    return QModelIndex();
}

QModelIndex DetailedUserModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

int DetailedUserModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent); //Avoids problems with the compiler by telling it that the parent parameter is not used in the function
    return colNumber; //We return only the number of used columns here
}

int DetailedUserModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return items.count(); //We return the whole vector because it represents the rows
}

QList<QString> DetailedUserModel::getRow(const QModelIndex& index, int role) const
{
    QList<QString> null;
    if(index.isValid() == false) return null; //Similar to the data method, except here we will return the
                                                    //whole row when calling the method, without looking into columns
    if(role == Qt::DisplayRole)
    {
        if(items.count() == 0) return null;

        const QList<QString>& row = items[index.row()];

        return row;
    }

    return null;
}

//We append data by adding a Qlist of Qstrings (data from each column that form a row)
void DetailedUserModel::append(const QList<QString>& data)
{
    items.append(data);
}

//We reset the model before displaying data and query for it again so we have the most up-to-date data displayed
void DetailedUserModel::reset()
{
    QAbstractItemModel::beginResetModel();
    QAbstractItemModel::endResetModel();
}

//This method gets a QVector of Users from the JSONHandler and iterates through it
//getting the data needed for the model, formatting it into a QList and then
//adding that QList to the QVector of QList that represents the data of this model
void DetailedUserModel::convertUserToModel(QList<QString>& identifiers)
{
    User selectedUser = this->json.getUserDetails(identifiers);

    QList<QString> userDetailsList;
    userDetailsList.append(selectedUser.getName());
    userDetailsList.append(selectedUser.getLastName());
    userDetailsList.append(selectedUser.getEmail());
    userDetailsList.append(selectedUser.getBirthdate().toString("yyyy.MM.dd"));
    userDetailsList.append(selectedUser.getGender());
    userDetailsList.append(selectedUser.getStreet());
    userDetailsList.append(selectedUser.getCity());
    userDetailsList.append(selectedUser.getPostalCode());
    userDetailsList.append(selectedUser.getPhoneNumber());

    QList<QString> userDetailsListHeaders;
    userDetailsListHeaders.append("First Name: ");
    userDetailsListHeaders.append("Last Name: ");
    userDetailsListHeaders.append("Email: ");
    userDetailsListHeaders.append("Date of Birth: ");
    userDetailsListHeaders.append("Gender: ");
    userDetailsListHeaders.append("Street: ");
    userDetailsListHeaders.append("City: ");
    userDetailsListHeaders.append("Postal code: ");
    userDetailsListHeaders.append("Phone number: ");
    //We made two lists of Strings, which contain the header name and the data in the same position of their respective list
    //We make a for loop that iterates as many times as there are members in our lists, we form a pair of header and value
    //with the help of an index (our iteration int in the for loop) and make a new QList that consists of only two members:
    //header and value. We append this list to our model.

    for (int i = 0; i < userDetailsList.count(); ++i)
    {
        QList<QString> headerValuePair;
        headerValuePair.append(userDetailsListHeaders.at(i));
        headerValuePair.append(userDetailsList.at(i));

        this->append(headerValuePair);
        this->reset();
    }
    this->imagePath = selectedUser.getImagePath();
}

//This method returns the path to the image that's inside the JSON file to the
//UserDetailsTableView
QString DetailedUserModel::getImagePath() const
{
    return this->imagePath;
}

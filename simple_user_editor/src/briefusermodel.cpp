//Class that collects the data that's displayed in the left Table View
//Since the Table View uses the Model-View component, this class is a descendant of QAbstractItemModel
//It collects data for First name, Last name and email address
//Since it inherits the QAbstractItemModel class, we have to override certain methods, which are redefined in the code below
#include "briefusermodel.h"

BriefUserModel::BriefUserModel(int colNumber, QObject *parent)
    :colNumber(colNumber), QAbstractItemModel{parent}
{

}

BriefUserModel::~BriefUserModel()
{

}

QVariant BriefUserModel::headerData(int section, Qt::Orientation orientation, int role
                                    ) const
{
    if(role == Qt::DisplayRole) //Setting up the header names when data is displayed in Table View
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0: return "First Name";
                case 1: return "Last Name";
                case 2: return "Email Address";
                default: return QAbstractItemModel::headerData(section, orientation, role);
            }
        }
    }

    return QAbstractItemModel::headerData(section, orientation, role);
}

QVariant BriefUserModel::data(const QModelIndex& index, int role) const
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
            case 2: return item[2];
        }
    }

    return QVariant();
}

QModelIndex BriefUserModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    int rowMax = items.count();
    if(row < rowMax && row >=0 && column < colNumber && column >=0)
    {
        return createIndex(row, column); //This method is used to create the possibilty to access our model's properties using indices
    }

    return QModelIndex();
}

QModelIndex BriefUserModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

int BriefUserModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent); //Avoids problems with the compiler by telling it that the parent parameter is not used in the function
    return colNumber; //We return only the number of used columns here
}

int BriefUserModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return items.count(); //We return the whole vector because it represents the rows
}

//A method that returns the whole row of the model instead of a cell
QList<QString> BriefUserModel::getRow(const QModelIndex& index, int role) const
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
void BriefUserModel::append(const QList<QString>& data)
{
    items.append(data);
}

//We reset the model before displaying data and query for it again so we have the most up-to-date data displayed
void BriefUserModel::reset()
{
    QAbstractItemModel::beginResetModel();
    QAbstractItemModel::endResetModel();
}

//This method gets a QVector of Users from the JSONHandler and iterates through it
//getting the data needed for the model, formatting it into a QList and then
//adding that QList to the QVector of QList that represents the data of this model
void BriefUserModel::convertUserListToModel()
{
    QVector<User> userList = this->json.getUsersBrief();
    QVectorIterator<User> it(userList);

    while(it.hasNext())
    {
        User currentUser = it.next();
        QString name = currentUser.getName();
        QString lastName = currentUser.getLastName();
        QString email = currentUser.getEmail();

        QList<QString> modelRow;
        modelRow.append(name);
        modelRow.append(lastName);
        modelRow.append(email);

        this->append(modelRow);
        this->reset();
    }
}

//This method accepts a list of strings by which it will find the object in
//the JSON file and will erase that object
void BriefUserModel::deleteUser(QList<QString> parameters)
{
    this->json.deleteJson(parameters);
}

#include "jsonhandler.h"

JsonHandler::JsonHandler()
{

}

JsonHandler::~JsonHandler()
{

}

//Function that takes the JSON file and converts it into a usable Qt JSON object
//We will further analyze and take the data we need from this object in getUsersBrief and getUsersDetailed methods
QJsonObject JsonHandler::readJson()
{
    QJsonDocument doc;
    QFile file(this->path);

    if(file.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        doc = QJsonDocument::fromJson(bytes, &jsonError);
        if( jsonError.error != QJsonParseError::NoError )
        {
            qDebug() << "fromJson failed: " << jsonError.errorString();
            return QJsonObject();
        }
        if(doc.isObject())
        {
            QJsonObject jsonObj = doc.object();
            return jsonObj;
        }
    }
    return QJsonObject();
}

void JsonHandler::writeJson(User user)
{

}

void JsonHandler::deleteJson(QList<QString> modelRow)
{

}

//Method that gets only the name, last name and email of users and parses it into a QVector of Users
//This method is called by the BriefUserModel method convertUserListToModel()
QVector<User> JsonHandler::getUsersBrief()
{
    QJsonObject jsonObj = this->readJson();
    QVector<User> userList;

    QJsonValue users = jsonObj.value("users");
    QJsonArray usersArray = users.toArray();
    foreach(const QJsonValue& jsonValue, usersArray)
    {

        QString name = jsonValue.toObject().value("name").toString();
        QString lastName = jsonValue.toObject().value("last_name").toString();
        QString email = jsonValue.toObject().value("email").toString();

        User newUser(name, lastName, email);
        userList.append(newUser);
    }
    return userList;
}

//Method that gets all selected user data and parses it into a User object
//This method is called by the DetailedUserModel method convertUserToModel()
//The QList passed by the model contains the name, last name and email of the user
//that will be used as parameters to find the user
User JsonHandler::getUserDetails(QList<QString> selectedRow)
{
    QString wantedName = selectedRow.at(0);
    QString wantedLastName = selectedRow.at(1);
    QString wantedEmail = selectedRow.at(2);

    QJsonObject jsonObj = this->readJson();

    QJsonValue users = jsonObj.value("users");
    QJsonArray usersArray = users.toArray();

    foreach(const QJsonValue& jsonValue, usersArray)
    {
        QString name = jsonValue.toObject().value("name").toString();
        QString lastName = jsonValue.toObject().value("last_name").toString();
        QString email = jsonValue.toObject().value("email").toString();
        if(name == wantedName && lastName == wantedLastName && email == wantedEmail)
        {
            QString gender = jsonValue.toObject().value("gender").toString();
            QString birthdateString = jsonValue.toObject().value("birthdate").toString();
            QDate birthdate = QDate::fromString(birthdateString, "yyyy-MM-dd");

            QJsonObject address = jsonValue.toObject().value("address").toObject();
            QString city = address.value("city").toString();
            QString postalCode = address.value("postal_code").toString();
            QString streetAddress = address.value("street_address").toString();

            QString phoneNumber = jsonValue.toObject().value("phone_number").toString();
            QString imagePath = jsonValue.toObject().value("image").toString();

            User wantedUser(name, lastName, email, birthdate, gender, streetAddress, city, postalCode, phoneNumber, imagePath);

            return wantedUser;
        }

    }

    return User();
}

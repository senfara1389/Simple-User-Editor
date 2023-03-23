#include "jsonhandler.h"

JsonHandler::JsonHandler()
{

}

JsonHandler::~JsonHandler()
{

}

//Method that takes the JSON file and converts it into a usable Qt JSON object
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

//Method that takes the newly created JSON object, converts it into a document and writes it into a file
void JsonHandler::writeJson(QJsonObject jsonObj)
{
    QJsonDocument newDoc(jsonObj);
    QFile file(this->path);

    if(file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(newDoc.toJson());
        file.close();
    }
    else
    {
        qDebug() << "Problem writing to file";
    }
}

//Method that gets the name, last name and email of the user that's supposed to be
//deleted, deletes it from the json object and updates the JSON document
void JsonHandler::deleteJson(QList<QString> modelRow)
{
    QString wantedName = modelRow.at(0);
    QString wantedLastName = modelRow.at(1);
    QString wantedEmail = modelRow.at(2);

    QJsonObject jsonObj = this->readJson();

    QJsonValue users = jsonObj.value("users");
    QJsonArray usersArray = users.toArray();
    qsizetype index = 0; //We make an index to capture the position of the element in the array
    foreach(const QJsonValue& jsonValue, usersArray)
    {
        QString name = jsonValue.toObject().value("name").toString();
        QString lastName = jsonValue.toObject().value("last_name").toString();
        QString email = jsonValue.toObject().value("email").toString();

        if(name == wantedName && lastName == wantedLastName && email == wantedEmail)
        {
            break; //We break when every parameter matches the criteria and this way the index is pointing to our element
        }
        index += 1;
    }

    usersArray.removeAt(index);
    QJsonValue arrayAsValue(usersArray); //In order to make a new JSON file, we need to make the new array an object

    QJsonObject newJson;
    newJson.insert("users", arrayAsValue); //The key for the array will be "users", just like it was before

    this->writeJson(newJson);
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

//Method that gets data about our new user and makes a JSON object
//out of it and puts it in the file
void JsonHandler::parseNewUser(User user)
{
    QString name = user.getName();
    QString lastName = user.getLastName();
    QString email = user.getEmail();
    QString gender = user.getGender();
    QDate birthDate = user.getBirthdate();
    QString birthDateString = birthDate.toString("yyyy-MM-dd");
    QString street = user.getStreet();
    QString city = user.getCity();
    QString postalCode = user.getPostalCode();
    QString phoneNumber = user.getPhoneNumber();
    QString imagePath = user.getImagePath();

    QJsonObject userObj;

    userObj.insert("name", name);
    userObj.insert("last_name", lastName);
    userObj.insert("email", email);
    userObj.insert("gender", gender);
    userObj.insert("birthdate", birthDateString);

    QJsonObject addressObj;

    addressObj.insert("street_address", street);
    addressObj.insert("city", city);
    addressObj.insert("postal_code", postalCode);
    userObj.insert("address", addressObj);

    userObj.insert("phone_number", phoneNumber);
    userObj.insert("image", imagePath);

    QJsonObject encapsulatedObj;
    encapsulatedObj.insert("user", userObj);

    addNewUser(encapsulatedObj);
}

//Method that adds the newly created JSON object to the document
//We take the existing document and transform it into an array
//and append our user to the end of the array
//and then write our new json array to the file
void JsonHandler::addNewUser(QJsonObject newUser)
{
    QJsonObject jsonObj = this->readJson();
    QJsonValue users = jsonObj.value("users");
    QJsonArray usersArray = users.toArray();

    QJsonValue user = newUser.value("user");

    usersArray.push_back(user);

    QJsonValue arrayAsValue(usersArray);

    QJsonObject newJson;
    newJson.insert("users", arrayAsValue);

    this->writeJson(newJson);
}

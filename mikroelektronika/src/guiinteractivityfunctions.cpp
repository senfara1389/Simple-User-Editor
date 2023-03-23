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

//Function that enables opening a New User Dialog when pressing the "New" button
void connectNewButtonWithNewUserDialog(QWidget* window)
{
    QPushButton *sender = window->findChild<QPushButton*>("newUserPushButton");

    //We use lambda functions so we can pass the dialog to our function so it can access the data the user entered
    QObject::connect(sender, &QPushButton::clicked, [window](){
        openAddUserDialog(window);
    });
}

//Function that makes the connections between the Dialog buttons and their functions
void connectDialogButton(QDialog* dialog)
{
    QPushButton *fileDialogButton = dialog->findChild<QPushButton*>("imagePathButton");
    QObject::connect(fileDialogButton, &QPushButton::clicked, [dialog](){       //We use lambda functions so we can pass the dialog pointer as a parameter so the function can access the other widgets
        openFileDialog(dialog);
    });

    QPushButton *cancelButton = dialog->findChild<QPushButton*>("cancelButton");
    QObject::connect(cancelButton, &QPushButton::clicked, dialog, &QDialog::reject);


    QPushButton *createButton = dialog->findChild<QPushButton*>("createButton");
    QObject::connect(createButton, &QPushButton::clicked, [dialog](){
        validateData(dialog);
    });
}

//Function that takes the entered data and checks if it's properly entered
void validateData(QDialog* dialog)
{
    QList<QString> userData = getUserData(dialog);
    QString name = userData.at(0);
    if(name == "")
    {
           warningMessage(dialog, "No name was entered");
           return;
    }
    QString lastName = userData.at(1);
    if(lastName == "")
    {
           warningMessage(dialog, "No last name was entered");
           return;
    }
    QString email = userData.at(2);
    if(email == "" || !(email.contains(QRegularExpression("^([a-zA-Z0-9_\\-\\.]+)@([a-zA-Z0-9_\\-\\.]+)\\.([a-zA-Z]{2,5})$"))))
    {
           warningMessage(dialog, "Invalid Email");
           return;
    }
    QString street = userData.at(3);
    if(street == "" || !(street.contains(QRegularExpression("\\w+\\s+\\d+"))))
    {
           warningMessage(dialog, "Invalid street address");
           return;
    }
    QString city = userData.at(4);
    if(city == "")
    {
           warningMessage(dialog, "No city was entered");
           return;
    }
    QString postalCode = userData.at(5);
    if(postalCode == "" || !(postalCode.contains(QRegularExpression("^\\d+$"))))
    {
           warningMessage(dialog, "Invalid Postal Code");
           return;
    }
    QString phoneNumber = userData.at(6);
    if(phoneNumber == "" || !(phoneNumber.contains(QRegularExpression("^\\d+$"))))
    {
           warningMessage(dialog, "Invalid Phone Number");
           return;
    }
    QString birthDate = userData.at(7);
    if(birthDate == "Invalid Date")
    {
           warningMessage(dialog, "Invalid Date");
           return;
    }
    QString gender = userData.at(9);
    if(gender == "")
    {
           warningMessage(dialog, "No gender was selected");
           return;
    }

    dialog->accept(); //If the function made it to here that means all data is valid and our dialog closes
}

//Function that disconnects the validation function and "Add User" button
//promising that the entered data is valid and connects the "Add User" button
//to the QDialog result "Accepted" so we can return to the main dialog and fetch the data
void disconnectButtonAndValidation(QDialog* dialog)
{
    QPushButton *createButton = dialog->findChild<QPushButton*>("createButton");
    QObject::disconnect(createButton, nullptr, nullptr, nullptr);

    QObject::connect(createButton, &QPushButton::clicked, dialog, &QDialog::accept);
}

//Function that retrieves all the user data from the inputs
QList<QString> getUserData(QDialog* dialog)
{
    QList<QString> userData;

    QString name = dialog->findChild<QLineEdit*>("nameInput")->text();
    userData.append(name);
    QString lastName = dialog->findChild<QLineEdit*>("lastNameInput")->text();
    userData.append(lastName);
    QString email = dialog->findChild<QLineEdit*>("emailInput")->text();
    userData.append(email);
    QString street = dialog->findChild<QLineEdit*>("streetInput")->text();
    userData.append(street);
    QString city = dialog->findChild<QLineEdit*>("cityInput")->text();
    userData.append(city);
    QString postalCode = dialog->findChild<QLineEdit*>("postalCodeInput")->text();
    userData.append(postalCode);
    QString phoneNumber = dialog->findChild<QLineEdit*>("phoneNumberInput")->text();
    userData.append(phoneNumber);

    QDate birthDate = dialog->findChild<QCalendarWidget*>("birthDateInput")->selectedDate();
    QString birthDateString = birthDate.toString("yyyy-MM-dd");
    userData.append(birthDateString);

    QString gender;
    int id = dialog->findChild<QButtonGroup*>("radioButtonGroup")->checkedId();

    QString imagePath = dialog->findChild<QLabel*>("imagePathText")->text();
    userData.append(imagePath);

    if(id == 1)
    {
        gender = "Male";
    }
    else if(id == 2)
    {
        gender = "Female";
    }
    else{
        gender="";
    }
    userData.append(gender);

    return userData;
}

//Function that creates a JSON parser and a new User object and passes the object to the parser
void addUser(QList<QString> userData)
{
    JsonHandler json;

    QDate date(QDate::fromString(userData.at(7), "yyyy-MM-dd")); //We need to convert the date string to a QDate because that's what the constructor accepts

    User newUser(userData.at(0), userData.at(1), userData.at(2), date, userData.at(9), userData.at(3), userData.at(4), userData.at(5), userData.at(6), userData.at(8));
    json.parseNewUser(newUser);
}

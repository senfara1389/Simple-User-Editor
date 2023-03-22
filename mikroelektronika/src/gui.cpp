//Class made specifically for making the GUI for this particular application so main.cpp doesn't get too messy
#include "gui.h"

GUI::GUI(QWidget* window)
{   
    this->window = window;
    makeGUI();
    connectWidgets();
}

GUI::~GUI()
{

}

//Function that's responsible for creating all QWidgets and Layouts and displaying them in the window
void GUI::makeGUI()
{ 
    this->window->resize(600,600);
    this->window->setObjectName("window");

    QVBoxLayout *usersLayout = new QVBoxLayout();
    usersLayout->setObjectName("usersLayout");

    makeUserListLabel(*usersLayout, this->window); //This way we have all widgets in one Vector, but graphically they're
    makeSearchBar(*usersLayout, this->window);     //organized in their respective layouts due to the layout argument

    QHBoxLayout *controlButtonsLayout = new QHBoxLayout();
    controlButtonsLayout->setObjectName("controlButtonsLayout");

    ModelViewer *modelViewer = new ModelViewer(); //This model viewer is passed to the functions that make the brief
                                                  //users and detailed users list so their models have a shared space

    makeNewUserButton(*controlButtonsLayout, this->window);
    QObject::connect(this->window->findChild<QPushButton*>("newUserPushButton"), &QPushButton::clicked, this, &GUI::openAddUserDialog);

    makeDeleteUserButton(*controlButtonsLayout, this->window);
    makeBriefUserTable(*usersLayout, modelViewer, this->window);

    usersLayout->addLayout(controlButtonsLayout);

    QVBoxLayout *userDetailsLayout = new QVBoxLayout();
    usersLayout->setObjectName("userDetailsLayout");

    makeUserDetailsLabel(*userDetailsLayout, this->window);
    makeUserImage(*userDetailsLayout, this->window);
    makeDetailedUserTable(*userDetailsLayout, modelViewer, this->window);

    QHBoxLayout *usersDetailsDivisionLayout = new QHBoxLayout();
    usersDetailsDivisionLayout->addLayout(usersLayout);
    usersDetailsDivisionLayout->addLayout(userDetailsLayout);

    this->window->setLayout(usersDetailsDivisionLayout);
    this->window->show();
}

//Method that calls all the other functions that connect the signals and slots between related elements
void GUI::connectWidgets()
{
    connectBriefAndDetailedModels(this->window);
    saveSelectedRow(this->window);
    deleteSelectedUser(this->window);
    clearDetailsOnDialogButtonPress(this->window);
}

void GUI::openAddUserDialog()
{
    QDialog *addUserDialog = new QDialog(this->window);
    addUserDialog->setObjectName("addUserDialog");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setObjectName("mainLayout");

    makeAddListLabel(*mainLayout, addUserDialog);

    QVBoxLayout *inputLayout = new QVBoxLayout();
    inputLayout->setObjectName("inputLayout");

    QHBoxLayout *nameInputLayout = new QHBoxLayout();
    nameInputLayout->setObjectName("nameInputLayout");
    makeUserParameterLabel(*nameInputLayout, "First Name: ", "nameInputLabel", addUserDialog);
    makeUserTextInput(*nameInputLayout, "nameInput", addUserDialog);
    inputLayout->addLayout(nameInputLayout);

    QHBoxLayout *lastNameInputLayout = new QHBoxLayout();
    lastNameInputLayout->setObjectName("lastNameInputLayout");
    makeUserParameterLabel(*lastNameInputLayout, "Last Name: ", "lastNameInputLabel", addUserDialog);
    makeUserTextInput(*lastNameInputLayout, "lastNameInput", addUserDialog);
    inputLayout->addLayout(lastNameInputLayout);

    QHBoxLayout *emailInputLayout = new QHBoxLayout();
    emailInputLayout->setObjectName("emailInputLayout");
    makeUserParameterLabel(*emailInputLayout, "Email: ", "emailInputLabel", addUserDialog);
    makeUserTextInput(*emailInputLayout, "emailInput", addUserDialog);
    inputLayout->addLayout(emailInputLayout);

    QHBoxLayout *genderInputLayout = new QHBoxLayout();
    genderInputLayout->setObjectName("genderInputLayout");
    makeUserParameterLabel(*genderInputLayout, "Gender: ", "genderInputLabel", addUserDialog);
    QButtonGroup *radioButtonGroup = new QButtonGroup(addUserDialog);
    radioButtonGroup->setObjectName("radioButtonGroup");
    makeUserRadioButton(*genderInputLayout, *radioButtonGroup, "Male", "radioButtonMale", addUserDialog);
    makeUserRadioButton(*genderInputLayout, *radioButtonGroup, "Female", "radioButtonFemale", addUserDialog);
    radioButtonGroup->addButton(addUserDialog->findChild<QRadioButton*>("radioButtonMale"), 1);
    radioButtonGroup->addButton(addUserDialog->findChild<QRadioButton*>("radioButtonFemale"), 2);
    inputLayout->addLayout(genderInputLayout);

    QHBoxLayout *birthdateInputLayout = new QHBoxLayout();
    birthdateInputLayout->setObjectName("bithdateInputLayout");
    makeUserParameterLabel(*birthdateInputLayout, "Date of Birth: ", "birthdateInputLabel", addUserDialog);
    makeCalendar(*birthdateInputLayout, "birthDateInput", addUserDialog);
    inputLayout->addLayout(birthdateInputLayout);

    QHBoxLayout *streetInputLayout = new QHBoxLayout();
    streetInputLayout->setObjectName("streetInputLayout");
    makeUserParameterLabel(*streetInputLayout, "Street: ", "streetInputLabel", addUserDialog);
    makeUserTextInput(*streetInputLayout, "streetInput", addUserDialog);
    inputLayout->addLayout(streetInputLayout);

    QHBoxLayout *cityInputLayout = new QHBoxLayout();
    cityInputLayout->setObjectName("cityInputLayout");
    makeUserParameterLabel(*cityInputLayout, "City: ", "cityInputLabel", addUserDialog);
    makeUserTextInput(*cityInputLayout, "cityInput", addUserDialog);
    inputLayout->addLayout(cityInputLayout);

    QHBoxLayout *postalCodeInputLayout = new QHBoxLayout();
    postalCodeInputLayout->setObjectName("postalCodeInputLayout");
    makeUserParameterLabel(*postalCodeInputLayout, "Postal Code: ", "postalCodeInputLabel", addUserDialog);
    makeUserTextInput(*postalCodeInputLayout, "postalCodeInput", addUserDialog);
    inputLayout->addLayout(postalCodeInputLayout);

    QHBoxLayout *phoneNumberInputLayout = new QHBoxLayout();
    phoneNumberInputLayout->setObjectName("phoneNumberInputLayout");
    makeUserParameterLabel(*phoneNumberInputLayout, "Phone Number: ", "phoneNumberInputLabel", addUserDialog);
    makeUserTextInput(*phoneNumberInputLayout, "phoneNumberInput", addUserDialog);
    inputLayout->addLayout(phoneNumberInputLayout);

    QHBoxLayout *imagePathInputLayout = new QHBoxLayout();
    imagePathInputLayout->setObjectName("imagePathInputLayout");
    makeUserParameterLabel(*imagePathInputLayout, "Image: ", "imagePathInputLabel", addUserDialog);
    makeUserParameterLabel(*imagePathInputLayout, "", "imagePathText", addUserDialog);
    makeButton(*imagePathInputLayout, "Add Image", "imagePathButton", addUserDialog);
    inputLayout->addLayout(imagePathInputLayout);

    //Connecting this button to the method that opens up a dialog for finding a picture
    QObject::connect(addUserDialog->findChild<QPushButton*>("imagePathButton"), &QPushButton::clicked, this, &GUI::openFileDialog);

    mainLayout->addLayout(inputLayout);

    QHBoxLayout *optionsLayout = new QHBoxLayout();
    optionsLayout->setObjectName("optionsLayout");
    makeButton(*optionsLayout, "Cancel", "cancelButton", addUserDialog);
    makeButton(*optionsLayout, "Create", "createButton", addUserDialog);

    //We need to connect these two buttons to the standard dialog behavior, having a scenario when we press cancel(closing the dialog) and when pressing create(making a new user)
    QObject::connect(addUserDialog->findChild<QPushButton*>("cancelButton"), &QPushButton::clicked, addUserDialog, &QDialog::reject);
    QObject::connect(addUserDialog->findChild<QPushButton*>("createButton"), &QPushButton::clicked, addUserDialog, &QDialog::accept);

    mainLayout->addLayout(optionsLayout);

    addUserDialog->setLayout(mainLayout);
    int result = addUserDialog->exec();

    if(result == QDialog::Rejected)
    {
        return;
    }
    else if(result == QDialog::Accepted)
    {
        this->getUserData();
        this->window->findChild<UsersBriefTableView*>("briefDetailsTableView")->getModel(); //Updating the model on the left table;
    }
}

//Method for opening a file browser dialog for finding a user picture when clicking on add image button
void GUI::openFileDialog()
{
    QString directory = "..\\images";
    QDialog *parent = this->window->findChild<QDialog*>("addUserDialog");
    QFileDialog *imageFinder = new QFileDialog(parent, "Add Image", directory);

    const QStringList filters({"Image files (*.png *.jpg *.bmp)"});
    imageFinder->setNameFilters(filters);
    imageFinder->setFileMode(QFileDialog::ExistingFile);

    int result = imageFinder->exec();

    if(result == QDialog::Accepted)
    {
        QString imagePath = imageFinder->selectedFiles().at(0);
        parent->findChild<QLabel*>("imagePathText")->setText(imagePath);
    }
}

//With this method, we fetch all the data the user has provided, make an new user which we will parse into a JSON object
void GUI::getUserData()
{
    QDialog *parent = this->window->findChild<QDialog*>("addUserDialog");

    QString name = parent->findChild<QLineEdit*>("nameInput")->text();
    if(name == "")
    {
           qDebug() << "Name slot is empty";
    }
    QString lastName = parent->findChild<QLineEdit*>("lastNameInput")->text();
    QString email = parent->findChild<QLineEdit*>("emailInput")->text();
    QString street = parent->findChild<QLineEdit*>("streetInput")->text();
    QString city = parent->findChild<QLineEdit*>("cityInput")->text();
    QString postalCode = parent->findChild<QLineEdit*>("postalCodeInput")->text();
    QString phoneNumber = parent->findChild<QLineEdit*>("phoneNumberInput")->text();

    QDate birthDate = parent->findChild<QCalendarWidget*>("birthDateInput")->selectedDate();
    QString birthDateString = birthDate.toString("yyyy-MM-dd");

    QString gender;
    int id = parent->findChild<QButtonGroup*>("radioButtonGroup")->checkedId();

    QString imagePath = parent->findChild<QLabel*>("imagePathText")->text();

    if(id == 1)
    {
        gender = "Male";
    }
    else if(id == 2)
    {
        gender = "Female";
    }
    else{
        qDebug() << "Nothing was selected";
        return;
    }

    User newUser(name, lastName, email, birthDate, gender, street, city, postalCode, phoneNumber, imagePath);
    JsonHandler json;
    json.parseNewUser(newUser);
}






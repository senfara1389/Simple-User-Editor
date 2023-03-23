//This file takes care of all the functions needed to make the GUI elements and does their initial setup
#include "guiwidgetfunctions.h"

//This function is responsible for making the QTableView that contains the
//list of all users and adds the data into it through the model
void makeBriefUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent)
{
    UsersBriefTableView *briefDetailsTableView = new UsersBriefTableView(modelViewer, parent);
    briefDetailsTableView->setObjectName("briefDetailsTableView");
    briefDetailsTableView->verticalHeader()->hide();
    briefDetailsTableView->setSelectionBehavior(QAbstractItemView::SelectRows); //When any cell in row is selected, the whole row is selected
    briefDetailsTableView->setSelectionMode(QAbstractItemView::SingleSelection);//We can only select one row at a time
    briefDetailsTableView->setShowGrid(false);

    layout.addWidget(briefDetailsTableView);
}

//The function that makes the QTableView that contains the details about the selected user
void makeDetailedUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent)
{
    UserDetailsTableView *detailedTableView = new UserDetailsTableView(modelViewer, parent);
    detailedTableView->setObjectName("detailedTableView");
    detailedTableView->verticalHeader()->hide();
    detailedTableView->horizontalHeader()->hide();
    detailedTableView->setSelectionMode(QAbstractItemView::NoSelection);
    detailedTableView->setShowGrid(false);

    layout.addWidget(detailedTableView);
}

//Function that creates the User Image property
void makeUserImage(QVBoxLayout& layout, QWidget* parent, QString filepath)
{
    UpdatableImage *imageHolder = new UpdatableImage(parent);
    imageHolder->setObjectName("imageHolder");
    imageHolder->setAlignment(Qt::AlignCenter);
    imageHolder->resize(90, 150);
    imageHolder->updateImage(filepath);

    layout.addWidget(imageHolder);
}

//Function that adds the label that says "Users" in the top left corner
void makeUserListLabel(QVBoxLayout& layout, QWidget* parent)
{
    QLabel *usersLabel = new QLabel("Users", parent);
    usersLabel->setObjectName("usersLabel");

    layout.addWidget(usersLabel);
}

//Function that makes the search bar for the users
void makeSearchBar(QVBoxLayout& layout, QWidget* parent)
{
    QLineEdit *searchBar = new QLineEdit(parent);
    searchBar->setObjectName("searchBarTextEdit");

    layout.addWidget(searchBar);
}

//Function that makes the New User button
void makeNewUserButton(QHBoxLayout& layout, QWidget* parent)
{
    QPushButton *newUserButton = new QPushButton("New", parent);
    newUserButton->setObjectName("newUserPushButton");

    layout.addWidget(newUserButton);
}

//Function that makes the Delete User button
void makeDeleteUserButton(QHBoxLayout& layout, QWidget* parent)
{
    QPushButton *deleteUserButton = new QPushButton("Delete", parent);
    deleteUserButton->setObjectName("deleteUserPushButton");

    layout.addWidget(deleteUserButton);
}

//Function that adds the label that says "User Details" above user image
void makeUserDetailsLabel(QVBoxLayout& layout, QWidget* parent)
{
    QLabel *userDetailsLabel = new QLabel("User Details: ", parent);
    userDetailsLabel->setObjectName("userDetailsLabel");
    layout.addWidget(userDetailsLabel);
}

//Function that creates the label at the top of the page
void makeAddListLabel(QVBoxLayout &layout, QWidget* parent)
{
    QLabel *addUserLabel = new QLabel("New User: ", parent);
    addUserLabel->setObjectName("addUserLabel");

    layout.addWidget(addUserLabel);
}

//Function that makes all the Label that pertain to the inputs next to them
void makeUserParameterLabel(QHBoxLayout& layout, QString text, QString objectName, QWidget* parent)
{
    QLabel *parameterLabel = new QLabel(text, parent);
    parameterLabel->setObjectName(objectName);

    layout.addWidget(parameterLabel);
}

//Function that makes the text inputs where the user puts in the info about the new user
void makeUserTextInput(QHBoxLayout& layout, QString objectName, QWidget* parent)
{
    QLineEdit *parameterInput = new QLineEdit(parent);
    parameterInput->setObjectName(objectName);

    layout.addWidget(parameterInput);
}

//Function that makes the radio buttons for gender selection
void makeUserRadioButton(QHBoxLayout& layout, QButtonGroup& buttonGroup, QString text, QString objectName, QWidget* parent)
{
    QRadioButton *radioParameterInput = new QRadioButton(text, parent);
    radioParameterInput->setObjectName(objectName);

    layout.addWidget(radioParameterInput);
    buttonGroup.addButton(radioParameterInput);
}

//Function that creates the calendar widget for selecting date of birth
void makeCalendar(QHBoxLayout& layout, QString objectName, QWidget* parent)
{
    QCalendarWidget *dateInput = new QCalendarWidget(parent);
    dateInput->setObjectName(objectName);
    dateInput->setMaximumDate(QDate::currentDate());

    layout.addWidget(dateInput);
}

//Function that creates all the buttons in the dialog
void makeButton(QHBoxLayout &layout, QString text, QString objectName, QWidget* parent)
{
    QPushButton *dialogButton = new QPushButton(text, parent);
    dialogButton->setObjectName(objectName);

    layout.addWidget(dialogButton);
}

//Function for opening a dialog for entry of new user data
void openAddUserDialog(QWidget* parent)
{
    QDialog *addUserDialog = new QDialog(parent);
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

    mainLayout->addLayout(inputLayout);

    QHBoxLayout *optionsLayout = new QHBoxLayout();
    optionsLayout->setObjectName("optionsLayout");
    makeButton(*optionsLayout, "Cancel", "cancelButton", addUserDialog);
    makeButton(*optionsLayout, "Create", "createButton", addUserDialog);

    mainLayout->addLayout(optionsLayout);
    addUserDialog->setLayout(mainLayout);

    connectDialogButton(addUserDialog);

    int result = addUserDialog->exec();

    if(result == QDialog::Rejected)
    {
        return;
    }
    else if(result == QDialog::Accepted)
    {
        QList<QString> userData = getUserData(addUserDialog);
        addUser(userData);
        parent->findChild<UsersBriefTableView*>("briefDetailsTableView")->getModel(); //Updating the model on the left table so it includes the new user
    }
    delete addUserDialog;
}

//Function for opening a file browser dialog for finding a user picture when clicking on add image button
void openFileDialog(QDialog* parent)
{
    QString directory = "..\\images";
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

//Function for displaying a MessageBox when Data is invalid
void warningMessage(QDialog* parent, QString message)
{
    QMessageBox *warningDialog = new QMessageBox(parent);
    warningDialog->setText("Invalid input");
    warningDialog->setInformativeText(message);
    warningDialog->setStandardButtons(QMessageBox::Ok);

    warningDialog->exec();
    delete warningDialog;
}


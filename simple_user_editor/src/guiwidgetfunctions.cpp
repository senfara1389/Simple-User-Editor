//This file takes care of all the functions needed to make the GUI elements and does their initial setup
#include "guiwidgetfunctions.h"

//This function is responsible for making the QTableView that contains the
//list of all users and adds the data into it through the model
void makeBriefUserTable(QLayout& layout, ModelViewer* modelViewer, QWidget* parent)
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
void makeDetailedUserTable(QLayout& layout, ModelViewer* modelViewer, QWidget* parent)
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
void makeUserImage(QLayout& layout, QWidget* parent, QString filepath)
{
    UpdatableImage *imageHolder = new UpdatableImage(parent);
    imageHolder->setObjectName("imageHolder");
    imageHolder->setAlignment(Qt::AlignCenter);
    imageHolder->resize(90, 150);
    imageHolder->updateImage(filepath);

    layout.addWidget(imageHolder);
}

//Function that makes the search bar for the users
void makeSearchBar(QLayout& layout, QWidget* parent)
{
    QLineEdit *searchBar = new QLineEdit(parent);
    searchBar->setObjectName("searchBarTextEdit");

    layout.addWidget(searchBar);
}

//Function that makes all the Label that pertain to the inputs next to them
void makeLabel(QLayout& layout, QString text, QString objectName, QWidget* parent)
{
    QLabel *label = new QLabel(text, parent);
    label->setObjectName(objectName);
    label->setWordWrap(true);

    layout.addWidget(label);
}

//Function that makes the text inputs where the user puts in the info about the new user
void makeUserTextInput(QLayout& layout, QString objectName, QWidget* parent)
{
    QLineEdit *parameterInput = new QLineEdit(parent);
    parameterInput->setObjectName(objectName);

    layout.addWidget(parameterInput);
}

//Function that makes the radio buttons for gender selection
void makeUserRadioButton(QLayout& layout, QButtonGroup& buttonGroup, QString text, QString objectName, QWidget* parent)
{
    QRadioButton *radioParameterInput = new QRadioButton(text, parent);
    radioParameterInput->setObjectName(objectName);

    layout.addWidget(radioParameterInput);
    buttonGroup.addButton(radioParameterInput);
}

//Function that creates the calendar widget for selecting date of birth
void makeCalendar(QLayout& layout, QString objectName, QWidget* parent)
{
    QCalendarWidget *dateInput = new QCalendarWidget(parent);
    dateInput->setObjectName(objectName);
    dateInput->setMaximumDate(QDate::currentDate());

    layout.addWidget(dateInput);
}

//Function that creates all the buttons in the dialog
void makeButton(QLayout &layout, QString text, QString objectName, QWidget* parent)
{
    QPushButton *button = new QPushButton(text, parent);
    button->setObjectName(objectName);

    layout.addWidget(button);
}

//Function for opening a dialog for entry of new user data
void openAddUserDialog(QWidget* parent)
{
    QDialog *addUserDialog = new QDialog(parent);
    addUserDialog->setObjectName("addUserDialog");
    addUserDialog->resize(250, 500);
    addUserDialog->setWindowFlag(Qt::FramelessWindowHint);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setObjectName("mainLayout");

    makeLabel(*mainLayout, "Add User: ", "addUserLabel", addUserDialog);

    QVBoxLayout *inputLayout = new QVBoxLayout();
    inputLayout->setObjectName("inputLayout");

    QHBoxLayout *nameInputLayout = new QHBoxLayout();
    nameInputLayout->setObjectName("nameInputLayout");
    makeLabel(*nameInputLayout, "First Name: ", "nameInputLabel", addUserDialog);
    makeUserTextInput(*nameInputLayout, "nameInput", addUserDialog);
    inputLayout->addLayout(nameInputLayout);

    QHBoxLayout *lastNameInputLayout = new QHBoxLayout();
    lastNameInputLayout->setObjectName("lastNameInputLayout");
    makeLabel(*lastNameInputLayout, "Last Name: ", "lastNameInputLabel", addUserDialog);
    makeUserTextInput(*lastNameInputLayout, "lastNameInput", addUserDialog);
    inputLayout->addLayout(lastNameInputLayout);

    QHBoxLayout *emailInputLayout = new QHBoxLayout();
    emailInputLayout->setObjectName("emailInputLayout");
    makeLabel(*emailInputLayout, "Email: ", "emailInputLabel", addUserDialog);
    makeUserTextInput(*emailInputLayout, "emailInput", addUserDialog);
    inputLayout->addLayout(emailInputLayout);

    QHBoxLayout *genderInputLayout = new QHBoxLayout();
    genderInputLayout->setObjectName("genderInputLayout");
    makeLabel(*genderInputLayout, "Gender: ", "genderInputLabel", addUserDialog);
    QButtonGroup *radioButtonGroup = new QButtonGroup(addUserDialog);
    radioButtonGroup->setObjectName("radioButtonGroup");
    makeUserRadioButton(*genderInputLayout, *radioButtonGroup, "Male", "radioButtonMale", addUserDialog);
    makeUserRadioButton(*genderInputLayout, *radioButtonGroup, "Female", "radioButtonFemale", addUserDialog);
    radioButtonGroup->addButton(addUserDialog->findChild<QRadioButton*>("radioButtonMale"), 1);
    radioButtonGroup->addButton(addUserDialog->findChild<QRadioButton*>("radioButtonFemale"), 2);
    inputLayout->addLayout(genderInputLayout);

    QHBoxLayout *birthdateInputLayout = new QHBoxLayout();
    birthdateInputLayout->setObjectName("bithdateInputLayout");
    makeLabel(*birthdateInputLayout, "Date of Birth: ", "birthdateInputLabel", addUserDialog);
    makeCalendar(*birthdateInputLayout, "birthDateInput", addUserDialog);
    inputLayout->addLayout(birthdateInputLayout);

    QHBoxLayout *streetInputLayout = new QHBoxLayout();
    streetInputLayout->setObjectName("streetInputLayout");
    makeLabel(*streetInputLayout, "Street: ", "streetInputLabel", addUserDialog);
    makeUserTextInput(*streetInputLayout, "streetInput", addUserDialog);
    inputLayout->addLayout(streetInputLayout);

    QHBoxLayout *cityInputLayout = new QHBoxLayout();
    cityInputLayout->setObjectName("cityInputLayout");
    makeLabel(*cityInputLayout, "City: ", "cityInputLabel", addUserDialog);
    makeUserTextInput(*cityInputLayout, "cityInput", addUserDialog);
    inputLayout->addLayout(cityInputLayout);

    QHBoxLayout *postalCodeInputLayout = new QHBoxLayout();
    postalCodeInputLayout->setObjectName("postalCodeInputLayout");
    makeLabel(*postalCodeInputLayout, "Postal Code: ", "postalCodeInputLabel", addUserDialog);
    makeUserTextInput(*postalCodeInputLayout, "postalCodeInput", addUserDialog);
    inputLayout->addLayout(postalCodeInputLayout);

    QHBoxLayout *phoneNumberInputLayout = new QHBoxLayout();
    phoneNumberInputLayout->setObjectName("phoneNumberInputLayout");
    makeLabel(*phoneNumberInputLayout, "Phone Number: ", "phoneNumberInputLabel", addUserDialog);
    makeUserTextInput(*phoneNumberInputLayout, "phoneNumberInput", addUserDialog);
    inputLayout->addLayout(phoneNumberInputLayout);

    QHBoxLayout *imagePathInputLayout = new QHBoxLayout();
    imagePathInputLayout->setObjectName("imagePathInputLayout");
    makeLabel(*imagePathInputLayout, "Image: ", "imagePathInputLabel", addUserDialog);
    makeLabel(*imagePathInputLayout, "", "imagePathText", addUserDialog);
    makeButton(*imagePathInputLayout, "Add Image", "imagePathButton", addUserDialog);
    inputLayout->addLayout(imagePathInputLayout);

    mainLayout->addLayout(inputLayout);

    QHBoxLayout *optionsLayout = new QHBoxLayout();
    optionsLayout->setObjectName("optionsLayout");
    makeButton(*optionsLayout, "Cancel", "cancelButton", addUserDialog);
    makeButton(*optionsLayout, "Create", "createButton", addUserDialog);

    mainLayout->addLayout(optionsLayout);
    addUserDialog->setLayout(mainLayout);

    //This function adds functionality to the buttons inside the dialog
    connectDialogButton(addUserDialog);

    int result = addUserDialog->exec();

    //If the user clicks "cancel" the window will close, if he clicks "create" the data inside the window will be validated and if it's ok, it will be added to the file
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
    QDir dir("..");
    QFileDialog *imageFinder = new QFileDialog(parent, "Add Image", "..\\images");

    const QStringList filters({"Image files (*.png *.jpg *.bmp)"});
    imageFinder->setNameFilters(filters);
    imageFinder->setFileMode(QFileDialog::ExistingFile);

    int result = imageFinder->exec();

    if(result == QDialog::Accepted)
    {
        QString imagePath = imageFinder->selectedFiles().at(0);
        QString relativeImagePath = "../" + dir.relativeFilePath(imagePath);
        parent->findChild<QLabel*>("imagePathText")->setText(relativeImagePath);
    }
    delete imageFinder;
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


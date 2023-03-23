#include "user.h"

User::User(const QString name, const QString lastName, const QString email,
           const QDate birthdate, const QString gender, const QString street, const QString city, const QString postalCode,
           const QString phoneNumber, const QString imagePath)
{
    this->name = name;
    this->lastName = lastName;
    this->email = email;
    this->birthdate = birthdate;
    this->gender = gender;
    this->street = street;
    this->city = city;
    this->postalCode = postalCode;
    this->phoneNumber = phoneNumber;
    this->imagePath = imagePath;
}

User::User(const QString name, const QString lastName, const QString email)
{
    this->name = name;
    this->lastName = lastName;
    this->email = email;
}

User::User()
{

}

User::~User()
{

}

QString User::getName() const
{
    return this->name;
}

QString User::getLastName() const
{
    return this->lastName;
}

QString User::getEmail() const
{
    return this->email;
}

QDate User::getBirthdate() const
{
    return this->birthdate;
}

QString User::getGender() const
{
    return this->gender;
}

QString User::getStreet() const
{
    return this->street;
}

QString User::getCity() const
{
    return this->city;
}

QString User::getPostalCode() const
{
    return this->postalCode;
}

QString User::getPhoneNumber() const
{
    return this->phoneNumber;
}

QString User::getImagePath() const
{
    return this->imagePath;
}


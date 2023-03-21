#ifndef USER_H
#define USER_H

#include<QObject>
#include<QDate>
#include <QFile>

class User
{
private:
    QString name;
    QString lastName;
    QString email;
    QDate birthdate;
    QString gender;
    QString street;
    QString city;
    QString postalCode;
    QString phoneNumber;
    QString imagePath;
public:
    User(const QString name, const QString lastName, const QString email,
         const QDate birthdate, const QString gender, const QString street, const QString city, const QString postalCode,
         const QString phoneNumber, QString imagePath);
    User(const QString name, const QString lastName, const QString email);
    User();
    ~User();

    QString getName() const;
    QString getLastName() const;
    QString getEmail() const;
    QDate getBirthdate() const;
    QString getGender() const;
    QString getStreet() const;
    QString getCity() const;
    QString getPostalCode() const;
    QString getPhoneNumber() const;
    QString getImagePath() const;
};

#endif // USER_H

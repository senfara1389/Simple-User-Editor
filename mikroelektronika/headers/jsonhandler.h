#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVectorIterator>
#include <QDebug>
#include "user.h"


class JsonHandler
{
private:
    std::filesystem::path const path = "..\\users.json";
public:
    JsonHandler();
    ~JsonHandler();
    QJsonObject readJson();
    void writeJson(QJsonObject jsonObj);
    void deleteJson(QList<QString> modelRow);
    QVector<User> getUsersBrief();
    User getUserDetails(QList<QString> selectedRow);
    void parseNewUser(User user);
    void addNewUser(QJsonObject newUser);
};

#endif // JSONHANDLER_H

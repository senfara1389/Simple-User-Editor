#ifndef GUIINTERACTIVITYFUNCTIONS_H
#define GUIINTERACTIVITYFUNCTIONS_H

#include <QtWidgets>
#include <QObject>
#include "guiwidgetfunctions.h"
#include "jsonhandler.h"
#include "user.h"

void connectBriefAndDetailedModels(QWidget* window);
void saveSelectedRow(QWidget* window);
void deleteSelectedUser(QWidget* window);
void clearDetailsOnDialogButtonPress(QWidget* window);
void connectNewButtonWithNewUserDialog(QWidget* window);
void connectDialogButton(QDialog* dialog);
void validateData(QDialog* dialog);
void disconnectButtonAndValidation(QDialog* dialog);
QList<QString> getUserData(QDialog* dialog);
void addUser(QList<QString> userData);

#endif // GUIINTERACTIVITYFUNCTIONS_H

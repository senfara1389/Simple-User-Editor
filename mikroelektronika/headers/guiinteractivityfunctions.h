#ifndef GUIINTERACTIVITYFUNCTIONS_H
#define GUIINTERACTIVITYFUNCTIONS_H

#include <QtWidgets>
#include <QObject>
#include "guiwidgetfunctions.h"

void connectBriefAndDetailedModels(QWidget* window);
void saveSelectedRow(QWidget* window);
void deleteSelectedUser(QWidget* window);
void clearDetailsOnDialogButtonPress(QWidget* window);

#endif // GUIINTERACTIVITYFUNCTIONS_H

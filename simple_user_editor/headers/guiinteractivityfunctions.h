#ifndef GUIINTERACTIVITYFUNCTIONS_H
#define GUIINTERACTIVITYFUNCTIONS_H

#include <QtWidgets>
#include <QObject>
#include "userdetailstableview.h"

QWidget* findWidget(QVector<QWidget*> allWidgets, QString widgetName);
void connectBriefAndDetailedModels(QVector<QWidget*> allWidgets, QString senderName, QString recieverName);

#endif // GUIINTERACTIVITYFUNCTIONS_H

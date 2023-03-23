#ifndef GUIWIDGETFUNCTIONS_H
#define GUIWIDGETFUNCTIONS_H

#include <QtWidgets>
#include "updatableimage.h"
#include "usersbrieftableview.h"
#include "userdetailstableview.h"
#include "guiinteractivityfunctions.h"

void makeBriefUserTable(QLayout& layout, ModelViewer* modelViewer, QWidget* parent);
void makeDetailedUserTable(QLayout& layout, ModelViewer* modelViewer, QWidget* parent);
void makeUserImage(QLayout& layout, QWidget *parent, QString filepath = "..\\images\\blank.jpg");
void makeSearchBar(QLayout& layout, QWidget* parent);
void makeLabel(QLayout& layout, QString text, QString objectName, QWidget* parent);
void makeUserTextInput(QLayout& layout, QString objectName, QWidget* parent);
void makeUserRadioButton(QLayout& layout, QButtonGroup& buttonGroup, QString text, QString objectName, QWidget* parent);
void makeCalendar(QLayout& layout, QString objectName, QWidget* parent);
void makeButton(QLayout& layout, QString text, QString objectName, QWidget* parent);
void openAddUserDialog(QWidget* parent);
void openFileDialog(QDialog *parent);
void warningMessage(QDialog* parent, QString message);

#endif // GUIWIDGETFUNCTIONS_H

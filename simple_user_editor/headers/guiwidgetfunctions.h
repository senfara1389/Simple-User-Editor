#ifndef GUIWIDGETFUNCTIONS_H
#define GUIWIDGETFUNCTIONS_H

#include <QtWidgets>
#include "updatableimage.h"
#include "usersbrieftableview.h"
#include "userdetailstableview.h"

QWidget* makeBriefUserTable(QVBoxLayout& layout, ModelViewer* modelViewer);
QWidget* makeDetailedUserTable(QVBoxLayout& layout, ModelViewer* modelViewer);
QWidget* makeUserImage(QVBoxLayout& layout, QString filepath = "..\\images\\blank.jpg");
QWidget* makeUserListLabel(QVBoxLayout& layout);
QWidget* makeSearchBar(QVBoxLayout& layout);
QWidget* makeNewUserButton(QHBoxLayout& layout);
QWidget* makeDeleteUserButton(QHBoxLayout& layout);
QWidget* makeUserDetailsLabel(QVBoxLayout& layout);

#endif // GUIWIDGETFUNCTIONS_H

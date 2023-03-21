#ifndef GUIWIDGETFUNCTIONS_H
#define GUIWIDGETFUNCTIONS_H

#include <QtWidgets>
#include "updatableimage.h"
#include "usersbrieftableview.h"
#include "userdetailstableview.h"
#include "guiinteractivityfunctions.h"

void makeBriefUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent);
void makeDetailedUserTable(QVBoxLayout& layout, ModelViewer* modelViewer, QWidget* parent);
void makeUserImage(QVBoxLayout& layout, QWidget *parent, QString filepath = "..\\images\\blank.jpg");
void makeUserListLabel(QVBoxLayout& layout, QWidget* parent);
void makeSearchBar(QVBoxLayout& layout, QWidget* parent);
void makeNewUserButton(QHBoxLayout& layout, QWidget* parent);
void makeDeleteUserButton(QHBoxLayout& layout, QWidget* parent);
void makeUserDetailsLabel(QVBoxLayout& layout, QWidget* parent);

#endif // GUIWIDGETFUNCTIONS_H

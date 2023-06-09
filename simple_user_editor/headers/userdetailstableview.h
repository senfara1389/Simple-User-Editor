#ifndef USERDETAILSTABLEVIEW_H
#define USERDETAILSTABLEVIEW_H

#include <QTableView>
#include <QObject>
#include <QAbstractButton>
#include <QMessageBox>
#include "detailedusermodel.h"
#include "modelviewer.h"

class UserDetailsTableView : public QTableView
{
    Q_OBJECT
private:
    ModelViewer *modelViewer;
public:
    UserDetailsTableView(ModelViewer* modelViewer, QWidget *parent);
    ~UserDetailsTableView();
public slots:
    void loadUserDetails(const QModelIndex &index);
    void clearModel();
signals:
    void loadedImagePath(QString imagePath); //This signal is emitted inside loadUserDetails when the object is done reading the JSON and gets a new image path
};                                           //We will pass this new path as an argument to the slot

#endif // USERDETAILSTABLEVIEW_H

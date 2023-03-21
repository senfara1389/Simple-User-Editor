#ifndef USERSBRIEFTABLEVIEW_H
#define USERSBRIEFTABLEVIEW_H

#include <QTableView>
#include <QObject>
#include <QMessageBox>
#include "briefusermodel.h"
#include "modelviewer.h"

class UsersBriefTableView : public QTableView
{
    Q_OBJECT
private:
    ModelViewer *modelViewer;
    QModelIndex selectedRow;
public:
    UsersBriefTableView(ModelViewer* modelViewer, QWidget* parent);
    void getModel();
    QString getFullNameOfSelectedUser() const;
    int showDeleteDialog();
public slots:
    void loadSelectedUser(const QModelIndex& selectedRow);
    void deleteSelected();
signals:
    void clearDetailedTableView();
};

#endif // USERSBRIEFTABLEVIEW_H

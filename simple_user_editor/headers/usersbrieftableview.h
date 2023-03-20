#ifndef USERSBRIEFTABLEVIEW_H
#define USERSBRIEFTABLEVIEW_H

#include <QTableView>
#include <QObject>
#include <briefusermodel.h>
#include "modelviewer.h"

class UsersBriefTableView : public QTableView
{
    Q_OBJECT
private:
    ModelViewer *modelViewer;
public:
    UsersBriefTableView(ModelViewer* modelViewer);
    void getModel();
};

#endif // USERSBRIEFTABLEVIEW_H

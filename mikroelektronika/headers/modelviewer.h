#ifndef MODELVIEWER_H
#define MODELVIEWER_H

#include <QObject>
#include "briefusermodel.h"
#include "detailedusermodel.h"

class ModelViewer
{
private:
    BriefUserModel *bum;
    DetailedUserModel *dum;
public:
    ModelViewer();
    ~ModelViewer();
    void setBriefUserModel(BriefUserModel* bum);
    void setDetailedUserModel(DetailedUserModel* dum);
    QList<QString> getBriefUserModelAtIndex(const QModelIndex &index) const;
    QList<QString> getDetailedUserModelAtIndex(const QModelIndex &index) const;
    void deleteRowAtIndex(const QModelIndex &index);
};

#endif // MODELVIEWER_H

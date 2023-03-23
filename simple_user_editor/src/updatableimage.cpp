//This class is made with the sole purpose of having a slot method that's going to
//be called every time a user selects a new person in the UsersBriefTableView
//thus raising a signal that the image is supposed to be changed

#include "updatableimage.h"

UpdatableImage::UpdatableImage(QWidget* parent)
{
    this->setParent(parent);
}

UpdatableImage::~UpdatableImage()
{

}

//This slot method puts a picture on the given filepath in the UpdatableImage widget
//It's called every time UserDetailsTableView fetches new data(which means user
//clicked on an item in UsersBriefTableView) and gets a path to the new image
//Which emits a signal between the UserDetailsTableView and the UpdatableImage
void UpdatableImage::updateImage(QString filepath)
{
    if(filepath == "") //If there is no data on the image path we put in the default image
    {
        filepath = "..\\images\\blank.jpg";
    }

    QPixmap *img = new QPixmap();
    if(img->load(filepath))
    {
        *img = img->scaled(this->size(), Qt::KeepAspectRatio);
        this->setPixmap(*img);
    }
    delete img;
}

//This method resets the image of the User back to the default image when the user is deleted
void UpdatableImage::resetImageSlot()
{
    QString filepath = "..\\images\\blank.jpg";
    QPixmap img;
    if(img.load(filepath))
    {

        img = img.scaled(this->size(), Qt::KeepAspectRatio);
        this->setPixmap(img);
    }
}

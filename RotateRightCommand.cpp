#include "RotateRightCommand.h"
RotateRightCommand::RotateRightCommand(Vector<Image>& data) : ImageCommand(data)
{
}

void RotateRightCommand::execute()
{

    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Image>(data);

    for (size_t imgIndex = 0; imgIndex < data.getSize(); imgIndex++)
    {


        Image* rotated = new Image(data[imgIndex].getWidth(), (data[imgIndex]).getHeight());
        int newHeight = (data[imgIndex]).getWidth();
        int newWidth = (data[imgIndex]).getHeight();

        // logic
        for (size_t i = 0; i < (data[imgIndex]).getHeight(); i++)
        {
            for (size_t j = 0; j < (data[imgIndex]).getWidth(); j++)
            {
                (*rotated).setPixel(j, newWidth - i - 1, (data[imgIndex]).getPixel(i, j).clone());
            }
        }

        (data[imgIndex]) = (*rotated);
        delete rotated;

    }

}


ImageCommand* RotateRightCommand::clone() const
{
    return new RotateRightCommand(*this);
}


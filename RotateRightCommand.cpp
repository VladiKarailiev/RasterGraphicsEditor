#include "RotateRightCommand.h"
RotateRightCommand::RotateRightCommand(Image& data) : ImageCommand(data)
{
}

void RotateRightCommand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Image(data);

    Image* rotated = new Image(data.getWidth(), data.getHeight());
    int newHeight = data.getWidth();
    int newWidth = data.getHeight();

    // logic
    for (size_t i = 0; i < data.getHeight(); i++)
    {
        for (size_t j = 0; j < data.getWidth(); j++)
        {
            (*rotated).setPixel(j, newWidth - i - 1, data.getPixel(i, j).clone());
        }
    }

    data = (*rotated);
    delete rotated;


}


ImageCommand* RotateRightCommand::clone() const
{
    return new RotateRightCommand(*this);
}


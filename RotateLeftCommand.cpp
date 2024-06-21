#include "RotateLeftCommand.h"
RotateLeftCommand::RotateLeftCommand(Image& data) : ImageCommand(data)
{
}

void RotateLeftCommand::execute()
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
            (*rotated).setPixel(newHeight - 1 - j, i, data.getPixel(i, j).clone());
        }
    }

    data = (*rotated);
    delete rotated;


}


ImageCommand* RotateLeftCommand::clone() const
{
    return new RotateLeftCommand(*this);
}


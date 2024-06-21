#include "GrayscaleCommand.h"
GrayscaleCommand::GrayscaleCommand(Image& data) : ImageCommand(data)
{
}

void GrayscaleCommand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Image(data);

    // logic
    for (size_t i = 0; i < data.getHeight(); i++)
    {
        for (size_t j = 0; j < data.getWidth(); j++)
        {
            Pixel* currPixel = (data.getPixel(i,j).clone());
            currPixel->grayscale();
            data.setPixel(i, j, currPixel);
        }
    }


}


ImageCommand* GrayscaleCommand::clone() const
{
    return new GrayscaleCommand(*this);
}


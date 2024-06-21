#include "MonochromeCommand.h"
MonochromeCommand::MonochromeCommand(Image& data) : ImageCommand(data)
{
}

void MonochromeCommand::execute()
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
            Pixel* currPixel = (data.getPixel(i, j).clone());
            currPixel->monochrome();
            data.setPixel(i, j, currPixel);
        }
    }


}


ImageCommand* MonochromeCommand::clone() const
{
    return new MonochromeCommand(*this);
}


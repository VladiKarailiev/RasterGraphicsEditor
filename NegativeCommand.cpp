#include "NegativeCommand.h"
NegativeCommand::NegativeCommand(Image& data) : ImageCommand(data)
{

}

void NegativeCommand::execute()
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
            currPixel->invert();
            data.setPixel(i, j, currPixel);
        }
    }


}


ImageCommand* NegativeCommand::clone() const
{
    return new NegativeCommand(*this);
}


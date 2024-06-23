#include "NegativeCommand.h"
NegativeCommand::NegativeCommand(Vector<Image>& data) : ImageCommand(data)
{

}

void NegativeCommand::print() const
{
    std::cout << "negative";
};
void NegativeCommand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Image>(data);

    // logic
    for (size_t imgIndex = 0; imgIndex < data.getSize(); imgIndex++)
    {
        for (size_t i = 0; i < data[imgIndex].getHeight(); i++)
        {
            for (size_t j = 0; j < data[imgIndex].getWidth(); j++)
            {
                Pixel* currPixel = (data[imgIndex].getPixel(i, j).clone());
                currPixel->invert();
                data[imgIndex].setPixel(i, j, currPixel);
            }
        }
    }



}


ImageCommand* NegativeCommand::clone() const
{
    return new NegativeCommand(*this);
}


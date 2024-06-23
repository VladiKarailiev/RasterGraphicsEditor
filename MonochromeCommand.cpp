#include "MonochromeCommand.h"
MonochromeCommand::MonochromeCommand(Vector<Image>& data) : ImageCommand(data)
{
}

void MonochromeCommand::print() const
{
    std::cout << "monochrome";
};

void MonochromeCommand::execute()
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
                currPixel->monochrome();
                data[imgIndex].setPixel(i, j, currPixel);
            }
        }
    }



}


ImageCommand* MonochromeCommand::clone() const
{
    return new MonochromeCommand(*this);
}


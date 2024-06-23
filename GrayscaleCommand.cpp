#include "GrayscaleCommand.h"
GrayscaleCommand::GrayscaleCommand(Vector<Image>& data) : ImageCommand(data)
{
}

void GrayscaleCommand::execute()
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
                currPixel->grayscale();
                data[imgIndex].setPixel(i, j, currPixel);
            }
        }
    }

}


void GrayscaleCommand::print() const
{
    std::cout << "grayscale";
};
ImageCommand* GrayscaleCommand::clone() const
{
    return new GrayscaleCommand(*this);
}


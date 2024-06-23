#include "RotateLeftCommand.h"
RotateLeftCommand::RotateLeftCommand(Vector<Image>& data) : ImageCommand(data)
{
}

void RotateLeftCommand::print() const
{
    std::cout << "rotate left";
};
void RotateLeftCommand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Image>(data);

    for (size_t imgIndex = 0; imgIndex < data.getSize(); imgIndex++)
    {


        Image* rotated = new Image(data[imgIndex].getWidth(), data[imgIndex].getHeight(),data[imgIndex].getPath());
        int newHeight = data[imgIndex].getWidth();
        int newWidth = data[imgIndex].getHeight();

        // logic
        for (size_t i = 0; i < data[imgIndex].getHeight(); i++)
        {
            for (size_t j = 0; j < data[imgIndex].getWidth(); j++)
            {
                (*rotated).setPixel(newHeight - 1 - j, i, data[imgIndex].getPixel(i, j).clone());
            }
        }

        data[imgIndex] = (*rotated);
        delete rotated;

    }


}


ImageCommand* RotateLeftCommand::clone() const
{
    return new RotateLeftCommand(*this);
}


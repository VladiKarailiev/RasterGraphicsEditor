#include <iostream>
#include "ImageFactory.h"
#include "ImageCommand.h"
#include "GrayscaleCommand.h"
#include "RotateCommandBase.h"
#include "RotateLeftCommand.h"
#include "CommandExecutor.h"
#include "RGB.h"

int main2() {
    try {
        Image* pbmImage = ImageFactory::createImage("letterj.pbm");
        //std::cout << "PBM Image:" << std::endl;
        //pbmImage->print();

        Image* pgmImage = ImageFactory::createImage("feep.pgm");
        //std::cout << "PGM Image (Grayscale):" << std::endl;
        //pgmImage->print();

        Image* ppmRgbImage = ImageFactory::createImage("test.ppm");
        std::cout << "PPM Image (RGB):" << std::endl;
        ppmRgbImage->print();
      
        std::cout << "==================\n";

        ImageCommand* cmd = new RotateLeftCommand(*ppmRgbImage);
        (*cmd).execute();

        ppmRgbImage->print();
        std::cout << "==================\n";

        (*cmd).undo();
        ppmRgbImage->print();



        delete pbmImage;
        delete pgmImage;
        delete ppmRgbImage;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
int main()
{

    Image* pbmImage = ImageFactory::createImage("letterj.pbm");

    CommandExecutor& ce = CommandExecutor::getInstance();
    ImageCommand* ic1 = new RotateLeftCommand(*pbmImage);
    ImageCommand* ic2 = new NegativeCommand(*pbmImage);
    
    Polymorphic_Ptr<ImageCommand> ptr = Factory::create(*pbmImage);
    ce.add(ptr.get());

    pbmImage->print();
    std::cout << '\n';

    ce.execute();
    pbmImage->print();
    std::cout << '\n';

    ce.undo();
    pbmImage->print();
    std::cout << '\n';

    delete pbmImage;
}

/*
trqq se poglednat za vs sluchai height i width da ne sa razmeneni
do tuk cheteneto ot fail e kinda ok

*/



/*
 ImageFactory::createImage(<path>) - vrushta Image* - chete DYNAMIC! obekt ot tip IMAGE

*/
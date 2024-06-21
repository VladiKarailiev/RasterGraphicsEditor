#include <iostream>
#include "ImageFactory.h"
#include "ImageCommand.h"
#include "GrayscaleCommand.h"
#include "RotateCommandBase.h"
#include "RotateLeftCommand.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "RGB.h"
#include "Polymorphic_Ptr.hpp"
#include "Session.h"

int main2() {
    try {
        Image pbmImage = ImageFactory::createImage("letterj.pbm");
        //std::cout << "PBM Image:" << std::endl;
        //pbmImage->print();

        Image pgmImage = ImageFactory::createImage("feep.pgm");
        //std::cout << "PGM Image (Grayscale):" << std::endl;
        //pgmImage->print();

        Image ppmRgbImage = ImageFactory::createImage("test.ppm");
        std::cout << "PPM Image (RGB):" << std::endl;
        ppmRgbImage.print();
      
        std::cout << "==================\n";

      //  ImageCommand* cmd = new RotateLeftCommand(*ppmRgbImage);
        //(*cmd).execute();

        ppmRgbImage.print();
        std::cout << "==================\n";

        //(*cmd).undo();
        ppmRgbImage.print();



    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
int main()
{
/*
    //Image* pbmImage = ;
    Vector<Image> v;

    Image pbm = ImageFactory::createImage("letterj.pbm");
    v.pushBack(pbm);
    CommandExecutor ce;
    ImageCommand* ic1 = new RotateRightCommand(v);
    
    pbm.print();

    ic1->execute();
    
    v[0].print();
    */
    Image test = ImageFactory::createImage("letterj.pbm");
    Session ses(test);
    test = ImageFactory::createImage("letterv.pbm");
    ses.addImage(test);
    ses.handleCommand();
    ses.images[0].print();
    ses.images[1].print();
    std::cout << "\n";
    ses.pending.execute();
    ses.images[0].print();
    ses.images[1].print();

    /*
    for (size_t i = 0; i < v.getSize(); i++)
    {
        v[i].print();
    }
    
    std::cout << '\n';

    ce.execute();
    
    for (size_t i = 0; i < v.getSize(); i++)
    {
        v[i].print();
    }

    std::cout << '\n';


    */
}

/*
trqq se poglednat za vs sluchai height i width da ne sa razmeneni
do tuk cheteneto ot fail e kinda ok

*/



/*
 ImageFactory::createImage(<path>) - vrushta Image* - chete DYNAMIC! obekt ot tip IMAGE
 Polymorphic_Ptr<ImageCommand> ptr = Factory::create(*pbmImage);
*/


/*
PRAQ VEKTOR OT STATICHNI OBEKTI KOETO E MALKO WEIRD????


*/
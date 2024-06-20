#include <iostream>
#include "ImageFactory.h"
#include "RGB.h"

int main() {
    try {
        Image* pbmImage = ImageFactory::createImage("letterj.pbm");
        std::cout << "PBM Image:" << std::endl;
        pbmImage->print();

        Image* pgmImage = ImageFactory::createImage("feep.pgm");
        std::cout << "PGM Image (Grayscale):" << std::endl;
        pgmImage->print();

        Image* ppmRgbImage = ImageFactory::createImage("test.ppm");
        std::cout << "PPM Image (RGB):" << std::endl;
        ppmRgbImage->print();
      
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


/*
trqq se poglednat za vs sluchai height i width da ne sa razmeneni
do tuk cheteneto ot fail e kinda ok

*/
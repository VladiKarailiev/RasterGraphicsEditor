#include <iostream>
#include "ImageFactory.h"
#include "RGB.h"

int main() {
    try {
        std::unique_ptr<Image<RGB>> pgmImage = ImageFactory::createPPM("test.ppm");
        std::cout << "PpM Image:" << std::endl;
        pgmImage->print();
      
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
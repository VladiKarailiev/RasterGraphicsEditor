#include <iostream>
#include "ImageFactory.h"
#include "RGB.h"

int main() {
    try {
        std::unique_ptr<ImageBase> pbmImage = ImageFactory::createImage<ImageBase>("letterj.pbm");
        std::cout << "PBM Image:" << std::endl;
        pbmImage->print();
      
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
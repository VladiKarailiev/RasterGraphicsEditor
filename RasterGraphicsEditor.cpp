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
#include "SessionManager.h"
#include "Runner.h"
int main()
{
    SessionManager::run();



    
   /* Image test = ImageFactory::createImage("letterj.pbm");
    Image test2 = ImageFactory::createImage("letterv.pbm");
    Session ses(test);
    ses.addImage(test2);

    SessionManager::addSession(ses);
    
    //ses.printInfo();
    SessionManager::getSession(0)->printInfo();
    SessionManager::run();*/
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

vektor ot sesii

*/
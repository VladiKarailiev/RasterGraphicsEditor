#pragma once
#include "Image.hpp"
#include "Vector.hpp"
#include "CommandExecutor.h"
class Session
{
public:
    Vector<Image> images;
    CommandExecutor pending;
    int id;
    static int nextId;
public:
    void addImage(Image);
    void handleCommand();

    int getId() const;
    
    Session(Image&);

};


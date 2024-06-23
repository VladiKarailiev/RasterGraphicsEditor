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
    void addImage(Image&);
    void addTransformation(const Polymorphic_Ptr<ImageCommand>& cmd);

    // Delete the copy constructor and copy assignment operator
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;

    // Implement move constructor and move assignment operator
    Session(Session&& other) noexcept;
    Session& operator=(Session&& other) noexcept;


    void undo();

    void printInfo() const;

    int getId() const;
    Image getImage(int id) const
    {
        return images[id];
    }


    Session(Image&);
    Session();

};


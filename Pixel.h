#pragma once
#include <iostream>

class Pixel {
public:
    virtual ~Pixel() = default;
    virtual void print() const = 0;
    virtual Pixel* clone() const = 0;
    virtual void print(std::ostream& os) const = 0; // Helper function for operator<<
    virtual void read(std::istream& is) = 0; // Helper function for operator>>
};


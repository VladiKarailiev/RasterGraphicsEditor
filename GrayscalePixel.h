#pragma once
#include "Pixel.h"

class GrayscalePixel :
    public Pixel
{
public:
    GrayscalePixel(int value = 0) : value(value) {}
    void print() const override {
        std::cout << value;
    }
    Pixel* clone() const override {
        return new GrayscalePixel(*this);
    }
    void print(std::ostream& os) const override {
        os << value;
    }
    void read(std::istream& is) override {
        is >> value;
    }


private:
    int value;
};


#pragma once
#include "Pixel.h"

class RGBPixel :
    public Pixel
{
public:
    RGBPixel(int red = 0, int green = 0, int blue = 0) : red(red), green(green), blue(blue) {}
    void print() const override {
        std::cout << "(" << red << "," << green << "," << blue << ")";
    }
    Pixel* clone() const override {
        return new RGBPixel(*this);
    }


    void print(std::ostream& os) const override {
        os << '(' << red << ' ' << green << ' ' << blue << ')';
    }
    void read(std::istream& is) override {
        is >> red >> green >> blue;
    }

private:
    int red, green, blue;

};

/// trqq se mahnat read i write!
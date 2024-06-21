#pragma once
#include "Pixel.h"

class BlackOrWhitePixel : public Pixel {
public:
    BlackOrWhitePixel(bool value = false) : value(value) {}
    void print() const override {
        std::cout << (value ? "1" : "0");
    }
    Pixel* clone() const override {
        return new BlackOrWhitePixel(*this);
    }

    void grayscale() override
    {

    }
    void monochrome() override
    {

    }
    void invert() override
    {
        value = !value;
    }/// magic numbers


    void print(std::ostream& os) const override {
        os << (value ? "1" : "0");
    }
    void read(std::istream& is) override {
        int temp;
        is >> temp;
        value = (temp == 1);
    }

private:
    bool value;
};

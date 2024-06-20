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



class BlackOrWhitePixel : public Pixel {
public:
    BlackOrWhitePixel(bool value = false) : value(value) {}
    void print() const override {
        std::cout << (value ? "1" : "0");
    }
    Pixel* clone() const override {
        return new BlackOrWhitePixel(*this);
    }
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




class GrayscalePixel : public Pixel {
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

class RGBPixel : public Pixel {
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

std::ostream& operator<<(std::ostream& os, const Pixel& obj) {
    obj.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Pixel& obj) {
    obj.read(is);
    return is;
}

/// TIQ OPERATORI SA CHOK BAD
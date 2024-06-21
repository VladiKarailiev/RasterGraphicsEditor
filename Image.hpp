#pragma once
#include <vector>
#include <memory>
#include "Pixel.h"
#include "Vector.hpp"
#include "Polymorphic_Ptr.hpp"

class Image {
public:
    Image(int height, int width) : width(width), height(height) {
        for (size_t i = 0; i < height; i++)
        {
            pixels.pushBack(Vector<Polymorphic_Ptr<Pixel>>());
            for (size_t j = 0; j < width; j++)
            {
                pixels[i].pushBack(Polymorphic_Ptr<Pixel>());
            }
        }
    }

    void setPixel(int x, int y, const Pixel* pixel) {
        if (x >= height || y >= width) {
            throw std::out_of_range("Pixel coordinates out of range");
        }
        pixels[x][y] = pixel->clone();


    }

    const Pixel& getPixel(int x, int y) const {
        if (x >= height || y >= width) {
            throw std::out_of_range("Pixel coordinates out of range");
        }
        return *pixels[x][y];
    }

    void print() const {
        for (int i = 0; i < pixels.getSize(); i++) {
            for (int j = 0; j < pixels[i].getSize(); j++) {
                    getPixel(i,j).print(std::cout);

            }
            std::cout << std::endl;
        }
    }

    int getWidth() const
    {
        return width;
    }
    int getHeight() const
    {
        return height;
    }

private:
    int width, height;
    Vector<Vector<Polymorphic_Ptr<Pixel>>> pixels;
};


// tva ne e hpp!
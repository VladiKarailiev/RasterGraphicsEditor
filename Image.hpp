#pragma once
#include <vector>
#include <fstream>
#include "Pixel.h"
#include "MyString.h"
#include "Vector.hpp"
#include "Polymorphic_Ptr.hpp"

class Image {
public:
    Image() = default;
    Image(MyString path) {
        this->path = path;
    }
    Image(int height, int width, MyString path) : width(width), height(height) {
        this->path = path;
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

    MyString getPath() const
    {
        return path;
    }

    void save()
    {
        std::ofstream ofs(path.c_str());
        if (!ofs.is_open()) return;
        ofs << height << ' ' << width << '\n';
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                getPixel(i, j).print(ofs);
                ofs << ' ';
            }
            ofs << '\n';
        }
    }
    void saveAs(MyString newPath)
    {
        path = newPath;
        save();
    }

private:
    int width = 0, height = 0;
    Vector<Vector<Polymorphic_Ptr<Pixel>>> pixels;
    MyString path = "";
};

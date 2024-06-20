#pragma once
#include <vector>
#include <iostream>
#include "RGB.h"
#include "ImageBase.h"

template <typename T>
class Image : public ImageBase
{
public:
    Image(int height, int width) : width(width), height(height), pixels(height, std::vector<T>(width)) {}

    void setPixel(int x, int y, T value) {
        if (x< 0 || x >= height || y<0 || y >= width) {
            throw std::out_of_range("Pixel coordinates out of range");
        }
        pixels[x][y] = value;
    }

    T getPixel(int x, int y) const {
        if (x < 0 || x >= height || y < 0 || y >= width) {
            throw std::out_of_range("Pixel coordinates out of range");
        }
        return pixels[x][y];
    }

    void print() const {
        for (const auto& row : pixels) {
            for (const auto& pixel : row) {
                std::cout << pixel << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Image() = default;

private:
    int width, height;
    std::vector<std::vector<T>> pixels;
};

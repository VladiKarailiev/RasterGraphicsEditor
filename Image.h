#pragma once
#include <vector>

template <typename T>
class Image
{
    void setPixel(int x, int y, T value) {
        /// check for width height and throw exception
        pixels[x][y] = value;
    }

    T getPixel(int x, int y) const {
        /// check for width height and throw exception
        return pixels[x][y];
    }

    void print() const {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                std::count << pixels[i * width + j] << " ";
            }
            std::count << "\n";
        }

    }

    virtual ~Image() = default;

private:
	int width, height;
	std::vector<std::vector<T>> pixels; /// da se smeni s moi vektor
	
};


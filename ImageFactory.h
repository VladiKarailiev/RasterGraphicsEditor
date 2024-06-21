#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Image.hpp"
#include "BlackOrWhitePixel.h"
#include "GrayscalePixel.h"
#include "RGBPixel.h"

class ImageFactory {
public:
    static Image createPBM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height;
        file >> height >> width;
        Image image(height,width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                BlackOrWhitePixel value;
                Pixel* ptr = &value;
                ptr->read(file);
                image.setPixel(i, j, ptr);
            }
        }
        return image;
    }
    
    static Image createPGM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height, maxValue;
        file >> height >> width >> maxValue;
        Image image(height,width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                GrayscalePixel value;
                Pixel* ptr = &value;
                ptr->read(file);
                image.setPixel(i, j, ptr);
            }
        }

        return image;
    }

    static Image createPPM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height, maxValue;
        file >> height >> width >> maxValue;
        Image image(height,width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                RGBPixel value;
                Pixel* ptr = &value;
                ptr->read(file);
                image.setPixel(i, j, ptr);
            }
        }
        return image;
    }

    static Image createImage(const std::string& filePath) {
        std::string format = filePath.substr(filePath.size() - 3, 3);
        if (format == "pbm") {
            return createPBM(filePath);
        }
        else if (format == "pgm") {
            return createPGM(filePath);
        }
        else if (format == "ppm") {

            return createPPM(filePath);
        }
        else {
            throw std::runtime_error("Unsupported file format: " + filePath);
        }
    }
    
};

#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include "Image.hpp"

class ImageFactory {
public:
    static std::unique_ptr<Image<bool>> createPBM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height;
        file >> height >> width;
        auto image = std::make_unique<Image<bool>>(height, width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int value;
                file >> value;
                image->setPixel(i, j, value == 1);
            }
        }

        return image;
    }

    static std::unique_ptr<Image<int>> createPGM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height, maxValue;
        file >> height >> width >> maxValue;
        auto image = std::make_unique<Image<int>>(height, width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int value;
                file >> value;
                if (value > maxValue) value = maxValue;
                image->setPixel(i, j, value);
            }
        }

        return image;
    }

    static std::unique_ptr<Image<RGB>> createPPM(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        int width, height, maxValue;
        file >> height >> width >> maxValue;
        auto image = std::make_unique<Image<RGB>>(height, width);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int red, green, blue;
                file >> red >> green >> blue;
                image->setPixel(i, j, { red, green, blue });
            }
        }

        return image;
    }



    template<typename T>
    static std::unique_ptr<ImageBase> createImage(const std::string& filePath) {
        std::string format = filePath.substr(filePath.size() - 3, 3);
        if (format == "pbm") {
            return createPBM(filePath);
        }
        else if (format == "ppm") {
            return createPPM(filePath);
        }
        else if (format == "pgm") {
            return createPGM(filePath);
        }
        else {
            throw std::runtime_error("Unsupported file format: " + filePath);
        }
    }
};



/*
std string ???
vector ??? 
unique ptr ???

taq logika v methodite moje da se iznese po nqkuv nachin idk?



*/
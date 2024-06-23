#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MyString.h"
#include "Image.hpp"
#include "BlackOrWhitePixel.h"
#include "GrayscalePixel.h"
#include "RGBPixel.h"

class ImageFactory {
public:
    static Image createPBM(const MyString& filePath) {
        std::ifstream file(filePath.c_str());
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        int width, height;
        file >> height >> width;
        Image image(height,width,filePath);

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
    
    static Image createPGM(const MyString& filePath) {
        std::ifstream file(filePath.c_str());
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        int width, height;
        file >> height >> width;
        Image image(height,width, filePath);

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

    static Image createPPM(const MyString& filePath) {
        std::ifstream file(filePath.c_str());
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        int width, height;
        file >> height >> width;
        Image image(height,width, filePath);

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

    static Image createImage(const MyString& filePath) {
        MyString format = filePath.substr(strlen(filePath.c_str()) - 3, 3);
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
            throw std::runtime_error("Unsupported file format");
        }
    }
  

    static Image createHorizontalCollage(const Image& img1, const Image& img2, const MyString& newPath) {
        int newHeight = std::max(img1.getHeight(), img2.getHeight());
        int newWidth = img1.getWidth() + img2.getWidth();
        Image collage(newHeight, newWidth, newPath);
        
        Pixel* def = new BlackOrWhitePixel(0);
        for (size_t i = 0; i < newHeight; i++)
        {
            for (size_t j = 0; j < newWidth; j++)
            {
                collage.setPixel(i, j, def);
            }
        }
        delete def;


        for (int i = 0; i < img1.getHeight(); ++i) {
            for (int j = 0; j < img1.getWidth(); ++j) {
                collage.setPixel(i, j, &img1.getPixel(i, j));
            }
        }

        for (int i = 0; i < img2.getHeight(); ++i) {
            for (int j = 0; j < img2.getWidth(); ++j) {
                collage.setPixel(i, j + img1.getWidth(), &img2.getPixel(i, j));
            }
        }

        collage.save();
        return collage;
    }
    static Image createVerticalCollage(const Image& img1, const Image& img2, const MyString& newPath) {
        int newHeight = img1.getHeight()+img2.getHeight();
        int newWidth = std::max(img1.getWidth() ,img2.getWidth());
        Image collage(newHeight, newWidth, newPath);

        Pixel* def = new BlackOrWhitePixel(0);
        for (size_t i = 0; i < newHeight; i++)
        {
            for (size_t j = 0; j < newWidth; j++)
            {
                collage.setPixel(i, j, def);
            }
        }
        delete def;
        for (int i = 0; i < img1.getHeight(); ++i) {
            for (int j = 0; j < img1.getWidth(); ++j) {
                collage.setPixel(i, j, &img1.getPixel(i, j));
            }
        }

        for (int i = 0; i < img2.getHeight(); ++i) {
            for (int j = 0; j < img2.getWidth(); ++j) {
                collage.setPixel(i+img1.getHeight(), j, &img2.getPixel(i, j));
            }
        }

        collage.save();
        return collage;
    }
};

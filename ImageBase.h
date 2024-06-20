#pragma once

class ImageBase {
public:
    virtual ~ImageBase() = default;
    virtual void print() const = 0;
};
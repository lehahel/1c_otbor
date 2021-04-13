#include <png.h>
#include <iostream>
#include <fstream>

CPngFile::CPngFile(std::string filename) {
    std::ifstream in;
    in.open(filename);
    in >> width_ >> height_;

    data_.assign(height_ * width_, 0);
    for (int& elem : data_) {
        in >> elem;
    }
}

size_t CPngFile::GetHeight() const {
    return height_;
}

size_t CPngFile::GetWidth() const {
    return width_;
}

int CPngFile::operator() (size_t row, size_t column) const {
    return data_[row * width_ + column];
}

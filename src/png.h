#pragma once

#include <string>
#include <vector>

class CPngFile {
  public:
    CPngFile(std::string filename);
    int operator() (size_t row, size_t column) const;
    size_t GetHeight() const;
    size_t GetWidth() const;

  private:
    std::vector<int> data_;
    size_t width_;
    size_t height_;
};
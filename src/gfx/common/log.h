#pragma once

#include <iostream>
#include <fstream>

class LOG {
  public:
    LOG(std::string filePath);
    ~LOG();
    void Write(std::string log);
  private:
    std::fstream fileOpener;
    std::string filePath;
};

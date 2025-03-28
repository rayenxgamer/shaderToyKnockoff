#include <common/log.h>

LOG::LOG(std::string path){
  LOG::fileOpener.open(path, std::ios::out);
  LOG::filePath = path;
  std::cout << "file opened!" << std::endl;
  LOG::fileOpener.close();
}

LOG::~LOG(){
  fileOpener.close();
  std::cout << "all has been written to the log file: " << LOG::filePath << std::endl;
}

void LOG::Write(std::string log){
  fileOpener.open(LOG::filePath, std::ios::app);
  std::cout << "wrote to the log file!\n";
  fileOpener << log << std::endl;
  fileOpener.close();
}

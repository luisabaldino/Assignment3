#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class FileIO{
  public:
    //instance variables
    ifstream inFile;
    ofstream outFile;
    string line;

    string fileStatus;
    string location;

    //constructor/destructor
    FileIO(string input);
    ~FileIO();

    //core functions
    string getFileStatus();
    string nextElement();
};

FileIO::FileIO(string input){
  fileStatus = "Not Found";
  location = input;
  inFile.open(location);
  if (inFile) fileStatus = "Open";
}

FileIO::~FileIO(){
}

string FileIO::getFileStatus(){
  return fileStatus;
}

string FileIO::nextElement(){
  //check if eof
  getline(inFile, line);
  if (inFile.eof()) {
    return "#eof#";
  } else {
    return line;
  }
}

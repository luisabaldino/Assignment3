#include <iostream>
#include "GenStack.h"
#include "FileIO.h"
#include "CheckDelimiters.h"

int main (int argc, char **argv){

  bool errors = false;
  bool again = true;

  //Create a File object
  FileIO *sourceFile = new FileIO(argv[1]);

  while (again) {

  //Check if file is opened
  if (sourceFile->getFileStatus() != "Open"){
    cout << "Could not open file. Please try again." << endl;
    again = false;
    //If the file is open, run it through CheckDelimiters
  } else {
    cout << "File successfuly opened." << endl;
    CheckDelimiters *checkD = new CheckDelimiters(sourceFile);
    errors = checkD->check();

    //Ask user if they would like to run another file
    if (errors){
      again = false;
    } else {
      string goAgain;
      cout << "Would you like to input another file? Y/N?" << endl;
      cin >> goAgain;
      if (goAgain == "N") {
        again = false;
      } else {
        string fileName;
        cout << "What file would you like to analyze?" << endl;
        cin >> fileName;
        //Create a new File object
        delete sourceFile;
        FileIO *sourceFile = new FileIO(fileName);
        }
      }
    }
  }
}

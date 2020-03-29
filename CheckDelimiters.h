#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "FileIO.h"
using namespace std;

class CheckDelimiters{
  public:
    //Instance variables
    FileIO *file;
    GenStack<char> *stack = new GenStack<char>(0);

    //Constructor/Destructor
    CheckDelimiters(FileIO *sourceFile);
    ~CheckDelimiters();

    //Core functions
    bool check();

};

CheckDelimiters::CheckDelimiters(FileIO *sourceFile){
  file = sourceFile;
}

bool CheckDelimiters::check(){
  bool errors = false;
  int lineCounter = 0;
  stringstream str;
  string line = file->nextElement();
  while (line != "#eof#") {
      //Loop through char in line
      for (int i = 0; i < line.length(); i++){
        //Compare curr char in line to opening delimiters
        if (line[i] == '(' || line[i] == '{' || line[i] == '['){
          //If its an open delimiter, push to stack
          stack->push(line[i]);
        }
        else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
          char currPopped;
          //If it's a closed delimiter, pop from stack
          try {
            currPopped = stack->pop();
          } catch( std::out_of_range& e ) {
            cout << "Unballanced delimeter: " << line[i] << endl;
            errors = true;
            break;
          }
          char currPoppedOpp;
          if (currPopped == '(') currPoppedOpp = ')';
          if (currPopped == '{') currPoppedOpp = '}';
          if (currPopped == '[') currPoppedOpp = ']';
          //If curr char is not equal to the opposite of the popped char from the stack
          if (line[i] != currPoppedOpp){
            //Create error message & break for loop
            str  << "Line nbr: " << lineCounter << "\nChar expected: " << currPoppedOpp << " Found: " << line[i];
            cout << str.str() << endl;
            errors = true;
            break;
          }
        }
      }
      //If an error was found, break out of while loop too
      if (errors) break;
      //If everything's good, go to next line
      line = file->nextElement();
      lineCounter ++;
  }
  if (!errors){
    //End of file, if there have been no errors so far, check if stack is is empty
    if (!stack->isEmpty()){

      char currPopped = stack->pop();
      char currPoppedOpp;
      if (currPopped == '(') currPoppedOpp = ')';
      if (currPopped == '{') currPoppedOpp = '}';
      if (currPopped == '[') currPoppedOpp = ']';

      //If there's an error, let the user know
      str  << "Reached end of file (Line nbr: " << lineCounter << ")\nExpected: " << currPoppedOpp;
      cout << str.str() << endl;

    } else{
      //There are no errors
      cout << "Everything looks good!" << endl;
    }
  }
  //Destroy Stack

  return errors;
}

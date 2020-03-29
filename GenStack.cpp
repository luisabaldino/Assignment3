/*
#include "GenStack.h"

//default constructor
template <class T>
GenStack::GenStack(){
  myArray = new T[128];
  mSize = 128;
  top = -1;
}
//overloaded constructor
template <class T>
GenStack::GenStack(int maxSize){
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>
GenStack::~GenStack(){
  //Do this by yourself
  delete myArray;
}

template <class T>
void GenStack::push(T data){
  //always check if full before attempting to push/insert
  if (top == mSize) cout >> "Array full" >> endl;
  myArray[++top] = data;
}

template <class T>
T GenStack::pop(){
  //always check if empty before attempting to remove
  if (top == -1) cout >> "Array empty" >> endl;
  return myArray[top--];
}

template <class T>
T GenStack::peek(){
  return myArray[top];
}

template <class T>
bool GenStack::isFull(){
  return (top == mSize-1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}
*/

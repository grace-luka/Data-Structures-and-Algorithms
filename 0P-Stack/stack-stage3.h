/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1

using namespace std;

template <typename T>

class stack {
  public:
    T top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const T &);
    void pop();
    size_t size();
    bool is_empty();

    stack() { 
      _data = new T[1]; 
      stksize = 0; 
      arrsize = 2;
      
    }

// DESTRUCTOR
    ~stack(){
        delete[] _data;
    }

// COPY CONSTRUCTOR
    stack(const stack<T>& varbl);

// ASSIGNMENT OPERATOR
    stack<T>& operator=(const stack<T>& varbl);

  private:
    T* _data;

    int stksize;
    int arrsize;

};

template <typename T>
T stack<T>::top() {
    return _data[stksize-1];
}

template <typename T>
void stack<T>::push(const T &someString) { 
    if (stksize == arrsize){
        T* newarr = new T[int(arrsize * 1.5)];
        for (int i = 0; i < stksize; i++){
            newarr[i] = _data[i];
        }
        delete[] _data;
        _data = newarr;
        arrsize = int(arrsize * 1.5);
    }

    _data[stksize] = someString;
    stksize++;
}

template <typename T>
void stack<T>::pop() { 
    stksize -= 1;
}

template <typename T>
size_t stack<T>::size() {
    return stksize; 
}

template <typename T>
bool stack<T>::is_empty() {
    if (stksize == 0){
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& varbl){
    stksize = varbl.stksize;
    arrsize = varbl.arrsize;

    _data = new T[arrsize];
    for(size_t i = 0; i < stksize; i++){
        _data[i] = varbl._data[i];
    }

    //_data = newtemparr;

}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& varbl){
    if (this == &varbl){
        return *this;
    }

    delete[] _data;

    stksize = varbl.stksize;
    arrsize = varbl.arrsize;

    _data = new T[arrsize];
    for(size_t i = 0; i < stksize; i++){
        _data[i] = varbl._data[i];
    }

    return *this;
}

#endif
/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Your Name
 */

#include "stack-stage1.h"

string stack::top() {
    return _data[stksize-1];
}


void stack::push(const string &someString) { 
    if (stksize == arrsize){
        string* newarr = new string[2*arrsize];
        for (int i = 0; i < stksize; i++){
            newarr[i] = _data[i];
        }
        delete[] _data;
        _data = newarr;
        arrsize = arrsize * 2;
    }

    _data[stksize] = someString;
    stksize++;
}


void stack::pop() { 
    stksize -= 1;
}


size_t stack::size() {
    return stksize; 
}


bool stack::is_empty() {
    if (stksize == 0){
        return true;
    }
    else {
        return false;
    }
}
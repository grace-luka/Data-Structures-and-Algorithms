/*
 * hashtable.h
 *
 * A basic hashtable implementation.  This hashtable uses vectors,
 * rather than linked lists, to implement chaining.
 * 
 * Author: <your name here>
 */

#ifndef _HASHTABLE_PROJECT_H
#define _HASHTABLE_PROJECT_H

#include <functional>   // for std::hash
#include <algorithm>
#include <vector>



using namespace std;

template <class T, class H = std::hash<T>>
class hashtable {
public:
    // constructor
    hashtable(){
        mtable.resize(4);
        msizetable = 4;
        msizevalues = 0;
    }

    // basic hashset operations
    void insert(const T& key){
        if (contains(key)){
            return;
        }

        msizevalues++;

        if (.75 <= load_factor()){

            msizetable = msizetable * 2;
            vector<vector<T>> temptable(msizetable);

            for (size_t i = 0; i < mtable.size(); i++){
                for (size_t j = 0; j < mtable.at(i).size(); j++){

                    size_t hashValueLocation = hash(mtable.at(i).at(j)) % msizetable;
                    temptable.at(hashValueLocation).push_back(mtable.at(i).at(j));
                }
            }

            mtable.swap(temptable);
            
        }

        size_t newHashValueLocation = hash(key) % msizetable;
        mtable.at(newHashValueLocation).push_back(key);

    }

    void remove(const T& key){

        size_t index = hash(key) % msizetable;
        for (size_t i = 0; i < mtable.at(index).size(); i++){
            if (mtable.at(index).at(i) == key){
                mtable.at(index).erase(mtable.at(index).begin() + i);
                msizevalues--;
                break;
            }
        }
        return;
    }

    bool contains(const T& key){
        size_t index = hash(key) % msizetable;
        for (size_t i = 0; i < mtable.at(index).size(); i++){
            // if (find(mtable.at(i).begin(), mtable.at(i).end(), key) != mtable.at(i).end()){
            //     return true;
            // }
            if (mtable.at(index).at(i) == key){
                return true;
            }
        }
    return false;
    }

    size_t size(){
        return msizevalues;
    }

    // diagnostic functions
    double load_factor(){
        return double(msizevalues)/msizetable;
    }

    // convenience method, invokes the "hash" template parameter
    // function object to get a hash code
    static size_t hash(const T &key) {
        H h;
        return h(key);
    }

private:
    vector<vector<T>> mtable;
    int msizetable;
    int msizevalues;
};

#endif

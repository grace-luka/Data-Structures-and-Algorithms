/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: <your name here>
 */

#include "trie.h"
#include <iostream>

using namespace std;


//constructor for root of tree
trie::trie() : root(new TrieNode()){
}

//destructor for root of trie
trie::~trie(){
    delete root;
}

//constructor to make a new trinode
trie::TrieNode::TrieNode(){
    isTerminal = false;
    for (size_t i = 0; i < 26; i++){
        leafs[i] = nullptr;
    }
    
}
//delalocating memory of trienode with destructor
trie::TrieNode::~TrieNode() {
    for (size_t i = 0; i < 26; i++){
        if (leafs[i] != nullptr){
            delete leafs[i];
        }
        leafs[i] = nullptr;
    }
}

//insert function to trie
void trie::insert(const string &s){
    TrieNode* currentNode = root; //set head of trie to the root, we are currently looking at the root
    for (char chars : s){
        int index = chars - 'a';
        if (currentNode->leafs[index] == nullptr){
            currentNode->leafs[index] = new TrieNode();
        }

    currentNode = currentNode->leafs[index];
    }
    currentNode->isTerminal = true;
}

bool trie::contains(const string &s){
    TrieNode* currentNode = root; //set head of trie to the root, we are currently looking at the root
    for (char chars : s){
        int index = chars - 'a';
        if(currentNode->leafs[index] == nullptr){
            return false; //does not contain string
        }
        currentNode = currentNode->leafs[index];
    }

    return currentNode->isTerminal;
}

bool trie::is_prefix(const string &s){
    TrieNode* currentNode = root; //set head of trie to the root, we are currently looking at the root
    for (char chars : s){
        int index = chars - 'a';
        if(currentNode->leafs[index] == nullptr){
            return false;
        }
        currentNode = currentNode->leafs[index];
    }
    return true;
}


void trie::extend(const string &prefix, vector<string> &result){
    TrieNode* currentNode = root; //set head of trie to the root, we are currently looking at the root
    for (char chars : prefix){
        int index = chars - 'a';
        if(currentNode->leafs[index] == nullptr){
            return; //prefix is not included in trie
        }
        currentNode = currentNode->leafs[index];
    }
    helperFunction(currentNode, prefix, result);
}

void trie::helperFunction(TrieNode* currentTrieNode, const string& currentPrefix, vector<string>& final){
    if(currentTrieNode->isTerminal){
        final.push_back(currentPrefix);
    }
    for (size_t i = 0; i < 26; i++){
        if(currentTrieNode->leafs[i] ){
            char charNext = 'a' + i;
            helperFunction(currentTrieNode->leafs[i], currentPrefix + charNext, final);
        }
    }
}
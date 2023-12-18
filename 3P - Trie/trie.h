/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

using namespace std;

class trie {
public:
    trie();
    ~trie();
    void insert(const string &s);
    bool contains(const string &s);
    bool is_prefix(const string &s);
    void extend(const string &prefix, vector<string> &result);

private:
    class TrieNode{
    public:
        TrieNode();
        ~TrieNode();
        bool isTerminal;
        TrieNode* leafs[26];
    };
    TrieNode* root;
    void helperFunction(TrieNode* node, const string& currentPrefix, vector<string>& result);

};

#endif

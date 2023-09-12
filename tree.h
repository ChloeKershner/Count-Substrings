//
// Created by Chloe Kershner on 9/2/23.
//

#ifndef UNTITLED5_TREE_H
#define UNTITLED5_TREE_H

#include <string>

class TrieNode {
public:
    TrieNode* children[31];
    TrieNode();
};

class Trie {
public:
    Trie();
    bool insert(const char* stringToInsert = nullptr);
    TrieNode* getRootNode();
private:
    TrieNode* root;
};

void insertSubstrings(Trie& trie, const std:: string& word);
bool search(Trie& trie, const char* substring);
int countTheSubstrings(Trie& trie, const std::string& substring);


#endif //UNTITLED5_TREE_H

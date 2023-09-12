//
// Created by Chloe Kershner on 9/2/23.
//
#include "tree.h"
#include <vector>
#include <cstring>


TrieNode::TrieNode(){
    for (size_t i = 0; i < 30; i++) { // manually initializes all pointers in that child array to nullptr
        children[i] = nullptr;
    }
}

Trie::Trie() {
    root = new TrieNode(); // upon instantiation of a trie, a root node will be initialized
}

bool Trie::insert(const char* stringToInsert) {
    TrieNode* currNode = root;

    for (size_t i = 0; i < strlen(stringToInsert); i++) { // iterates through every character in the string
        int index;
        // assigning the index to search for
        char c = tolower(stringToInsert[i]);
        if ((c >= 'a') && (c <= 'z')) { // checking for a-z
            index = c - 'a'; // uses the ascii values to find the offset from 'a' to calculate the index
        } else if (c == 39) { // checking for '
            index = 26;
        } else if (c == '-') { // checking for -
            index = 27;
        } else if (c == '_') { // checking for _
            index = 28;
        } else if (c == ' ') { // checking for space
            index = 29;
        }
        else{
            continue; // continues if there is an invalid char
        }
        if (!currNode->children[index]) {
            currNode->children[index] = new TrieNode();
        }
        currNode = currNode->children[index]; // reassigns the currNode to the new node just created for the next loop
    }
    int index = 30; // end of word, so point to \0
    if (!currNode->children[index]) {
        currNode->children[index] = new TrieNode();
    }
    return true; // insertion was successful
}

TrieNode* Trie::getRootNode() {
    return root;
}

void insertSubstrings (Trie& trie, const std::string& word) {
    for (size_t i = 0; i < word.length(); i++) { // inserts the word and all of its substrings
        trie.insert(word.c_str() + i);
    }
}

bool search(Trie& trie, const char* substring) {
    TrieNode* currNode = trie.getRootNode();

    // similar to inserting, assigning the correct index to search for based on the current char of the substring
    for (size_t i = 0; i < strlen(substring); i++){
        char c = tolower(substring[i]);
        int index;
        if ((c >= 'a') && (c <= 'z')) { // checking for a-z
            index = c - 'a'; // determining if valid character
        } else if (c == 39) {
            index = 26;
        } else if (c == '-') {
            index = 27;
        } else if (c == '_') {
            index = 28;
        } else if (c == ' ') {
            index = 29;
        } else {
            return false; // invalid char
        }

        if (!currNode->children[index]){
            return false; // Substring is not found
        }
        currNode = currNode->children[index]; // char found, so move to the next char
    }

    return true; // substring found
}

int countTheSubstrings(Trie& trie, const std::string& substring) {
    int counter = 0;
    /* calls the search method, if found, counter should be increased
    note: uses a counter (which will always either be 1 or zero, but using int counter instead of bool for easier adding
    to the running total in main function
    */
    if (search(trie,substring.c_str())) {
        counter++;
    }
    return counter;
}
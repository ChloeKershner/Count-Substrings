//
// Created by Chloe Kershner on 9/2/23.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "tree.h"


int main(int argc, char* argv[]) {

    //handles if the user provides the wrong number of arguments
    if (argc!= 3) {
        std::cerr << "Usage: " << argv[0] << "  <vocabulary_file> <test_file>" << std::endl;
        return 1;
    }

    // assigning the arguments
    const char* vocabFilepath = argv[1];
    const char* testFilePath = argv[2];

    std::vector<std::string> vocab; // vector of vocabulary words

    // opening the vocabulary.txt file
    std::ifstream vocabFile(vocabFilepath);
    //handles if the file fails to open
    if (!vocabFile.is_open()) {
        std::cerr << "Failed to open the vocab file." << std::endl;
        return 1;
    }
    std::string word;
    // populating the vocab vector
    while(std::getline(vocabFile, word)){
        for (char &c : word) {
            c = tolower(c); // makes all the words in the vocab file lowercase
        }
        vocab.push_back(word);
    }
    vocabFile.close();

    // opening the testfile.txt file
    std::ifstream testFile(testFilePath);
    // handles if the testfile fails to open
    if (!testFile.is_open()) {
        std::cerr << "Failed to open the testfile." << std::endl;
        return 1;
    }
    // line by line of testfile.txt, make the trie and search for the substrings in that trie
    while(std::getline(testFile, word)) {

        for (char &c : word) {
            c = tolower(c); // makes the testfile.text all lowercase
        }
        Trie subTrie;
        insertSubstrings(subTrie, word); // insert substrings
        int total = 0;
        for (size_t i = 0; i < vocab.size(); i++) { //for every word in the vocab vector, count the substrings
            total = countTheSubstrings(subTrie, vocab[i]) + total; // running total of the substrings found
        }
        std::cout << total << '\n'; // prints the total

    }
    testFile.close();


    return 0;
}

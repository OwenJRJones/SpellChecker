#include "SpellChecker.h"
#include<iostream>
#include <fstream>

using namespace std;

void SpellChecker::read_dictionary(string &file_name) {
    fstream file;
    string word;
    auto count{1};
    try {
        // Open dictionary file
        file.open(file_name.c_str());
        if (file.is_open()) {
            // Populate BST with dictionary words
            while (file >> word) {
                string word2 = word + " " + to_string(count);
                m_bst.insert(word2);
                count++;
            }
        }
    } catch (exception &e) {
        e.what();
    }
    file.close();
}

void SpellChecker::check_words(string &file_name) {
    fstream file;
    string word;

    try {
        // Open text file
        file.open(file_name.c_str());

        if (file.is_open()) {
            // Loop through words
            while (file >> word) {
                // Check if word is supposed to be word

                // Check if word is found in BST
                if (!m_bst.find(word)) {
                    // Output if not found in BST
                    cout << word << endl;
                }
            }
        }
    } catch (exception &e) {
        e.what();
    }
    file.close();
}

void SpellChecker::display_tree() {
    // Display tree to console
    cout << m_bst << endl;
}

SpellChecker::~SpellChecker() = default;

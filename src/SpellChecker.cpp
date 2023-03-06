#include "SpellChecker.h"
#include<iostream>
#include <fstream>

using namespace std;

void SpellChecker::check_words(string &input_file, string &output_file,
                               string &dict_file) {

    // Read in dictionary words
    read_dictionary(dict_file);

    fstream file;
    string word;

    try {
        // Open text file
        file.open(input_file.c_str());

        if (file.is_open()) {
            // Loop through words
            while (file >> word) {
                // Wash words of any special chars & convert to lowercase
                word = remove_chars(word);
                // Check if word is empty after wash
                if (!word.empty()) {
                    // Check if word is found in BST, output if not
                    if (!m_bst.find(word)) {
                        cout << word << endl;
                    }
                }
            }
        }
    } catch (exception &e) {
        cout << e.what();
    }
    file.close();

    // Save BST to file
    save_tree(output_file);

    cout << endl << "BST saved to " << output_file << "." << endl;
}

void SpellChecker::read_dictionary(string &file_name) {
    fstream file;
    string word;

    try {
        // Open dictionary file
        file.open(file_name.c_str());
        if (file.is_open()) {
            // Populate BST with dictionary words
            while (file >> word) {
                m_bst.insert(word);
            }
        }
    } catch (exception &e) {
        cout << e.what();
    }
    file.close();
}

string SpellChecker::remove_chars(string &word) {
    // Loop through word and erase special chars
    for (auto i = 0; i < word.size(); i++) {
        if (word[i] < 'A' || word[i] > 'Z' &&
                             word[i] < 'a' || word[i] > 'z') {
            // Erase non alphabetic char
            word.erase(i, 1);
            i--;
        }
        // Convert chars to lowercase
        word[i] = tolower(word[i]);
    }
    return word;
}

void SpellChecker::save_tree(string &file_name) {
    fstream file;

    try {
        file.open(file_name.c_str(), ios::out | ios::trunc);

        if (file.is_open()) {
            // Save BST to file
            file << m_bst;
        }
    } catch (exception &e) {
        cout << e.what();
    }
    file.close();
}

void SpellChecker::display_tree() {
    // Display tree to console
    cout << m_bst << endl;
}

SpellChecker::~SpellChecker() = default;
#include <iostream>
#include "SpellChecker.h"

using namespace std;

int main(int argc, char** argv) {

    SpellChecker sc;

    string input_file;
    string output_file;
    string dictionary;

    // Prompt user for filename if one was not given, then open/read file
    if (argc < 4) {
        cout << "Incorrect number / improper file types specified." << endl;

        cout << "Please specify input file: ";
        getline(cin, input_file);

        cout << "Please specify output file: ";
        getline(cin, output_file);

        cout << "Please specify dictionary file: ";
        getline(cin, dictionary);

    } else {
        input_file = argv[1];
        output_file = argv[2];
        dictionary = argv[3];
    }

    // Run SpellCheck
    sc.check_words(input_file, output_file, dictionary);

    return 0;
}
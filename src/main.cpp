#include <iostream>
#include "SpellChecker.h"

using namespace std;

int main(int argc, char **argv) {

    SpellChecker sc;

    string input_file;
    string output_file = "../output/output.txt";
    string dictionary = "../docs/dictionary.txt";

    switch (argc) {
        case 4:
            input_file = argv[1];
            output_file = argv[2];
            dictionary = argv[3];
            break;
        case 3:
            input_file = argv[1];
            output_file = argv[2];
            break;
        case 2:
            input_file = argv[1];
            break;
        default:
            // Prompt user for file name(s) if not given
            cout << "Incorrect number / improper file types specified." << endl;

            cout << "Please specify relative path to input file: ";
            getline(cin, input_file);

            string input;

            cout << "Please specify relative path to output file or '-d'"
                 << " for default output file: ";
            getline(cin, input);

            if (input != "-d") {
                output_file = input;
            }

            cout << "Please specify relative path to dictionary file or '-d'"
                 << " for default dictionary file: ";
            getline(cin, input);

            if (input != "-d") {
                dictionary = input;
            }
    }

    // Run SpellCheck
    sc.check_words(input_file, output_file, dictionary);

    return 0;
}
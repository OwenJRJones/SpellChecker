#include <iostream>
#include "SpellChecker.h"

using namespace std;

int main(int argc, char** argv) {

    SpellChecker sc;

    string input_file;
    string output_file = "../output/output.txt";
    string dictionary = "../docs/dictionary.txt";
    bool use_def = false;

    if (argc < 4) {
        input_file = argv[1];
        if (string(argv[2]) == "-d") {
            use_def = true;
        }
    }

    // Prompt user for filename if one was not given, then open/read file
    if (argc < 4 && !use_def) {
        cout << "Incorrect number / improper file types specified." << endl;

        cout << "Please specify input file: ";
        getline(cin, input_file);

        cout << "Please specify output file: ";
        getline(cin, output_file);

        cout << "Please specify dictionary file: ";
        getline(cin, dictionary);

    } else if (argc == 4){
        input_file = argv[1];
        output_file = argv[2];
        dictionary = argv[3];
    }

    // Run SpellCheck
    sc.check_words(input_file, output_file, dictionary);

    return 0;
}
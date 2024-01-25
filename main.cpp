//Erstellen des Programm
//mkdir build
//cd build
//cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
//ninja
//Alternativ diesen Ordner mit VSCode oeffnen
#include <config.h>
#include <cstring>
#
#include <iostream>
using namespace std; // = std::

int main(int argc, const char **argv) { //argv[][]
    //std::cout << argv[0] << endl;
    //std::cout << argv[1] << endl;
    
    // Bing AI:
    if (argc != 2) {
        cerr << "Bitte nur ein Argument mitgeben" << endl;
        //return 1;
        return EXIT_FAILURE;
    }

    string text = argv[1];

    string border = "+";
    for (int i = 0; i < 78; i++) {
        border += "-";
    }
    border += "+";

    cout << border << endl;
    cout << "| " << text;
    for (int i = 0; i < 77 - text.length(); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << border << endl;


    /*
    cout << "Hallowelt, und es folgt noch etwas mehr ..." << endl;

    cout << "CMake gibt noch folgende Zusatzinformation mit:\n"
         << "Version:      " << MAIN_VERSION_MAJOR << '.' << MAIN_VERSION_MINOR << '\n'
         << "Beschreibung: " << MAIN_DESCRIPTION << endl;

    */    


    return EXIT_SUCCESS;
}

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
using namespace std;

int main(int argc, const char **argv) { //argv[][]
    //std::cout << argv[0] << endl;
    //std::cout << argv[1] << endl;
    
    // Bing AI:
    if (argc != 2) {
        std::cerr << "Bitte nur ein Argument mitgeben" << std::endl;
        //return 1;
        return EXIT_FAILURE;
    }

    std::string text = argv[1];
    
    std::string border = "+";
    for (int i = 0; i < 78; i++) {
        border += "-";
    }
    border += "+";

    std::cout << border << std::endl;
    std::cout << "| " << text;
    for (int i = 0; i < 77 - text.length(); i++) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << border << std::endl;


    /*
    cout << "Hallowelt, und es folgt noch etwas mehr ..." << endl;

    cout << "CMake gibt noch folgende Zusatzinformation mit:\n"
         << "Version:      " << MAIN_VERSION_MAJOR << '.' << MAIN_VERSION_MINOR << '\n'
         << "Beschreibung: " << MAIN_DESCRIPTION << endl;

    */    


    return EXIT_SUCCESS;
}

//Erstellen des Programm
//mkdir build
//cd build
//cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
//ninja
//Alternativ diesen Ordner mit VSCode oeffnen
#include <config.h>
#include <cstring>
#include <iostream>
using namespace std; // = std::

void Bing_command_block(const char** argv);
void Self_command_block(const char** argv);

int main(int argc, const char** argv) { //argv[][]
    //std::cout << argv[0] << endl;
    //std::cout << argv[1] << endl;
    
    if (argc != 2) {
        cerr << "Bitte nur ein Argument mitgeben" << endl;
        //return 1;
        return EXIT_FAILURE;
    }
    // Call Fuctions 
    Bing_command_block(argv);
    //Self_command_block(argv);



    /*
    cout << "Hallowelt, und es folgt noch etwas mehr ..." << endl;

    cout << "CMake gibt noch folgende Zusatzinformation mit:\n"
         << "Version:      " << MAIN_VERSION_MAJOR << '.' << MAIN_VERSION_MINOR << '\n'
         << "Beschreibung: " << MAIN_DESCRIPTION << endl;

    */    


    return EXIT_SUCCESS;
}

void Bing_command_block(const char** argv)
{
    /*
    Diese Function wurde mit hilfe der Bing Ai erstellt
    Die Function nutzt statt char pointer array die string klasse
    Die std:string Klasse kapselt Zeichenarrays und biete nützliche Methoden zb append().
    std:string kümmert sich selbst um Speicherverwaltung.
    */
    string text = argv[1];
    // Print text lengh
    cout << "Text leange:" << endl;
    cout << text.length() << endl;

    string border = "+";
    for (int i = 0; i < 78; i++) {
        border += "-";
    }
    border += "+";

    cout << border << endl;
    //cout << "| " << text;
    //string* b;
    if(text.length() > 77)
    {
        //cout << "if Treu" << endl;
        int nullst = 0;
        for (int a = 0; a < (text.length() / 77) ; a++)
        {

            cout << "| " << text.substr(nullst,nullst += 77) << "|" << endl;
            cout << nullst << endl;

        }
        cout << "| " << text.substr(nullst,nullst += (text.length() % 77));
        for (int i = 0; i < 77 - (text.length() % 77); i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    else
    {
        cout << "| " << text;
        for (int i = 0; i < 77 - text.length(); i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << border << endl;

}
void Self_command_block(char** argv)
{
    /*
    Das ist die selbst geschrieben Command Block Function
    Diese verwendet für die Umsetzung nicht die String Klasse 
    */


}
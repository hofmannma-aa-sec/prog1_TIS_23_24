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

void String_command_block(const char** argv);
void No_string_command_block(const char** argv);

int main(int argc, const char** argv) { //argv[][]
    //std::cout << argv[0] << endl;
    //std::cout << argv[1] << endl;
    
    if (argc != 2) {
        cerr << "Bitte nur ein Argument mitgeben" << endl;
        //return 1;
        return EXIT_FAILURE;
    }
    // Call Fuctions 
    String_command_block(argv);
    No_string_command_block(argv);



    /*
    cout << "Hallowelt, und es folgt noch etwas mehr ..." << endl;

    cout << "CMake gibt noch folgende Zusatzinformation mit:\n"
         << "Version:      " << MAIN_VERSION_MAJOR << '.' << MAIN_VERSION_MINOR << '\n'
         << "Beschreibung: " << MAIN_DESCRIPTION << endl;

    */    


    return EXIT_SUCCESS;
}

void String_command_block(const char** argv)
{
    /*
    Die Function nutzt statt char pointer array die string klasse
    Die std:string Klasse kapselt Zeichenarrays und biete nützliche Methoden zb append().
    std:string kümmert sich selbst um Speicherverwaltung.
    */
    cout << "C++ und String Klasse" << endl;
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

    if(text.length() > 77)
    {
        int nullst = 0;
        int cut = 77; 
        for (int i = 0; i < (text.length() / 77) ; i++)
        {

            //cout << "| " << text.substr(nullst, cut).length() << "|" << endl;
            cout << "| " << text.substr(nullst, cut) << "|" << endl;
            nullst = nullst + cut;

        }
        cout << "| " << text.substr(nullst, nullst + (text.length() % 77));
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
void No_string_command_block(const char** argv)
{
    /*
    Das ist die selbst geschrieben Command Block Function
    Diese verwendet für die Umsetzung nicht die String Klasse 
    */
    //char* border = "+";
    // Speicher resevieren
    char* border = new char[80];
    char* text = new char[80];
    const char* bp = new char[2];
    const char* bm = new char[2];
    memset(border, 0, 80);
    //border = "";
    bp = "+";
    bm = "-";
    cout << strlen(border) << endl;
    strcat(border, bp);
    cout << strlen(border) << endl;
    for (int i = 0; i < 78; i++) {
        strcat(border, bm);
    }
    strcat(border, bp);
    cout << strlen(argv[1]) << endl;
    cout << border << endl;
    if (strlen(argv[1]) > 77)
    {
        strcat(text, argv[1]);
        for (int i = 0; i < (strlen(argv[1]) / 77); i++)
        {
            //cout << "| " text
        }
        for (int i = 0; i < (strlen(argv[1]) % 77); i++)
        {
            /* code */
        }
        
        
    }
    else
    {
        strcat(text, argv[1]);
        for (int i = 0; i < 77 - strlen(argv[1]); i++)
        {
            strcat(text, " ");
        }
        
        cout << "| " << text << "|" << endl;
    }
    cout << strlen(border) << endl;
    cout << border << endl;
    delete[] border;
    delete[] text;
    //delete[] bm;
}
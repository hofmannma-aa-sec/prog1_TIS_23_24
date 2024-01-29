//Erstellen des Programm
//mkdir build
//cd build
//cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
//ninja
//Alternativ diesen Ordner mit VSCode oeffnen
#include <config.h>
#include <cstring>
#include <iostream>
// Konstanten

#define SIGN_PER_LINE = 0;
#define START_ADDRESS_LINE01 = 0;
#define START_ADDRESS_LINE02 = 0;
#define START_OF_TEXT = 0;
#define MAX_TEXT_LENGTH = 0;
#define OVERFLOWPRINTPOSITION = 0;
#define START_ADDRESS_LINE03 = 0;
#define TOTAL_BUFFER_SIZE = 0;

using namespace std; // = std::

void StringCommandBlock(const char** argv);
void NoStringCommandBlock(const char** argv);
void NoStringOverflowCommandBlock(const char** argv);

int main(int argc, const char** argv) { //argv[][]
    //std::cout << argv[0] << endl;
    //std::cout << argv[1] << endl;
    
    if (argc != 2) {
        cerr << "Bitte nur ein Argument mitgeben" << endl;
        //return 1;
        return EXIT_FAILURE;
    }
    /*
    Call Fuctions
    */

    StringCommandBlock(argv);
    NoStringCommandBlock(argv);
    NoStringOverflowCommandBlock(argv);


    /*
    cout << "Hallowelt, und es folgt noch etwas mehr ..." << endl;

    cout << "CMake gibt noch folgende Zusatzinformation mit:\n"
         << "Version:      " << MAIN_VERSION_MAJOR << '.' << MAIN_VERSION_MINOR << '\n'
         << "Beschreibung: " << MAIN_DESCRIPTION << endl;

    */    


    return EXIT_SUCCESS;
}

void StringCommandBlock(const char** argv)
{
    /**
    * Die Function nutzt statt char pointer array die string klasse
    * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines. 
    * Die std:string Klasse kapselt Zeichenarrays und biete nützliche Methoden zb append().
    * std:string kümmert sich selbst um Speicherverwaltung.
    * @param argv Parameter der von der Kommandozeile übergeben wird. 
    **/
    cout << "StringCommandBlock" << endl;
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
void NoStringCommandBlock(const char** argv)
{
    /**
     * Diese Funktion verwendet für die Umsetzung des Command Blocks nicht die String Klasse.
     * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines. 
     * @param argv Parameter der von der Kommandozeile übergeben wird. 
    **/

    // Speicher resevieren
    char* border = new char[80];
    char* text = new char[80];
    const char* bp = new char[2];
    const char* bm = new char[2];
    memset(border, 0, 80);
    memset(text, 0, 80);
    bp = "+";
    bm = "-";
    cout << "NoStringCommandBlock" << endl;

    strcat(border, bp);
    for (int i = 0; i < 78; i++) {
        strcat(border, bm);
    }
    strcat(border, bp);
    cout << border << endl;
    if (strlen(argv[1]) > 77)
    {
        strcat(text, argv[1]);
        int strstart = 0;
        for (int i = 0; i < (strlen(argv[1]) / 77); i++)
        {
            cout << "| ";
            for (int i = strstart; i < strstart + 77; i++)
            {
                cout << text[i];
            }
            strstart = strstart + 77;
            cout << "|"  << endl;
        }
        if ((strlen(argv[1]) % 77) != 0)
        {
            cout << "| ";
            /*
            test der berechnung der Stringlänge 
            cout << "For:" << endl;
            cout << strstart << endl;
            cout <<  strstart + (strlen(argv[1]) % 77) << endl;
            */
            for (int i = strstart; i < strstart + (strlen(argv[1]) % 77); i++)
            {
                cout << text[i];
            }
            for (int i = 0; i < 77 - (strlen(argv[1]) % 77); i++)
            {

                cout << " ";
            }
            cout << "|" << endl;
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

    cout << border << endl;
    delete[] border;
    delete[] text;
}
void NoStringOverflowCommandBlock(const char** argv)
{
    /**
     * Diese Funktion verwendet für die Umsetzung des Command Blocks nicht die String Klasse.
     * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines. 
     * @param argv Parameter der von der Kommandozeile übergeben wird. 
    **/

    char* border = new char[80];
    char* text = new char[80];
    const char* bp = new char[2];
    const char* bm = new char[2];
    memset(border, 0, 80);
    memset(text, 0, 80);
    bp = "+";
    bm = "-";
    strcat(border, bp);
    cout << "NoStringOverflowCommandBlock" << endl;

    for (int i = 0; i < 78; i++) {
        strcat(border, bm);
    }
    strcat(border, bp);
    cout << border << endl;

}
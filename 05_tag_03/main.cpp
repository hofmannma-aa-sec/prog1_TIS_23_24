// Erstellen des Programm
// mkdir build
// cd build
// cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
// ninja
// Alternativ diesen Ordner mit VSCode oeffnen
#include <config.h>
#include <cstring>
#include <iostream>
// Konstanten
/*
#define SIGN_PER_LINE = 0;
#define START_ADDRESS_LINE01 = 0;
#define START_ADDRESS_LINE02 = 0;
#define START_OF_TEXT = 0;
#define MAX_TEXT_LENGTH = 0;
#define OVERFLOWPRINTPOSITION = 0;
#define START_ADDRESS_LINE03 = 0;
#define TOTAL_BUFFER_SIZE = 0;
*/
using namespace std; // = std::

void StringCommandBlock(const char **argv);
void NoStringCommandBlock(const char **argv);
void NoStringOverflowCommandBlock(const char **argv);
void VorlesungsCommandBlock(const char **argv);

// Vorlesung Tag 4

enum
{
    SIGN_PER_LINE = 81,
    START_ADDRESS_LINE01 = 0,
    START_ADDRESS_LINE02 = SIGN_PER_LINE,
    START_OF_TEXT = START_ADDRESS_LINE02 + 2,
    MAX_TEXT_LENGTH = SIGN_PER_LINE - 2 - 2 - 1,
    // OVERFLOWPRINTPOSITION,
    START_ADDRESS_LINE03 = SIGN_PER_LINE * 2,
    TOTAL_BUFFER_SIZE = SIGN_PER_LINE * 3
};

int main(int argc, const char **argv)
{ // argv[][]
    // std::cout << argv[0] << endl;
    // std::cout << argv[1] << endl;

    if (argc != 2)
    {
        cerr << "Bitte nur ein Argument mitgeben" << endl;
        // return 1;
        return EXIT_FAILURE;
    }
    /**
     * Call Fuctions
     **/

    StringCommandBlock(argv);
    NoStringCommandBlock(argv);
    // NoStringOverflowCommandBlock(argv);
    VorlesungsCommandBlock(argv);

    /**
     *
     *
     * Vorlesungs CommandBlock
     *
     *
     **/
    cout << "VorlesungsCommandBlock" << endl;
    char *buffer = new char[TOTAL_BUFFER_SIZE];
    if (!buffer)
    {
        cerr << "Kein Speicher mehr verfuegbar" << endl;
        return EXIT_FAILURE;
    }
    {
        // Weise Leinwand
        memset(buffer, ' ', TOTAL_BUFFER_SIZE);

        *(buffer + TOTAL_BUFFER_SIZE - 1) = '\0';
    }
    {
        // Linie 1
        *(buffer + START_ADDRESS_LINE01) = '+';
        memset(buffer + START_ADDRESS_LINE01 + 1, '-', SIGN_PER_LINE - 2 - 1);
        *(buffer + START_ADDRESS_LINE01 + SIGN_PER_LINE - 2) = '+';
        *(buffer + START_ADDRESS_LINE01 + SIGN_PER_LINE - 1) = '\n';
    }

    {
        // Linie 2
        *(buffer + START_ADDRESS_LINE02) = '|';
        *(buffer + START_ADDRESS_LINE02 + SIGN_PER_LINE - 2) = '|';
        *(buffer + START_ADDRESS_LINE02 + SIGN_PER_LINE - 1) = '\n';
    }

    {
        // Linie 3
        memcpy(buffer + START_ADDRESS_LINE03, buffer + START_ADDRESS_LINE01, SIGN_PER_LINE - 1);
    }
    {
        const int length = strlen(argv[1]);
        const int reallength = length > MAX_TEXT_LENGTH ? MAX_TEXT_LENGTH : length;
        memcpy(buffer + START_OF_TEXT, argv[1], reallength);
    }
    cout << buffer << endl;
    delete[] buffer, buffer = nullptr;

    return EXIT_SUCCESS;
}

void StringCommandBlock(const char **argv)
{
    /**
     * Die Function nutzt statt char pointer array die string klasse
     * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines.
     * Die std:string Klasse kapselt Zeichenarrays und biete nützliche Methoden zb append().
     * std:string kümmert sich selbst um Speicherverwaltung.
     * @param argv Parameter der von der Kommandozeile übergeben wird.
     **/
    cout << "FunctionStringCommandBlock" << endl;
    string text = argv[1];
    // Print text lengh
    //cout << "Text leange:" << endl;
    //cout << text.length() << endl;

    string border = "+";
    for (int i = 0; i < 78; i++)
    {
        border += "-";
    }
    border += "+";

    cout << border << endl;

    if (text.length() > 77)
    {
        int nullst = 0;
        int cut = 77;
        for (int i = 0; i < (text.length() / 77); i++)
        {

            // cout << "| " << text.substr(nullst, cut).length() << "|" << endl;
            cout << "| " << text.substr(nullst, cut) << "|" << endl;
            nullst = nullst + cut;
        }
        cout << "| " << text.substr(nullst, nullst + (text.length() % 77));
        for (int i = 0; i < 77 - (text.length() % 77); i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }
    else
    {
        cout << "| " << text;
        for (int i = 0; i < 77 - text.length(); i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << border << endl;
}
void NoStringCommandBlock(const char **argv)
{
    /**
     * Diese Funktion verwendet für die Umsetzung des Command Blocks nicht die String Klasse.
     * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines.
     * @param argv Parameter der von der Kommandozeile übergeben wird.
     **/

    // Speicher resevieren
    char *border = new char[80];
    char *text = new char[80];
    const char *bp = new char[2];
    const char *bm = new char[2];
    memset(border, 0, 80);
    memset(text, 0, 80);
    bp = "+";
    bm = "-";
    cout << "FunctionNoStringCommandBlock" << endl;

    strcat(border, bp);
    for (int i = 0; i < 78; i++)
    {
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
            cout << "|" << endl;
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
void NoStringOverflowCommandBlock(const char **argv)
{
    /**
     * Diese Funktion verwendet für die Umsetzung des Command Blocks nicht die String Klasse.
     * Die Funktion splitted den String nach 80 Zeichen und und erweiterte die Box mit newlines.
     * @param argv Parameter der von der Kommandozeile übergeben wird.
     **/

    char *border = new char[80];
    char *text = new char[80];
    const char *bp = new char[2];
    const char *bm = new char[2];
    memset(border, 0, 80);
    memset(text, 0, 80);
    bp = "+";
    bm = "-";
    strcat(border, bp);
    cout << "FunctionNoStringOverflowCommandBlock" << endl;

    for (int i = 0; i < 78; i++)
    {
        strcat(border, bm);
    }
    strcat(border, bp);
    cout << border << endl;
    if (strlen(argv[1]) > 77)
    {
        for (int i = 0; i < 77; i++)
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
}
void VorlesungsCommandBlock(const char **argv)
{
    /**
     * Diese Funktion verwendet das Beispiel für die Umsetzung des Command Blocks aus der Vorlesung.
     *
     * @param argv Parameter der von der Kommandozeile übergeben wird.
     **/
    cout << "FunctionVorlesungsCommandBlock" << endl;
    char *buffer = new char[TOTAL_BUFFER_SIZE];

    if (!buffer)
    {
        cerr << "Keins Speicher zu verfügung" << endl;

        // return EXIT_FAILURE;
    }
    else
    {
        {
            // Weise Leinwand
            memset(buffer, ' ', TOTAL_BUFFER_SIZE);

            *(buffer + TOTAL_BUFFER_SIZE - 1) = '\0';
        }
        {
            // Linie 1
            *(buffer + START_ADDRESS_LINE01) = '+';
            memset(buffer + START_ADDRESS_LINE01 + 1, '-', SIGN_PER_LINE - 2 - 1);
            *(buffer + START_ADDRESS_LINE01 + SIGN_PER_LINE - 2) = '+';
            *(buffer + START_ADDRESS_LINE01 + SIGN_PER_LINE - 1) = '\n';
        }

        {
            // Linie 2
            *(buffer + START_ADDRESS_LINE02) = '|';
            *(buffer + START_ADDRESS_LINE02 + SIGN_PER_LINE - 2) = '|';
            *(buffer + START_ADDRESS_LINE02 + SIGN_PER_LINE - 1) = '\n';
        }

        {
            // Linie 3
            memcpy(buffer + START_ADDRESS_LINE03, buffer + START_ADDRESS_LINE01, SIGN_PER_LINE - 1);
        }
        {
            const int length = strlen(argv[1]);
            const int reallength = length > MAX_TEXT_LENGTH ? MAX_TEXT_LENGTH : length;
            memcpy(buffer + START_OF_TEXT, argv[1], reallength);
        }
        cout << buffer << endl;
    }
    delete[] buffer, buffer = nullptr;
}
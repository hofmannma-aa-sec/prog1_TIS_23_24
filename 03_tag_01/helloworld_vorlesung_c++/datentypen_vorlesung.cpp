#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // initaliesierungsklammern {}
    int i = {123};
    // Konstanten
    const int a = {234};
    // TXT mit Adresspointer
    const char * const TXT = {"Ich bin ein Text"};
    string b = {"Ich bin ein Text mit datentype string"};
    TXT[5]; //B
    &TXT[5]; //bin ein Text
    &TXT[5] - 5; // Ich bin ein Text 
    i = 124;
    cout << i << endl;
    cout << a << endl;
    cout << TXT << endl;
    cout << b << endl;
    return 0;
}

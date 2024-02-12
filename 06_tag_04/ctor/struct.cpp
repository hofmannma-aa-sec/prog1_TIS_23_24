#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct CStruct {
    CStruct(const char * const text = "") : name() {
        cout << "Ctor char" << endl;
        strncpy(name, text, sizeof(name));
    }

    CStruct(const string& text = "") : name() {
        cout << "Ctor string" << endl;
        strncpy(name, text.c_str(), sizeof(name));
    }

    CStruct(const CStruct& other) : name() {
        cout << "Copy Ctor" << endl;
        strncpy(name, other.name, sizeof(name));
    }

    ~CStruct() {
        cout << "Destructor" << endl;
    }

    string getName() const {
        return name;
    }

    char name[40];
};

ostream& operator<<(ostream& os, const CStruct s) {
    os << s.getName();
    return os;
}

int main() {

    cout << "Start"<< endl;

    CStruct c("The quick brown fox ...");

    cout << c << endl;

    //Bei einem Ptr auf eine Instanz wird diese nicht kopiert
    const CStruct *ptr = &c;

    cout << ptr->getName() << endl;

    //Bei einer Kopie wird der Copy Ctor aufgerufen
    CStruct other = c;

    cout << other << endl;

    cout << "Ende"<< endl;

    return EXIT_SUCCESS;
}

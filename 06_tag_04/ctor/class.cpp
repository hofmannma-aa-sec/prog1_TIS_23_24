#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class CClass {
public:
    CClass(const char * const text = "") : name() {
        cout << "Ctor char" << endl;
        strncpy(name, text, sizeof(name));
    }

    CClass(const string& text = "") : name() {
        cout << "Ctor string" << endl;
        strncpy(name, text.c_str(), sizeof(name));
    }

    CClass(const CClass& other) : name() {
        cout << "Copy Ctor" << endl;
        strncpy(name, other.name, sizeof(name));
    }

    ~CClass() {
        cout << "Destructor" << endl;
    }

    string getName() const {
        return name;
    }
private:

    char name[40];
};

ostream& operator<<(ostream& os, const CClass s) {
    os << s.getName();
    return os;
}

int main() {

    cout << "Start"<< endl;

    CClass c("The quick brown fox ...");

    cout << c << endl;

    //Bei einem Ptr auf eine Instanz wird diese nicht kopiert
    const CClass *ptr = &c;

    cout << ptr->getName() << endl;

    //Bei einer Kopie wird der Copy Ctor aufgerufen
    CClass other = c;

    cout << other << endl;

    cout << "Ende"<< endl;

    return EXIT_SUCCESS;
}

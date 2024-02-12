#ifndef _BASECLASS_H_
#define _BASECLASS_H_
#include <string>
using namespace std;

class BaseClass {
public:
    // Constructor
    BaseClass();

    // Destructor
    ~BaseClass();

    // Public member functions
    //void someFunction();

protected:

private:
    // Private member variables
    string name;
};

#endif // BASECLASS_H

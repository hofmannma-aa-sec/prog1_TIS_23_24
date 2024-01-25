#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    uint8_t i = {127} ;
    uint8_t a = {0};
    uint8_t b = {0};
    uint8_t c = ~i;
    b = i + 1;
    a = -120;
    cout << "I" << endl;
    cout << dec << (int)(int8_t)i << endl;
    cout << hex << (int)(int8_t)i << endl;
    cout << "A" << endl;
    cout << dec << (int)(int8_t)a << endl;
    cout << hex << (int)(int8_t)a << endl;
    cout << "B" << endl;
    cout << dec << (int)(int8_t)b << endl;
    cout << hex << (int)(int8_t)b << endl;
    cout << "C" << endl;
    cout << dec << (int)(int8_t)c << endl;
    cout << hex << (int)(int8_t)c << endl;
    c++;
    cout << "!C++ von I" << endl;
    cout << dec << (int)(int8_t)c << endl;
    cout << hex << (int)(int8_t)c << endl;
    //cout << hex << (int)&i << endl;
    return 0;
}

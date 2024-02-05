#include <iostream>

/**
 * The main function is the entry point of the program.
 * It demonstrates the casting of a double to an int.
 */
int main() {
    double num1 = 3.14;
    int num2 = static_cast<int>(num1); // Casting von double zu int

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    unsigned int i = (unsigned int) -1;
    float f = 1.645f;
    int i = (int) f;
    float f = int(123);
    int i = (int) float(123.0);
    /*
    1.0 -> double
    1 -> int
    1.0f -> float
    1L -> long
    1LL -> long long
    struct S{...
        //Gute
        buffer[sizeof(S)];
        memcopy(buffer,...);
        //QuickDirty
        S *ptr = (s) buffer;
        const uint8_t *text = 0x5467235F;
    }
    */

    
    return 0;
}

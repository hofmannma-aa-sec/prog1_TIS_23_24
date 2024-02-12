#include <stdio.h>

int main() {

    char buffer[1024];

		//Eine relativ alte Funktion (Anfang 70er Jahre) di fast in Vergessenheit geraten ist
		//aber noch erstaunliches bewirkt. Alternative ist auch snprintf
    const int length = sprintf(buffer,"Ich bin %d alt und wohne in %s\n", 54, "Friedrichshafen");

    puts(buffer);

    return 0;
}

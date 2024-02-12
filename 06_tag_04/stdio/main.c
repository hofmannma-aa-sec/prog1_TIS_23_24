#include <stdio.h>

int main() {

    //Die C-Variante ist schlanker wie die c++ Variante
    //und hat auch mehr Einstellmoeglichkieten.
    //Allerdings gibt es keine Automatik. Alles muss
    //von Hand gemacht werden

    //Die FILE 0 (stdin), 1 (stdout) und 2 (stderr) sind schon vorbelegt
    fputs("Schreiben auf eine Datei mit C\n",stdout);

    FILE *fd = fopen("quickbrownfox.txt","w");

    if(!fd) {
        fputs("Schreiben auf die Datei hat nicht funtioniert!\n",stderr);
        return 1;
    }

    fprintf(fd,"The Quick brown fox...\n");
    fclose(fd);

    return 0;
}

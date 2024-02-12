#include <fstream>
#include <iostream>
using namespace std;

int main() {

    {
        //Textvariante
        ofstream f;

        f.open("sample.txt", ofstream::out);

        if(f) {
            //Gut Pfad

            //Beim schreiben in Dateien mit Textunterstuetzung (nicht binaer)
            //bitte nicht immer ends,endl,flush verwenden das dann jedes mal der
            //Puffer geleert wird und die Datei auf die Festplatte geschrieben wird.
            //Einerseits koennen SSD/M2 gar nicht mehr die Schreibzyklen ab, mal abgesehen
            //dass das Programm dadurch auch schwerfaellig wird.
            f << "The quick brown fox jumps over the lazy dog!\n";

            //Jetzt ist der Text eingeschrieben und der Text kann direkt auf die Platte geschrieben werden.
            f << flush;

            f.close();

            //Der Test kann jetzt mit cat sample.txt angeschaut werden
        }
        else {
            cerr << "Datei konnte nicht geschrieben werden!" << endl;
            return EXIT_FAILURE;
        }
    }
    {
        //Binaervariante
        ofstream f;

        f.open("sample.bin", ofstream::out | ofstream::binary);

        if(f) {
            //Gut Pfad
            uint8_t buffer[16];

            //Binaerzahlen 0..F in das Array schreiben
            for(int i = 0; i < sizeof(buffer); ++i)
                buffer[i] = i;

            f.write((const char *)buffer, sizeof(buffer));

            f.flush();

            f.close();

            //Der Test kann jetzt mit hexdump -C sample.bin angeschaut werden
        }
        else {
            cerr << "Datei konnte nicht geschrieben werden!" << endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
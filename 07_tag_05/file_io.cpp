#include <iostream>;
#include <fstream>;

using namespace std;

void ofStream();
void binStream();

int main(int argc, char const *argv[])
{
    ofStream();
    binStream();
    
    return 0;
}
void ofStream()
{
    ofstream f;
    f.open("sampel.txt", ofstream::out);
    if(f)
    {
        f << "The quick brown fox jumps over the lazy dog!\n";
        f << flush;
        f.close();
    }
    else
    {
        cerr << "Datei konnte nicht geschrieben werden" << endl;
    }
}  
void binStream()
{
    ofstream f;
    f.open("sampel.txt", ofstream::out | ofstream::binary);
    if(f)
    {
        f << "The quick brown fox jumps over the lazy dog!\n";
        f << flush;
        f.close();
    }
    else
    {
        cerr << "Datei konnte nicht geschrieben werden" << endl;
    }
}
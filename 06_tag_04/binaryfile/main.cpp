#include <iostream>
#include <cstdint>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//Da 64Bit System die Daten immer aligned auf 8Bytes schreiben muss der Pack Faktor auf 1 gesetzt werden
#pragma pack(push,1)
struct TUserChunk {
    enum {
        CHUNKNAMELENGTH = 8,
        USERNAMELENGTH = 20,
        MAILADRESSLENGTH = 40
    };

    TUserChunk() :
        chunkname(),
        username(),
        mailaddress() {
        
        //Zur Kontrolle wann dieser Ctor aufgerufen wird
        cout << "Ctor" << endl;

        memcpy(chunkname,CHUNKNAME,strlen(CHUNKNAME));
        memset(username,'\0',USERNAMELENGTH);
        memset(mailaddress,'\0',MAILADRESSLENGTH);
    }

    ~TUserChunk() {
        //Zur Kontrolle wann dieser Destruktor aufgerufen wird
        cout << "Destructor" << endl;
    }

    char chunkname[CHUNKNAMELENGTH];
    char username[USERNAMELENGTH];
    char mailaddress[MAILADRESSLENGTH];

		//Die Wrapperklasse string wird hier verwendet um eine Kopie des usernamen
		//zurueck zu geben. Const dient hier als Kennzeichnung das der username nicht veraendert wird
    string getUsername() const {
        return username;
    }

		//Die Wrapperklasse string wird hier verwendet um eine Kopie des mailaddress
		//zurueck zu geben. Const dient hier als Kennzeichnung das der mailaddress nicht veraendert wird
    string getMailaddress() const {
        return mailaddress;
    }

    void setUsername(const char * const user) {
        memset(username,'\0',USERNAMELENGTH);
        if(user)
            memcpy(username, user, strlen(user) > USERNAMELENGTH ? USERNAMELENGTH : strlen(user));
    }

    void setMailaddress(const char * const mail) {
        memset(mailaddress,'\0',MAILADRESSLENGTH);
        if(mail)
            memcpy(mailaddress, mail, strlen(mail) > MAILADRESSLENGTH ? MAILADRESSLENGTH : strlen(mail));
    }

		//Ein Identifier dass die Binaerdatei spaeter noch identifiziert werden kann
		//static darum, um diesen Wert nicht pro Instanz zu vervielfachen
    static inline const char * const CHUNKNAME = {"USER    "};
};
#pragma pack(pop)

//Die Operatorueberladung vereinfacht die Benutzung einer Instanz zur Ausgabe
ostream& operator<<(ostream& os, const TUserChunk& user) {
    os << "User=" << user.username << ", Mail=" << user.mailaddress;
    return os;
}

//Dateinamen fuer die spaeter erzeugte Datei
static const char * const USERFILE = {"userdata.bin"};

int main() {
    cout << "Start" << endl;

    {
        //Werte schreiben
        TUserChunk user;

        user.setUsername("thomas");
        user.setMailaddress("thomas.staudacher@zf.com");

        ofstream f;
        f.open(USERFILE, ofstream::out | ofstream::binary);

        if(f) {
            f.write((const char *)&user, sizeof(TUserChunk));
            f.close();
        }
        else {
            cerr << "Datei " << USERFILE << " konnte nicht geschrieben werden!" << endl;
            return EXIT_FAILURE;
        }
    }
    {
        //Werte auslesen
        TUserChunk user;

        ifstream f;
        f.open(USERFILE, ifstream::in | ifstream::binary);

        if(f) {
            f.read((char *)&user, sizeof(TUserChunk));
            f.close();

            cout << "User " << user.getUsername() << endl;
            cout << "Mail " << user.getMailaddress() << endl;

            cout << "oder -> " << user << endl;
        }
        else {
            cerr << "Datei " << USERFILE << " konnte nicht geschrieben werden!" << endl;
            return EXIT_FAILURE;
        }
    }
    
    cout << "Ende" << endl;

    return EXIT_SUCCESS;
}
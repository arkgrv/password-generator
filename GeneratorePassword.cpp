//[アダムスカ-シャラシャスカ] Adamska-Shalansaska VII/X/MMXXI

#include "Functions.cpp" //functions.cpp

using namespace checking;
using namespace pass;
using namespace std;

int main(){
    ofstream ofs("password.txt"); //create a backup file
    Ascii v; //array of ASCII
    
    word passwd = ""; //the final passwd
    bool exit = false; //flag
    int length = 0; //length of passwd
    char e = 'n';

    srand(time(NULL));

    while (!exit) {
        try {
            cout << "Length? ----> ";
            do { cin >> length; } while ((length < minSize) || (length > maxSize));

            v = generation(length); //Generation of Ascii keys
            passwd = createPassword(v); //create the string

            if (testConditions(passwd)) backup(ofs, passwd); //true write in backup
            else continue; //skip to another iteration

            cout << "U wanna get out Y yes";
            cin >> e;
            if (e == 'Y') exit = true; //a stupid way to exit
        }catch (int& val) { cerr << exceptions(val) << endl; }
    }

    ofs.close();
    return 0;
}


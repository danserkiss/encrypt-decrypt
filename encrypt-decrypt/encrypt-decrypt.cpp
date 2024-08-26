#include "encrypt-decrypt.h"
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    string filename;
    string filetext;
    int offset = 5;
    int choise;

    while (true)
    {
        cout << "Enter:\n1.to encrypt file\n"
            << "2.to decrypt file\n"
            << "3.to read file\n"
            << "4.to exit\n";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "Enter file name to encrypt:" << endl;
            cin >> filename;
            filetext = encrypt(OpenAndReadFile(filename), offset);
            writeToFile(filename, filetext);
            cout << "File encrypted successfully.\n";
            break;

        case 2:
            cout << "Enter file name to decrypt:" << endl;
            cin >> filename;
            filetext = decrypt(OpenAndReadFile(filename), offset);
            writeToFile(filename, filetext);
            cout << "File decrypted successfully.\n";
            break;

        case 3:
            cout << "Enter file name to read:" << endl;
            cin >> filename;
            filetext = OpenAndReadFile(filename);
            cout << "File content:\n" << filetext << endl;
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

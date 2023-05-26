#include <iostream>
#include <fstream>
using namespace std;

void encryptFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string outputFilename = "encrypted_" + filename;
    ofstream outputFile(outputFilename);

    char ch;
    while (inputFile.get(ch)) {
        // Simple encryption algorithm: increment ASCII value by 1
        ch++;
        outputFile << ch;
    }

    inputFile.close();
    outputFile.close();

    cout << "File encrypted successfully. Encrypted file: " << outputFilename << endl;
}

void decryptFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string outputFilename = "decrypted_" + filename;
    ofstream outputFile(outputFilename);

    char ch;
    while (inputFile.get(ch)) {
        // Simple decryption algorithm: decrement ASCII value by 1
        ch--;
        outputFile << ch;
    }

    inputFile.close();
    outputFile.close();

    cout << "File decrypted successfully. Decrypted file: " << outputFilename << endl;
}

int main() {
    string filename;
    char choice;

    cout << "File Encryption/Decryption Program" << endl;
    cout << "---------------------------------" << endl;

    cout << "Enter the name of the file: ";
    getline(cin, filename);

    cout << "Select the operation: " << endl;
    cout << "1. Encrypt File" << endl;
    cout << "2. Decrypt File" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case '1':
            encryptFile(filename);
            break;
        case '2':
            decryptFile(filename);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    cout << "Goodbye!" << endl;

    return 0;
}


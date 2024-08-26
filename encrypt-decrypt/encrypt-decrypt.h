#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string encrypt(string input, int offset)
{
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int temp;
    for (int i = 0; i < input.length(); i++) {
        for (int k = 0; k < alphabet.length(); k++) {
            if (word[i] == alphabet[k]) {
                temp = (k + offset) % 26;
                word[i] = alphabet[temp];
                break;
            }
            else if (word[i] == alphabet_upper[k]) {
                temp = (k + offset) % 26;
                word[i] = alphabet_upper[temp];
                break;
            }
        }
    }
    string res(word.begin(), word.end());
    return res;
}

string decrypt(string input, int offset)
{
    return encrypt(input, 26 - offset);
}

string OpenAndReadFile(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error Opening File\n";
        exit(1);
    }
    stringstream buffer;
    buffer << inFile.rdbuf();  
    inFile.close();
    return buffer.str();
}

void writeToFile(const string& filename, const string& filetext)
{
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error Opening File\n";
        exit(1);
    }
    outFile << filetext;
    outFile.close();
}

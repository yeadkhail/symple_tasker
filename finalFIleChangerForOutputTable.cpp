#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

class FileProcessor {
public:
    FileProcessor(const string& inputFile1, const string& inputFile2, const string& outputFile)
        : inputFile1_(inputFile1), inputFile2_(inputFile2), outputFile_(outputFile) {}

    int processFiles() {
        ifstream file1(inputFile1_);
        ifstream file2(inputFile2_);
        ofstream outputFile(outputFile_);

        if (!file1.is_open() || !file2.is_open() || !outputFile.is_open()) {
            cout << "Unable to open one of the files." << endl;
            return 1;
        }

        string line1, line2;
        while (getline(file1, line1) && getline(file2, line2)) {
            string concat = line1 + " ~" + line2 + " ~";
            outputFile << concat << endl;
        }

        while (getline(file1, line1)) {
            string concat = line1 + " ~" + string(line1.length(), ' ') + " ~";
            outputFile << concat << endl;
        }

        while (getline(file2, line2)) {
            string concat = string(line2.length(), ' ') + " ~" + line2 + " ~";
            outputFile << concat << endl;
        }

        file1.close();
        file2.close();
        outputFile.close();

        return 0;
    }

private:
    string inputFile1_;
    string inputFile2_;
    string outputFile_;
};

int finalFileChangerForOutputTable() {
    FileProcessor processor1("d1.txt", "d2.txt", "d5.txt");
    processor1.processFiles();

    FileProcessor processor2("d3.txt", "d4.txt", "d6.txt");
    processor2.processFiles();

    return 0;
}

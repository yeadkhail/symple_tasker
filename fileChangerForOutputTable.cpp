#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
private:
    ifstream inputFile;
    ofstream outputFile;

public:
    FileProcessor(const string& inputFileName, const string& outputFileName) {
        inputFile.open(inputFileName);
        if (!inputFile) {
            cerr << "Failed to open the input file: " << inputFileName << endl;
            exit(1);
        }

        outputFile.open(outputFileName);
        if (!outputFile) {
            cerr << "Failed to create the output file: " << outputFileName << endl;
            exit(1);
        }
    }

    ~FileProcessor() {
        inputFile.close();
        outputFile.close();
    }

    void processFile() {
        string line;
        while (getline(inputFile, line)) {
            if (line.length() > 30) {
                string firstPart = line.substr(0, 29);
                string secondPart = line.substr(29);
                outputFile << firstPart << '-' << endl << secondPart << endl;
            } else {
                if (line.length() == 1)
                    outputFile << line << " " << endl;
                else {
                    outputFile << line << endl;
                }
            }
        }
    }
};

int fileChangerForOutputTable() {
    FileProcessor fileProcessor1("data1.txt", "d1.txt");
    fileProcessor1.processFile();

    FileProcessor fileProcessor2("data2.txt", "d2.txt");
    fileProcessor2.processFile();

    FileProcessor fileProcessor3("data3.txt", "d3.txt");
    fileProcessor3.processFile();

    FileProcessor fileProcessor4("data4.txt", "d4.txt");
    fileProcessor4.processFile();

    return 0;
}

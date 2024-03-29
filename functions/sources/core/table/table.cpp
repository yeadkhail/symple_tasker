//
// Created by yead on 9/18/23.
//

#include "../../../../headers/table.h"
#include "../../../../headers/PathManager.h"
#include "../../../../headers/Task.h"
using namespace std;
int max1=0;
int max2=0;
int c1=0;
int c2=0;
int c3=0;
int c4=0;
namespace core
{

    void table::modifyFilesForTable() {
        // Close and clear contents of existing files
        for (int i = 1; i <= 4; ++i) {
            string fileName = "data" + to_string(i) + ".txt";
            ofstream outputFile(fileName);

            if (outputFile.is_open()) {
                outputFile.close();
            } else {
                cerr << "Error creating/clearing the file " << fileName << ".\n";
            }
        }

        // Open files for writing
        ofstream outputFile11("data1.txt");
        ofstream outputFile12("data2.txt");
        ofstream outputFile13("data3.txt");
        ofstream outputFile14("data4.txt");

        // Check if files are successfully opened
        if (!outputFile11.is_open() || !outputFile12.is_open() || !outputFile13.is_open() || !outputFile14.is_open()) {
            cerr << "Error opening one or more output files.\n";
            return;
        }

        string taskfile = PathManager::gettaskfile();
        ifstream workfile(taskfile);

        if (!workfile.is_open()) {
            cerr << "Error opening the task file " << taskfile << ".\n";
            return;
        }

        string lineee;
        int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

        while (getline(workfile, lineee)) {
            core::Task mytask(lineee);
            std::string taskName = mytask.gettaskname();

            if (mytask.isUrgent() && mytask.isimportant()) {
                count1++;
                outputFile11 << count1 << ". " << taskName << std::endl;
            } else if (!mytask.isUrgent() && mytask.isimportant() && !mytask.isExpired()) {
                count2++;
                outputFile12 << count2 << ". " << taskName << std::endl;

            } else if (mytask.isUrgent() && !mytask.isimportant()) {
                count3++;
                outputFile13 << count3 << ". " << taskName << std::endl;

            } else if (!mytask.isUrgent() && !mytask.isimportant() && !mytask.isExpired()) {
                count4++;
                outputFile14 << count4 << ". " << taskName << std::endl;

            }
        }

        outputFile11.close();
        outputFile12.close();
        outputFile13.close();
        outputFile14.close();

    }


    void table::FilesForTable() {
        ifstream inputFile("data1.txt");

        if (!inputFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile("d1.txt");

        if (!outputFile) {
            cout << "Failed to create the output file." << endl;
            return;
        }
        c1 = 0;
        string line;
        while (getline(inputFile, line)) {
            if (line.length() > 30) {
                c1++;
                string firstPart = line.substr(0, 27);
                string secondPart = line.substr(27);
                if (secondPart.length() != 0) {
                    c1++;
                }
                outputFile << firstPart << '-' << endl
                           << secondPart << endl;
            } else {
                c1++;
                outputFile << line << endl;
            }
        }
        inputFile.close();
        outputFile.close();

        ifstream inputFile2("data2.txt");

        if (!inputFile2) {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile2("d2.txt");

        if (!outputFile2) {
            cout << "Failed to create the output file." << std::endl;
            return;
        }

        c2 = 0;
        while (getline(inputFile2, line)) {
            if (line.length() > 30) {
                c2++;
                string firstPart = line.substr(0, 27);

                string secondPart = line.substr(27);
                if (secondPart.length() != 0) {
                    c2++;
                }
                outputFile2 << firstPart << endl
                            << secondPart << endl;
            } else {
                c2++;
                outputFile2 << line << endl;
            }
        }

        inputFile2.close();
        outputFile2.close();

        ifstream inputFile3("data3.txt");

        if (!inputFile3) {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile3("d3.txt");

        if (!outputFile3) {
            cerr << "Failed to create the output file." << endl;
            return;
        }
        c3 = 0;
        while (getline(inputFile3, line)) {
            if (line.length() > 30) {
                c3++;
                string firstPart = line.substr(0, 27);
                string secondPart = line.substr(27);
                if (secondPart.length() != 0) {
                    c3++;
                }
                outputFile3 << firstPart << "-" << endl
                            << secondPart << " " << endl;
            } else {
                c3++;
                outputFile3 << line << endl;
            }
        }

        inputFile3.close();
        outputFile3.close();

        ifstream inputFile4("data4.txt");

        if (!inputFile4) {
            cerr << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile4("d4.txt");

        if (!outputFile4) {
            cerr << "Failed to create the output file." << endl;
            return;
        }
        c4 = 0;
        while (getline(inputFile4, line)) {
            if (line.length() > 30) {
                c4++;
                string firstPart = line.substr(0, 27);
                string secondPart = line.substr(27);
                if (secondPart.length() != 0) {
                    c4++;
                }
                outputFile4 << firstPart << '-' << endl
                            << secondPart << " " << endl;
            } else {
                c4++;
                outputFile4 << line << endl;
            }
        }

        inputFile4.close();
        outputFile4.close();
//        ofstream inFile1("d1.txt");
//        ofstream inFile2("d2.txt");
//        ofstream inFile3("d3.txt");
//        ofstream inFile4("d4.txt");
       max1 = max(c1, c2);
       max2 = max(c3, c4);
//        if (c1 < max1)
//        {
//            inFile1<<"   "<<endl;
//        }
//        else if (c2 < max1)
//        {
//            inFile2<<"   "<<endl;
//        }
//
//        if (c3 < max2)
//        {
//            inFile3<<"   "<<endl;
//        }
//       else if (c4 < max1)
//        {
//            inFile4<<"   "<<endl;
//        }
//
//
//
//    inFile1.close();
//    inFile2.close();
//    inFile3.close();
//    inFile4.close();





    };
//    void  table::fileChangerForOutputTable() {
//        ifstream inputFile("data1.txt");
//
//        if (!inputFile) {
//            cout << "Failed to open the file." << endl;
//            return ;
//        }
//
//        ofstream outputFile("d1.txt");
//
//        if (!outputFile) {
//            cout << "Failed to create the output file." << endl;
//            return ;
//        }
//
//        string line;
//        while (getline(inputFile, line)) {
//            if (line.length() > 30) {
//                string firstPart = line.substr(0, 29);
//                string secondPart = line.substr(29);
//                outputFile << firstPart << '-' << endl << secondPart << endl;
//            } else {
//                if (line.length() == 1)
//                    outputFile << line << " " << endl;
//                else {
//                    outputFile << line << endl;
//                }
//            }
//
//        }
//        inputFile.close();
//        outputFile.close();
//
//        ifstream inputFile2("data2.txt");
//
//        if (!inputFile2) {
//            std::cout << "Failed to open the file." << endl;
//            return ;
//        }
//
//        ofstream outputFile2("d2.txt");
//
//        if (!outputFile2) {
//            cout << "Failed to create the output file." << std::endl;
//            return ;
//        }
//
//
//        while (getline(inputFile2, line)) {
//            if (line.length() > 30) {
//                string firstPart = line.substr(0, 29);
//                string secondPart = line.substr(29);
//                outputFile2 << firstPart << endl << secondPart << endl;
//            } else {
//                if (line.length() == 1)
//                    outputFile2 << line << " " << endl;
//                else {
//                    outputFile2 << line << endl;
//                }
//            }
//        }
//
//
//        inputFile2.close();
//        outputFile2.close();
//
//        ifstream inputFile3("data3.txt");
//
//        if (!inputFile3) {
//            cout << "Failed to open the file." << endl;
//            return ;
//        }
//
//        ofstream outputFile3("d3.txt");
//
//        if (!outputFile3) {
//            cerr << "Failed to create the output file." << endl;
//            return ;
//        }
//
//
//        while (getline(inputFile3, line)) {
//            if (line.length() > 30) {
//                string firstPart = line.substr(0, 29);
//                string secondPart = line.substr(29);
//                outputFile3 << firstPart << "-" << endl << secondPart << " " << endl;
//            } else {
//                if (line.length() == 1)
//                    outputFile3 << line << " " << endl;
//                else {
//                    outputFile3 << line << endl;
//                }
//            }
//        }
////  outputFile3<<space<<endl;
////     outputFile3<<space<<endl;
//        inputFile3.close();
//        outputFile3.close();
//
//        ifstream inputFile4("data4.txt");
//
//        if (!inputFile4) {
//            cerr << "Failed to open the file." << endl;
//            return ;
//        }
//
//        ofstream outputFile4("d4.txt");
//
//        if (!outputFile4) {
//            cerr << "Failed to create the output file." << endl;
//            return ;
//        }
//
//
//        while (getline(inputFile4, line)) {
//            if (line.length() > 30) {
//                string firstPart = line.substr(0, 29);
//                string secondPart = line.substr(29);
//                outputFile4 << firstPart << '-' << endl << secondPart << " " << endl;
//            } else {
//                if (line.length() == 1)
//                    outputFile4 << line << " " << endl;
//                else {
//                    outputFile4 << line << endl;
//                }
//            }
//        }
////  outputFile4<<space<<endl;
////     outputFile4<<space<<endl;
//        inputFile4.close();
//        outputFile4.close();
//
//        return ;
//    }
    void table::finalFileChangerForOutputTable()
    {
        ifstream file1("d1.txt");
        ifstream file2("d2.txt");
        ofstream outputFile("d5.txt");

        if (!file1.is_open())
        {
            cout << "Unable to open d1.txt" << endl;
            return ;
        }

        if (!file2.is_open())
        {
            cout << "Unable to open d2.txt" << endl;
            return ;
        }

        if (!outputFile.is_open())
        {
            cout << "Unable to open d5.txt" << endl;
            return ;
        }

        string line1, line2;
        if(c1<max1) {
            while (getline(file1, line1) && getline(file2, line2)) {

                string concat = "";


                for (int i = 0; i < line1.length(); i++) {
                    concat += line1[i];
                }
                concat += " ~";

                for (int i = 0; i < line2.length(); i++) {
                    concat += line2[i];
                }
                concat += " ~";
                outputFile << concat << endl;

            }
        }
        else
        {
            while (getline(file2, line2) && getline(file1, line1)) {

                string concat = "";


                for (int i = 0; i < line1.length(); i++) {
                    concat += line1[i];
                }
                concat += " ~";

                for (int i = 0; i < line2.length(); i++) {
                    concat += line2[i];
                }
                concat += " ~";
                outputFile << concat << endl;

            }
        }

        while (getline(file1, line1))
        {
            string concat = "";


            for (int i = 0; i < line1.length() ; i++)
            {
                concat += line1[i];
            }
            concat += " ~";

            for (int i = 0; i < line1.length() ; i++)
            {
                concat += " ";
            }
            concat += " ~";
            outputFile << concat << endl;

        }



        while (getline(file2, line2))
        {

            string concat = "";
            for (int i = 0; i < line2.length() ; i++)
            {
                concat += " ";
            }
            concat += " ~";
            for (int i = 0; i < line2.length() ; i++)
            {
                concat += line2[i];
            }
            concat += " ~";
            outputFile << concat << endl;

        }
        file1.close();
        file2.close();
        outputFile.close();

        ifstream file3("d3.txt");
        ifstream file4("d4.txt");
        ofstream outputFile2("d6.txt");

        if (!file3.is_open())
        {
            cout << "Unable to open d3.txt" << endl;
            return ;
        }

        if (!file4.is_open())
        {
            cout << "Unable to open d4.txt" << endl;
            return ;
        }

        if (!outputFile2.is_open())
        {
            cout << "Unable to open d6.txt" << endl;
            return ;
        }

        string line3, line4;
        if(c3<max2) {
            while (getline(file3, line3) && getline(file4, line4)) {
                string concat = "";
                for (int i = 0; i < line3.length(); i++) {
                    concat += line3[i];
                }
                concat += '~';
                for (int i = 0; i < line4.length(); i++) {
                    concat += line4[i];
                }
                concat += '~';
                outputFile2 << concat << endl;
            }
        }
        else
        {
            while (getline(file4, line4) && getline(file3, line3)) {
                string concat = "";
                for (int i = 0; i < line3.length(); i++) {
                    concat += line3[i];
                }
                concat += '~';
                for (int i = 0; i < line4.length(); i++) {
                    concat += line4[i];
                }
                concat += '~';
                outputFile2 << concat << endl;
            }
        }
//        file3.clear();
//        file3.seekg(0);
//        file4.clear();
//        file4.seekg(0);
        while (getline(file3, line3))
        {
            int length1 = line3.length();
            string concat = "";

            for (int i = 0; i < line3.length() ; i++)
            {
                concat += line3[i];
            }
            concat += '~';
            for (int i = 0; i < line3.length() ; i++)
            {
                concat += " ";
            }
            concat += '~';
            outputFile2 << concat << endl;
        }

        while (getline(file4, line4))
        {
            int length1 = line4.length();
            string concat = "";
            for (int i = 0; i < line4.length(); i++)
            {
                concat += " ";
            }
            concat += '~';
            for (int i = 0; i < line4.length(); i++)
            {
                concat += line4[i];
            }
            concat += '~';
            outputFile2 << concat << endl;
        }

        file3.close();
        file4.close();
        outputFile2.close();

        return ;
    }



    void table::outputTable()
    {
        cout << string(86, '=') << endl;
        string line;
        cout << setw(20) << " "
             << "||" << left << setw(30) << "   URGENT"
             << "||" << left << setw(30)
             << "    NOT URGENT"
             << "||" << endl;
        cout << string(86, '=') << endl;

        ifstream fin, fin2;
        fin.open("d5.txt");

        if (!fin)
        {
            cout << "Error while opening file" << endl;
        }

        cout << setw(20) << left << "Important"
             << "||" << setw(30) << " "
             << "||" << setw(30) << " "
             << "||" << endl;
        string line1 = "";
        string space = "                    ";

        while (!fin.eof())
        {
            setvbuf(stdin, NULL, _IONBF, 0);
            getline(fin, line1);
            istringstream iss1(line1);
            string urg;
            string nurg;
            getline(iss1, urg, '~');
            getline(iss1, nurg, '~');
            cout << setw(20) << space << "||" << setw(30) << left << urg << "||" << setw(30) << nurg << left << "||"
                 << endl;
        }
        cout << string(86, '=') << endl;

        cout << setw(20) << left << "Not Important"
             << "||" << setw(30) << " "
             << "||" << setw(30) << " "
             << "||"
             << endl;
        fin2.open("d6.txt");
        string line2 = "";
        string space2 = "                    ";

        while (getline(fin2, line2))
        {
            setvbuf(stdin, NULL, _IONBF, 0);
            istringstream iss2(line2);
            string urg;
            string nurg;
            getline(iss2, urg, '~');
            getline(iss2, nurg, '~');
            cout << setw(20) << space2 << "||" << setw(30) << left << urg << "||" << setw(30) << nurg << left << "||"
                 << endl;
        }
        cout << string(86, '=') << endl;
        fin.close();
        fin2.close();



        remove("data1.txt");
        remove("data2.txt");
        remove("data3.txt");
        remove("data4.txt");
        remove("d1.txt");
        remove("d2.txt");
        remove("d3.txt");
        remove("d4.txt");
        remove("d5.txt");
        remove("d6.txt");





    }

    void table::showTable()
    {
        modifyFilesForTable();
        FilesForTable();
//        fileChangerForOutputTable();
        finalFileChangerForOutputTable();
        outputTable();


        return;
    }
} // core

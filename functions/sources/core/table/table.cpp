//
// Created by yead on 9/18/23.
//

#include "../../../../headers/table.h"
#include "../../../../headers/PathManager.h"
#include "../../../../headers/Task.h"
using namespace std;

namespace core
{
    void table::modifyFilesForTable()
    {
        // Close and clear contents of existing files
        for (int i = 1; i <= 4; ++i)
        {
            string fileName = "data" + to_string(i) + ".txt";
            ofstream outputFile(fileName);

            if (outputFile.is_open())
            {
                outputFile.close();
            }
            else
            {
                cerr << "Error creating/clearing the file " << fileName << ".\n";
            }
        }

        // Open files for writing
        ofstream outputFile11("data1.txt");
        ofstream outputFile12("data2.txt");
        ofstream outputFile13("data3.txt");
        ofstream outputFile14("data4.txt");

        // Check if files are successfully opened
        if (!outputFile11.is_open() || !outputFile12.is_open() || !outputFile13.is_open() || !outputFile14.is_open())
        {
            cerr << "Error opening one or more output files.\n";
            return;
        }

        string taskfile = PathManager::gettaskfile();
        ifstream workfile(taskfile);

        if (!workfile.is_open())
        {
            cerr << "Error opening the task file " << taskfile << ".\n";
            return;
        }

        string lineee;
        int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

        while (getline(workfile, lineee))
        {
            core::Task mytask(lineee);
            std::string taskName = mytask.gettaskname();

            if (mytask.isUrgent() && mytask.isimportant() &&
            !mytask.isExpired())
            {
                count1++;
                outputFile11 << count1 << ". " << taskName << std::endl;
            }
            else if (!mytask.isUrgent() && mytask.isimportant() && !mytask.isExpired())
            {
                count2++;
                outputFile12 << count2 << ". " << taskName << std::endl;
            }
            else if (mytask.isUrgent() && !mytask.isimportant() && !mytask.isExpired())
            {
                count3++;
                outputFile13 << count3 << ". " << taskName << std::endl;
            }
            else if (!mytask.isUrgent() && !mytask.isimportant() && !mytask.isExpired())
            {
                count4++;
                outputFile14 << count4 << ". " << taskName << std::endl;
            }
        }
    }


    void table::FilesForTable()
    {
        ifstream inputFile("data1.txt");

        if (!inputFile)
        {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile("d1.txt");

        if (!outputFile)
        {
            cout << "Failed to create the output file." << endl;
            return;
        }

        string line;
        while (getline(inputFile, line))
        {
            if (line.length() > 30)
            {
                string firstPart = line.substr(0, 29);
                string secondPart = line.substr(29);
                outputFile << firstPart << '-' << endl
                           << secondPart << endl;
            }
            else
            {
                outputFile << line << endl;
            }
        }
        inputFile.close();
        outputFile.close();

        ifstream inputFile2("data2.txt");

        if (!inputFile2)
        {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile2("d2.txt");

        if (!outputFile2)
        {
            cout << "Failed to create the output file." << std::endl;
            return;
        }

        while (getline(inputFile2, line))
        {
            if (line.length() > 30)
            {
                string firstPart = line.substr(0, 29);
                string secondPart = line.substr(29);
                outputFile2 << firstPart << endl
                            << secondPart << endl;
            }
            else
            {

                outputFile2 << line << endl;
            }
        }

        inputFile2.close();
        outputFile2.close();

        ifstream inputFile3("data3.txt");

        if (!inputFile3)
        {
            cout << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile3("d3.txt");

        if (!outputFile3)
        {
            cerr << "Failed to create the output file." << endl;
            return;
        }

        while (getline(inputFile3, line))
        {
            if (line.length() > 30)
            {
                string firstPart = line.substr(0, 29);
                string secondPart = line.substr(29);
                outputFile3 << firstPart << "-" << endl
                            << secondPart << " " << endl;
            }
            else
            {

                outputFile3 << line << endl;
            }
        }

        inputFile3.close();
        outputFile3.close();

        ifstream inputFile4("data4.txt");

        if (!inputFile4)
        {
            cerr << "Failed to open the file." << endl;
            return;
        }

        ofstream outputFile4("d4.txt");

        if (!outputFile4)
        {
            cerr << "Failed to create the output file." << endl;
            return;
        }

        while (getline(inputFile4, line))
        {
            if (line.length() > 30)
            {
                string firstPart = line.substr(0, 29);
                string secondPart = line.substr(29);
                outputFile4 << firstPart << '-' << endl
                            << secondPart << " " << endl;
            }
            else
            {
                outputFile4 << line << endl;
            }
        }

        inputFile4.close();
        outputFile4.close();

        return;
    }

    void table::fileChangerForOutputTable()
    {
        return;
    }

    void table::finalFileChangerForOutputTable()
    {

        ifstream file1("d1.txt");
        ifstream file2("d2.txt");
        ofstream outputFile("d5.txt");

        if (!file1.is_open())
        {
            cout << "Unable to open d1.txt" << endl;
            return;
        }

        if (!file2.is_open())
        {
            cout << "Unable to open d2.txt" << endl;
            return;
        }

        if (!outputFile.is_open())
        {
            cout << "Unable to open d5.txt" << endl;
            return;
        }

        string line1, line2;
        while ((getline(file1, line1)) && getline(file2, line2))
        {
            string concat = "";
            for (int i = 0; i < line1.length(); i++)
            {
                concat += line1[i];
            }
            concat += " ~";

            for (int i = 0; i < line2.length(); i++)
            {
                concat += line2[i];
            }
            concat += " ~";
            outputFile << concat << endl;
        }

        while (getline(file1, line1))
        {
            string concat = "";

            for (int i = 0; i < line1.length(); i++)
            {
                concat += line1[i];
            }
            concat += " ~";

            for (int i = 0; i < line1.length(); i++)
            {
                concat += " ";
            }
            concat += " ~";
            outputFile << concat << endl;
        }

        while (getline(file2, line2))
        {

            string concat = "";
            for (int i = 0; i < line2.length(); i++)
            {
                concat += " ";
            }
            concat += " ~";
            for (int i = 0; i < line2.length(); i++)
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
            return;
        }

        if (!file4.is_open())
        {
            cout << "Unable to open d4.txt" << endl;
            return;
        }

        if (!outputFile2.is_open())
        {
            cout << "Unable to open d6.txt" << endl;
            return;
        }

        string line3, line4;

        while (getline(file3, line3) && getline(file4, line4))
        {
            string concat = "";
            for (int i = 0; i < line3.length(); i++)
            {
                concat += line3[i];
            }
            concat += '~';
            for (int i = 0; i < line4.length(); i++)
            {
                concat += line4[i];
            }
            concat += '~';
            outputFile2 << concat << endl;
        }
        while (getline(file3, line3))
        {
            int length1 = line3.length();
            string concat = "";

            for (int i = 0; i < line3.length(); i++)
            {
                concat += line3[i];
            }
            concat += '~';
            for (int i = 0; i < line3.length(); i++)
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

        return;
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
        return;
    }
    void table::deleteFiles()
    {
        for (int i = 1; i <= 4; ++i) {
            std::string fileName = "data" + std::to_string(i) + ".txt";
            if (std::remove(fileName.c_str()) == 0) {
                continue;
            } else {
                std::cerr << "Error deleting the file " << fileName << ".\n";
            }
        }
    }
    void table::showTable()
    {
        modifyFilesForTable();
        FilesForTable();
        fileChangerForOutputTable();
        finalFileChangerForOutputTable();
        outputTable();
        deleteFiles();
        return;
    }
} // core

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Task {
public:
    string important;
    string not_urgent;

    Task(string imp, string n_imp) : important(imp), not_urgent(n_imp) {}

    void displayTask(int width) {
        cout << setw(width) << "Important" << "||" << setw(30) << important << "||" << setw(30) << not_urgent << "||" << endl;
    }
};

class TaskList {
private:
    string title;
    vector<Task> tasks;

public:
    TaskList(const string& listTitle) : title(listTitle) {}

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void displayList() {
        cout << string(86, '=') << endl;
        cout << setw(20) << title << "||" << left << setw(30) << "URGENT" << "||" << left << setw(30) << "NOT URGENT" << "||" << endl;
        cout << string(86, '=') << endl;

        for (const Task& task : tasks) {
            cout << setw(20) << " " << "||";
            task.displayTask(30);
        }

        cout << string(86, '=') << endl;
    }
};

int outputTable() {
    TaskList urgentList("URGENT");
    TaskList notUrgentList("NOT URGENT");

    ifstream fin("d5.txt");
    ifstream fin2("d6.txt");

    if (!fin || !fin2) {
        cout << "Error while opening file" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string urg, nurg;
        getline(iss, urg, '~');
        getline(iss, nurg, '~');
        Task task(urg, nurg);
        urgentList.addTask(task);
    }

    while (getline(fin2, line)) {
        istringstream iss(line);
        string urg, nurg;
        getline(iss, urg, '~');
        getline(iss, nurg, '~');
        Task task(urg, nurg);
        notUrgentList.addTask(task);
    }

    fin.close();
    fin2.close();

    urgentList.displayList();
    notUrgentList.displayList();

    return 0;
}

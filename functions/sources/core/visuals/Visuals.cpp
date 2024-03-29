//
// Created by yead on 9/16/23.
//

#include "../../../../headers/Visuals.h"
#include<iostream>
using namespace std;
namespace core {
    void Visuals::title()
    {
        using namespace std;
        cout<<"    ███████╗██╗   ██╗███╗   ███╗    ████████╗ █████╗ ███████╗██╗  ██╗███████╗██████╗ "<<endl;
        cout<<"    ██╔════╝╚██╗ ██╔╝████╗ ████║    ╚══██╔══╝██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗"<<endl;
        cout<<"    ███████╗ ╚████╔╝ ██╔████╔██║       ██║   ███████║███████╗█████╔╝ █████╗  ██████╔╝"<< endl;
        cout<<"    ╚════██║  ╚██╔╝  ██║╚██╔╝██║       ██║   ██╔══██║╚════██║██╔═██╗ ██╔══╝  ██╔══██╗"<<endl;
        cout<<"    ███████║   ██║   ██║ ╚═╝ ██║       ██║   ██║  ██║███████║██║  ██╗███████╗██║  ██║"<<endl;
        cout<<"    ╚══════╝   ╚═╝   ╚═╝     ╚═╝       ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"<<endl;
    }
    void Visuals::motivation()
    {
        using namespace std;
        string quotes[] = {
                "\"Success is not final, failure is not fatal: It is the courage to continue that counts.\" - Winston Churchill",
                "\"Believe you can and you're halfway there.\" - Theodore Roosevelt",
                "\"The only way to do great work is to love what you do.\" - Steve Jobs",
                "\"Don't watch the clock; do what it does. Keep going.\" - Sam Levenson",
                "\"Success is walking from failure to failure with no loss of enthusiasm.\" - Winston Churchill",
                "\"The future belongs to those who believe in the beauty of their dreams.\" - Eleanor Roosevelt",
                "\"The only limit to our realization of tomorrow will be our doubts of today.\" - Franklin D. Roosevelt",
                "\"Success usually comes to those who are too busy to be looking for it.\" - Henry David Thoreau",
                "\"The best way to predict the future is to create it.\" - Peter Drucker",
                "\"The secret to getting ahead is getting started.\" - Mark Twain",
                "\"Don't be pushed around by the fears in your mind. Be led by the dreams in your heart.\" - Roy T. Bennett",
                "\"Your time is limited, don't waste it living someone else's life.\" - Steve Jobs",
                "\"Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.\" - Christian D. Larson",
                "\"The harder you work for something, the greater you'll feel when you achieve it.\" - Unknown",
                "\"Success is not in what you have, but who you are.\" - Bo Bennett",
                "\"It does not matter how slowly you go as long as you do not stop.\" - Confucius",
                "\"Success is not the key to happiness. Happiness is the key to success. If you love what you are doing, you will be successful.\" - Albert Schweitzer",
                "\"Don't be afraid to give up the good to go for the great.\" - John D. Rockefeller",
                "\"The only place where success comes before work is in the dictionary.\" - Vidal Sassoon",
                "\"The future depends on what you do today.\" - Mahatma Gandhi",
                "\"Success is not just about making money. It's about making a difference.\" - Unknown",
                "\"The road to success and the road to failure are almost exactly the same.\" - Colin R. Davis",
                "\"The only person you should try to be better than is the person you were yesterday.\" - Unknown",
                "\"Don't count the days, make the days count.\" - Muhammad Ali",
                "\"Success is not for the lazy.\" - Unknown",
                "\"The only limit to our realization of tomorrow will be our doubts of today.\" - Franklin D. Roosevelt",
                "\"Success is the sum of small efforts, repeated day in and day out.\" - Robert Collier",
                "\"Success is not the key to happiness. Happiness is the key to success. If you love what you are doing, you will be successful.\" - Albert Schweitzer",
                "\"The only way to do great work is to love what you do.\" - Steve Jobs",
                "\"Success usually comes to those who are too busy to be looking for it.\" - Henry David Thoreau",
                "\"The secret of success is to know something nobody else knows.\" - Aristotle Onassis",
                "\"The harder you work for something, the greater you'll feel when you achieve it.\" - Unknown",
                "\"Success is not in what you have, but who you are.\" - Bo Bennett",
                "\"Believe you can and you're halfway there.\" - Theodore Roosevelt",
                "\"The only place where success comes before work is in the dictionary.\" - Vidal Sassoon",
                "\"Success is not final, failure is not fatal: It is the courage to continue that counts.\" - Winston Churchill",
                "\"The future belongs to those who believe in the beauty of their dreams.\" - Eleanor Roosevelt",
                "\"Don't watch the clock; do what it does. Keep going.\" - Sam Levenson",
                "\"The best way to predict the future is to create it.\" - Peter Drucker",
                "\"The only limit to our realization of tomorrow will be our doubts of today.\" - Franklin D. Roosevelt",
                "\"Success usually comes to those who are too busy to be looking for it.\" - Henry David Thoreau",
                "\"The secret to getting ahead is getting started.\" - Mark Twain",
                "\"Don't be pushed around by the fears in your mind. Be led by the dreams in your heart.\" - Roy T. Bennett",
                "\"Your time is limited, don't waste it living someone else's life.\" - Steve Jobs",
                "\"Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.\" - Christian D. Larson",
                "\"The harder you work for something, the greater you'll feel when you achieve it.\" - Unknown"
        };

        srand(time(nullptr));
        int index = rand() % 49;
        cout << quotes[index] << endl;
        return;
    }
    void Visuals::showintro()
    {
        title();
        std::cout<<std::endl << "                  ";
        motivation();
    }
    void Visuals::showhelp()
    {
        using namespace std;
        cout<<"SYMPLE TASKER"<<endl;
        cout<<"A simple task manager for your daily tasks\n"<<endl;
        cout<<"Usage: sym [command] [arguments]\n\n";
        cout<<"sym --history(command: history): See history of tasks to edit\n";
        cout<<"sym --version: Shows the version of the application\n";
        cout<<"sym --randomizer: Allows the user to play a randomizer game\n\n";
        cout << "Available commands:\n";
        cout << "insert: Insert a task\n";
        cout << "delete-task: Delete a task\n";
        cout << "update-task: Update a task\n";
        cout << "help: Show this help\n";
        cout << "version: Show version\n";
        cout << "randomizer: Play a randomizer game\n";
        cout << "insert-tag: Insert a tag\n";
        cout << "edit-tag: Edit a tag\n";
        cout << "delete-tag: Delete a tag\n";
        cout << "search-tagwise: Search tagwise\n";
        cout << "exit: Exit\n";
        cout << "clear: Clear screen\n";
        cout << "history: Show history\n";
        cout << "show-attachment: Show attachment\n";
        cout << "show-expired: Show expired tasks\n";
        cout << "show-table : Show the table again\n";
    }
    void Visuals::showversion()
    {
        using namespace std;
        cout<<"sym tasker "<<"(Symple Utilities) "<<"v0.0.1"<<endl;
        cout<<"Copyright (C) 2024 Team Symple"<<endl;
        cout<<"License GPLv3+: GNU version 3 or later <https://gnu.org/licences/gpl.html>."<<endl<<"This is a free software: You are free to change and redestribute it."<<endl;
        cout<<"There is NO WARRANTY, to the extent permitted by law."<<endl<<endl;
        cout<<"Written by Md Yead Khail Shovo, Zawad Bin Shoukat Tasin , Md Abdul Muqtadir and Faheem Rahman."<<endl;
    }

    void Visuals::randomiser() {
        setvbuf(stdin, NULL, _IONBF, 0);  // Disable input buffering
        char *line = NULL;
        size_t len = 0;
        string question;
        string ans;

        cout << "Enter Your Question: ";
        getline(cin, question);

        cout << "Press 'd' for default answers or press any key for your own answers: ";
        cin >> ans;

        if (ans == "d") {
            srand(time(NULL));
            while (true) {
                cout << question << endl;
                if (rand() % 2) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                char ch;
                cout << "Do you want to play again? (y/n) ";
                cin >> ch;
                if (ch == 'n') {
                    break;
                } else if (ch != 'y') {
                    cout << "Wrong input" << endl;
                    break;
                }
            }
        } else {
            cin.ignore();
            string ans1, ans2;

            cout << "Input your first answer: ";
            getline(cin, ans1);

            cout << "Input your second answer: ";
            getline(cin, ans2);

            srand(time(NULL));
            while (true) {
                if (rand() % 2) {
                    cout << ans1 << endl;
                } else {
                    cout << ans2 << endl;
                }
                char ch;
                cout << "Do you want to play again? (y/n) ";
                cin >> ch;
                if (ch == 'n') {
                    break;
                } else if (ch != 'y') {
                    cout << "Wrong input" << endl;
                    break;
                }
            }
        }
    }
    void Visuals::showporfile() {
        using namespace std;
        core::PathManager path;
        ifstream profile;
        profile.open(path.getprofilefile());
        if (!profile.is_open()) {
            cerr << "Error while opening file" << endl;
            return;
        }
        string line;
        while (getline(profile, line)) {
            cout << line << endl;
        }
        return;
    }

} // core
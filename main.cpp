#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

using namespace std;


class Account {
private:
    int accountnumber;
    string name;
    string surname;
    float balance;

public:
    Account() {}

    Account(int accountnumber, string name, string surname, float balance) {
        this->accountnumber = accountnumber;
        this->name = name;
        this->surname = surname;
        this->balance = balance;
    }

    void addAccount () {

        fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);

        cout << "Account number: ";
        cin >> accountnumber;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Balance: ";
        cin >> balance;

        record << setw(10) << accountnumber << setw(10) << name << setw(10) << surname << setw(10) << balance << endl;

        system("PAUSE");
    }

    void showAllAccount() {

        fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);

        while(record >> accountnumber >> name >> surname >> balance) {
            cout << "Account number: " << accountnumber << endl;
            cout << "Name: " << name << endl;
            cout << "Surname: " << surname << endl;
            cout << "Balance: " << balance << endl << endl;
        }

        system("PAUSE");
    }

    void SearchandShowAccount() {

        fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);

        string searchname, searchsurname;

        cout << "Please enter you name: ";
        cin >> searchname;
        cout << "Please enter you surname: ";
        cin >> searchsurname;

        while(record >> accountnumber >> name >> surname >> balance) {
            if(name == searchname && surname == searchsurname) {
                cout << "Account number: " << accountnumber << endl;
                cout << "Name: " << name << endl;
                cout << "Surname: " << surname << endl;
                cout << "Balance: " << balance << endl << endl;
            }
        }

        system("PAUSE");
    }

    void updateAccount() {

        fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);

        int newaccountnumber;

        ofstream newrecord("temp.txt", std::fstream::app);
        cout << "Please enter your account number: ";
        cin >> newaccountnumber;

        while(record >> accountnumber >> name >> surname >> balance) {
            if(accountnumber == newaccountnumber)
            {
                cout << "Account number: " << accountnumber << endl;
                cout << "Name: " << name << endl;
                cout << "Surname: " << surname << endl;
                cout << "Balance: " << balance << endl << endl;

                int choice2, money;
                cout << "Do you wanna add money(1) or take money(2): ";
                cin >> choice2;

                if(choice2 == 1) {
                    cout << "How much money would you like to add: ";
                    cin >> money;

                    balance += money;
                    cout << "Account number: " << accountnumber << endl;
                    cout << "Name: " << name << endl;
                    cout << "Surname: " << surname << endl;
                    cout << "Balance: " << balance << endl << endl;
                }
                else if(choice2 == 2) {
                    cout << "How much money would you like to take: ";
                    cin >> money;

                    balance -= money;
                    cout << "Account number: " << accountnumber << endl;
                    cout << "Name: " << name << endl;
                    cout << "Surname: " << surname << endl;
                    cout << "Balance: " << balance << endl << endl;
                }
            }
            newrecord << setw(10) << accountnumber << setw(10) << name << setw(10) << surname << setw(10) << balance << endl;
        }
        record.close();
        newrecord.close();
        remove("record.txt");
        rename("temp.txt", "record.txt");
        system("PAUSE");
    }

    void deleteAccount() {

        fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);
        ofstream newrecord("temp.txt", std::fstream::app);

        int newaccountnumber;

        cout << "Please enter your account number: ";
        cin >> newaccountnumber;

        while(record >> accountnumber >> name >> surname >> balance) {
            if(accountnumber != newaccountnumber) {
                newrecord << setw(10) << accountnumber << setw(10) << name << setw(10) << surname << setw(10) << balance << endl;
            }
        }

        record.close();
        newrecord.close();
        remove("record.txt");
        rename("temp.txt", "record.txt");
        system("PAUSE");
    }
};

int main()
{
    int choice;
    Account customer;

    start:
    system("CLS");

    cout << "Account Information System" << endl;
    cout << "Select one option blow" <<endl;
    cout << setw(10) << "1-->" << "Add record to file" << endl;
    cout << setw(10) << "2-->" << "Show record to file" << endl;
    cout << setw(10) << "3-->" << "Search record to file" << endl;
    cout << setw(10) << "4-->" << "Update record" << endl;
    cout << setw(10) << "5-->" << "Delete record" << endl;
    cout << setw(10) << "6-->" << "Quit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: customer.addAccount(); goto start; break;
        case 2: customer.showAllAccount(); goto start; break;
        case 3: customer.SearchandShowAccount(); goto start; break;
        case 4: customer.updateAccount(); goto start; break;
        case 5: customer.deleteAccount(); goto start; break;
        case 6: break;
        default: cout << "Wrong choice!!" << endl; goto start;
    }
    return 0;
}

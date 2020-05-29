#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

fstream record("record.txt", std::fstream::in |std::fstream::out | std::fstream::app);

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
        cout << "Account number: ";
        cin >> accountnumber;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Balance: ";
        cin >> balance;

        record << setw(10) << accountnumber << setw(10) << name << setw(10) << surname << setw(10) << balance << endl;
    }

    void showAllAccount() {
        while(record >> accountnumber >> name >> surname >> balance) {
            cout << "Account number: " << accountnumber << endl;
            cout << "Name: " << name << endl;
            cout << "Surname: " << surname << endl;
            cout << "Balance: " << balance << endl << endl;
        }
    }

    void SearchandShowAccount() {
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
    }
};

int main()
{
    int choice;
    Account customer;

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
        case 1: customer.addAccount();
        case 2: customer.showAllAccount();
        case 3: customer.SearchandShowAccount();
        case 4: break;
        case 5: break;
        case 6: break;
        default: cout << "Wrong choice!!" << endl;
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <stdlib.h>
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

    string randomnames[10] = {"Tony", "Chris", "Tyler", "Bill", "Steve", "Shirlee", "Sarah", "Rose", "Lilly", "Candy"};
    string randomsurnames[5] = {"Stark", "Pratt", "Phillips", "Gates", "Jobs"};




    void addAccount () {
        int randomaccountnumber = rand() % 9999 + 1000;
        int ramdomnamenumber = rand() % 10;
        int ramdomsurnamenumber = rand() % 5;
        int randombalancenumber = rand() % 5000;
        accountnumber = randomaccountnumber;
        name = randomnames[ramdomnamenumber];
        surname = randomsurnames[ramdomsurnamenumber];
        balance = randombalancenumber;

        record << setw(10) << accountnumber << setw(10) << name << setw(10) << surname << setw(10) << balance << endl;
    }
};




int main()
{
    int i = 0;
    Account customer;

    while(i<50) {
        customer.addAccount();
        i++;
    }


    return 0;
}

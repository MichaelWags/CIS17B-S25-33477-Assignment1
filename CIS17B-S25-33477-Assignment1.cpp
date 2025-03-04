#include <iostream>
using namespace std;

class BankAccount {
    private:
        string accountHolderName;
        int accountNumber;
        double balance;
    public:
        BankAccount(string name, double bal){
            accountHolderName = name;
            balance = bal;
        };

        void deposit(double amount){
            balance += amount;
        };

        void withdraw(double amount){
            if (balance < amount){
                cout << "Insufficient funds!" << endl;
            }
            else if (balance >= amount){
                balance -= amount;
            }
        };

        void getBalance(){
            cout << "\nYour balance is: $" << balance << endl;
        };
};

int main() {
    double amount;
    int choice=0;
    double bal;
    string name;
    
    while(choice != 1){
        //No Account User Menu
        cout << "\nWhat Would you like to do?" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        
        if(choice == 1){
            //account creation
            cout << "Input your name: ";
            cin >> name;
            
            cout << "Input your starting balance: ";
            cin >> bal;
            
        }
        else if(choice == 5){
            return 0;
        }
        else{
            cout << "You must first create an account" << endl;
        }
    }
    
    //Use collected info for account
    BankAccount myAccount(name, bal);
    
    while(choice != 4){
        //User Menu
        cout << "\nWhat Would you like to do?" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                //run deposit member function
                cout << "\nHow much would you like to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                //run withdraw member function
                cout << "\nHow much would you like to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                //run get balance member function
                myAccount.getBalance();
                break;
            case 4:
                cout << "Thanks for using the program!";
                return 0;
        }
    }
}

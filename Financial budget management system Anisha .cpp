#include <iostream>
#include <string>

using namespace std;

struct Transaction {
    string type; 
    string category;
    double amount;
};

const int MAX_TRANSACTIONS = 100; 
Transaction records[MAX_TRANSACTIONS];
int recordCount = 0;
double totalIncome = 0, totalExpense = 0;
double financialGoal = 0;
string username, password;

void login() {
    string inputUser, inputPass;
    cout << "Set Username: ";
    cin >> username;
    cout << "Set Password: ";
    cin >> password;
    cout << "\nLogin Now" << endl;
    do {
        cout << "Enter Username: ";
        cin >> inputUser;
        cout << "Enter Password: ";
        cin >> inputPass;
        if (inputUser != username || inputPass != password)
            cout << "Incorrect credentials. Try again!\n";
    } while (inputUser != username || inputPass != password);
    cout << "Login successful!\n";
}

void addTransaction(string type) {
    if (recordCount >= MAX_TRANSACTIONS) {
        cout << "Transaction limit reached!\n";
        return;
    }
    records[recordCount].type = type;
    cout << "Enter category: ";
    cin >> records[recordCount].category;
    cout << "Enter amount: ";
    cin >> records[recordCount].amount;

    if (type == "Income")
        totalIncome += records[recordCount].amount;
    else
        totalExpense += records[recordCount].amount;

    recordCount++;
    cout << "Transaction recorded successfully!\n";
}

void setFinancialGoal() {
    cout << "Enter financial goal amount: ";
    cin >> financialGoal;
    cout << "Financial goal set successfully!\n";
}

void generateReport() {
    cout << "\n--- Financial Report ---\n";
    cout << "Total Income: " << totalIncome << endl;
    cout << "Total Expense: " << totalExpense << endl;
    cout << "Net Savings: " << totalIncome - totalExpense << endl;
    if (financialGoal > 0)
        cout << "Goal Remaining: " << financialGoal - (totalIncome - totalExpense) << endl;
}

int main() {
    login();
    int choice;
    do {
        cout << "\n1. Add Income\n2. Add Expense\n3. Set Financial Goal\n4. Generate Report\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: addTransaction("Income"); break;
        case 2: addTransaction("Expense"); break;
        case 3: setFinancialGoal(); break;
        case 4: generateReport(); break;
        case 5: cout << "Exiting..."; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
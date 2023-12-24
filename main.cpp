#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void ATM();
void new_account();
int account_num_creation();
void print(string text);
void format_on();
void format_out_on();
void format_off();
int check_int_input(int min, int max);
int check_passcode();
void print_error(string text);

// Account structure
struct Account {
    string name;
    string type;
    int acc_number;
    int password;
    int balance;
};

// Additional function prototypes
void performTransaction(Account &account);
void performWithdrawal(Account &account);
void performDeposit(Account &account);
void performFundTransfer(Account &sourceAccount);
void printAccountInfo(const Account &account);

// Global variables
vector<Account> accounts_vector;
int choice;
int num;
int pass;
int x = 1;
string type;
string cancel;

// Main function for the program. Prints a welcome message and prompts the user
// for a choice
/**
 * @brief Main function of the program. Prints welcome message and prompts user
 * for choice. Calls new_account () or ATM () depending on user choice.
 * @return Exit code ( 0 means success non - zero means failure ). In case of
 * error the program exits
 */
int main() {
    // This method is called by the user to ask for a new bank account or ATM
    while (true) {
        print("Welcome to our bank\n"
              "You have two choices: \n"
              "(1) NEW BANK ACCOUNT \n"
              "(2) ATM \n"
              "Type 1 or 2: ");
        choice = check_int_input(1, 2);

        // User choices
        // if choice 1 new_account new_account ATM
        if (choice == 1) {
            new_account();
            // If choice is 2 ATM is the choice 2
        } else if (choice == 2) {
            ATM();
        }
    }
    return 0;
}

// Account number creation function
/**
 * @brief Returns the number of accounts that have been created. This is used to
 * determine how many accounts will be created in the case of an error or when a
 * user tries to create more than one account at a time.
 * @return The number of accounts that have been created or - 1 if there are no
 * accounts in the account vector
 */
int account_num_creation() { return accounts_vector.size() + 1; }

// New account creation function
/**
 * @brief Create a new account in the database and add it to the
 * accounts_vector. This is a function that should be called every time the user
 * enters an account
 */
void new_account() {
    Account account;
    print("Welcome\n"
          "Enter your name: ");
    cin >> account.name;
    cout << endl;
    print("Create your password: ");
    account.password = check_passcode();
    cout << endl;
    print("Enter your balance: ");
    account.balance = check_int_input(0, 100000000);
    cout << endl;

    // Set account type to GOLD or SILVER
    account.type = (account.balance >= 1000000) ? "GOLD" : "SILVER";

    account.acc_number = account_num_creation();
    accounts_vector.push_back(account);

    format_on();
    print("Your account is created successfully\n");
    print("Your account number is ");
    format_out_on();
    cout << account.acc_number << endl;
    print("Your account type is ");
    format_out_on();
    cout << account.type << endl;
    print("Your balance is $");
    format_out_on();
    cout << account.balance << endl;
    cout << endl;
    format_off();
}

// ATM function
/**
 * @brief \ brief ATM for this program \ author Sascha Kevin Olivier Cou
 */
void ATM() {
    print("Welcome to the ATM\n"
          "Enter your account number: ");

    int accountNumber = check_int_input(1, 100);
    cout << endl;

    auto accountIterator =
        find_if(accounts_vector.begin(), accounts_vector.end(),
                [accountNumber](const Account &account) {
                    return accountNumber == account.acc_number;
                });

    // Perform a transaction on the account iterator.
    if (accountIterator == accounts_vector.end()) {
        print_error("Invalid account number\n"
                    "Please try again later\n\n\n");
    } else {
        int attempts = 3;
        // This method is used to perform a transaction.
        while (attempts > 0) {
            print("Please enter your PIN number: ");
            int enteredPin = check_int_input(0, 10000);
            cout << endl;

            // Perform a transaction if the user entered the PIN.
            if (enteredPin == accountIterator->password) {
                performTransaction(*accountIterator);
                break;
            } else {
                print("Incorrect PIN. You have ");
                format_out_on();
                cout << attempts - 1;
                print(" attempts left.\n");
                attempts--;
            }
        }

        // Prints a message if there are no more attempts.
        if (attempts == 0) {
            print("Too many incorrect attempts. Exiting...\n");
        }
    }
}

// Additional functions for transaction handling
/**
 * @brief Performs the transaction and prompts the user to choose. This is a
 * blocking function. It returns when the user confirms or exits
 * @param account Reference to the account
 */
void performTransaction(Account &account) {
    print("Login successful!\n");
    printAccountInfo(account);

    // Choose the action 1 Cash Withdrawal 2 Deposit 3 Fund Transfer 4 Exit
    while (true) {
        print("Choose the action:\n"
              "(1) Cash Withdrawal\n"
              "(2) Deposit\n"
              "(3) Fund Transfer\n"
              "(4) Exit\n"
              "Enter your choice: ");

        int choice = check_int_input(1, 4);
        cout << endl;

        // Perform the action based on the choice.
        switch (choice) {
        case 1:
            performWithdrawal(account);
            break;
        case 2:
            performDeposit(account);
            break;
        case 3:
            performFundTransfer(account);
            break;
        case 4:
            print("Exiting...\n");
            return;
        default:
            print_error("Invalid choice. Please try again.\n");
        }
    }
}

/**
 * @brief Withdraws funds from the account. This function is called by the
 * program when the user presses the withdraw button.
 * @param account Reference to the account to withdraw from. This is passed by
 * reference
 */
void performWithdrawal(Account &account) {
    print("Enter the amount to withdraw: ");
    double withdrawalAmount = check_int_input(0, account.balance);
    cout << endl;

    // Withdrawal is successful and the account is withdrawal.
    if (withdrawalAmount <= account.balance) {
        account.balance -= withdrawalAmount;
        format_on();
        print("Withdrawal successful. Updated balance: $");
        format_out_on();
        cout << account.balance << "\n";
        format_off();
    } else {
        print("Insufficient funds. Withdrawal canceled.\n");
    }
}

/**
 * @brief Performs deposit and updates the balance. This is a function that
 * takes an account as an argument and calls the function to do the deposit.
 * @param account Reference to the account being deposited to
 */
void performDeposit(Account &account) {
    print("Enter the amount to deposit: ");
    double depositAmount = check_int_input(0, numeric_limits<int>::max());
    cout << endl;

    account.balance += depositAmount;
    format_on();
    print("Deposit successful. Updated balance: $");
    format_out_on();
    cout << account.balance << "\n";
    format_off();
}

/**
 * @brief Transfer funds from one account to another. This function is called by
 * the transfer_account function in this module.
 * @param sourceAccount The account to transfer funds from. Must be an account
 */
void performFundTransfer(Account &sourceAccount) {
    print("Enter the account number to transfer funds to: ");
    int targetAccountNumber = check_int_input(1, 100);
    cout << endl;

    auto targetAccountIterator =
        find_if(accounts_vector.begin(), accounts_vector.end(),
                [targetAccountNumber](const Account &account) {
                    return targetAccountNumber == account.acc_number;
                });

    // Transfer the amount of funds to the target account.
    if (targetAccountIterator != accounts_vector.end()) {
        print("Enter the amount to transfer: ");
        double transferAmount = check_int_input(0, sourceAccount.balance);
        cout << endl;

        // Update balance for the target account.
        if (transferAmount <= sourceAccount.balance) {
            sourceAccount.balance -= transferAmount;
            targetAccountIterator->balance += transferAmount;

            print("Fund transfer successful.\n");
            printAccountInfo(sourceAccount);
            format_on();
            cout << "Updated balance for target account (#";
            format_out_on();
            cout << targetAccountNumber;
            print("): $");
            format_out_on();
            cout << targetAccountIterator->balance << "\n";
            format_off();
        } else {
            print("Insufficient funds. Fund transfer canceled.\n");
        }
    } else {
        print_error("Invalid target account number. Fund transfer canceled.\n");
    }
}

// Print account information
/**
 * @brief Prints information about an account. This is used to determine if we
 * are running in Gold or Silver mode
 * @param account The account to print
 */
void printAccountInfo(const Account &account) {
    format_on();
    print("Account Information:\n");
    format_on();
    cout << "Account Holder: ";
    format_out_on();
    cout << account.name << "\n";
    format_on();
    cout << "Account Type: ";
    format_out_on();
    cout << ((account.balance >= 1000000) ? "GOLD" : "SILVER") << "\n";
    void format_on();
    print("Account Balance: $");
    format_out_on();
    cout << account.balance << "\n\n";
    format_off();
}

// Print formatted text
/**
 * @brief Prints a string to the screen. This is a debugging function to be used
 * in conjunction with print_string
 * @param text The string to print
 */
void print(string text) {
    cout << "\033[1m\033[32;3m" << text;
    cout << "\033[0m";
}
/**
 * @brief Prints an error to the console. This is a debugging function to be
 * used in conjunction with print_warnings
 * @param text The text to print
 */
void print_error(string text) {
    cout << "\033[1m\033[31;3m" << text;
    cout << "\033[0m";
}
// Enable text formatting
/**
 * @brief \ fn format_on \ brief Turn on formating \ param [ in ] none \ param [
 * out ]
 */
void format_on() { cout << "\033[1m\033[32;3m"; }
/**
 * @brief \ fn format_out_on \ brief Turn on formatting for output \ param [ in
 * ] none
 */
void format_out_on() { cout << "\033[1m\033[34;3m"; }
// Disable text formatting
/**
 * @brief \ brief Turn off formatting \ ingroup QGIS_QUICK_Eastern_
 */
void format_off() { cout << "\033[0m"; }

// Check passcode for correctness and convert to integer
/**
 * @brief Check passcode for validity and return number of passcodes. Print
 * error if invalid passcode. Return value is 0 for success or non - zero for
 * failure.
 * @return number of passcodes in string or - 1 for failure ( check_passcode ()
 * is called by this
 */
int check_passcode() {
    string passcode;
    cin >> passcode;

    // check_passcode Checks if passcode is exactly four digits long
    if (passcode.length() != 4) {
        print("Passcode must be exactly four digits long.\n"
              "Please create a valid Passcode: ");
        return check_passcode();
    }

    for (char c : passcode) {
        // check if passcode is four digit number
        if (!isdigit(c)) {
            print("Passcode must be a four-digit number.\n");
            return check_passcode();
        }
    }

    return stoi(passcode);
}

// Check if user input is between min and max
/**
 * @brief Reads an integer from standard input and checks that it is within the
 * range. If not it tries again to get the value
 * @param min Minimum value of the range
 * @param max Maximum value of the range ( inclusive ).
 * @return The value read from standard input or min if input is out of range.
 * This function is used by print_error
 */
int check_int_input(int min, int max) {
    int input;
    cin >> input;

    // Check if the input is valid.
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        print_error("Invalid input. Please enter a valid number: ");
        return check_int_input(min, max);
        // Check if the input is within the range min max.
    } else if (input < min || input > max) {
        print_error("Invalid input. Please try again:");
        return check_int_input(min, max);
    } else {
        return input;
    }
}
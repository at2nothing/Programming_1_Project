#include <iostream>
#include <string>
#include <vector>
using namespace std;


void ATM();
void new_account();
int account_no_creation();
void print(string text);
void format_on();
void format_off();
int check_int_input(int min, int max);
int check_passcode();

struct Account {
    string name;
    string type;
    int acc_number;
    int password;
    int balance;
};

vector<Account> accounts_vector;
int choice;
int num;
int num2 = 0;
int pass;
int loop2 = 1;
int option;
string cancel;

/**
* Main function for the program. Prints welcome message and prompts user for choice
*/
void main() {
    // This method is used to ask for a new bank account and ATM
    while (true) {
        print(
            "Welcome to our bank\n"
            "You have two choices: \n"
            "(1) NEW BANK ACCOUNT \n"
            "(2) ATM \n"
            "Type 1 or 2: ");
        choice = check_int_input(1, 2);
        cout << endl;

        // This method is called by the user to choose the choice.
        if (choice == 1) {
            new_account();
        // This method is called by the user to choose the choice.
        } else if (choice == 2) {
            ATM();
        // This method is called when the choice is 3.
        } else if (choice == 3) {
            print("Thank you for using our bank\n");
            break;
        }
    }
}


int account_no_creation() {  // ACCOUNT NUMBER CREATION FUNCTION

    return accounts_vector.size() + 1;
}

/**
* NEW ACCOUNT FUNCTION Account creation and account number creation Function is called when user presses enter in new
*/
void new_account() {  // NEW ACCOUNT FUNCTION
    Account account;
    print(
        "Welcome\n"
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
    if (account.balance >= 1000000) {
        account.type = "GOLD";
    } else {
        account.type = "SILVER";
    }

    account.acc_number = account_no_creation();
    accounts_vector.push_back(account);

    format_on();
    cout << "Your account is created successfully\n";
    cout << "Your account number is " << account.acc_number << endl;
    cout << "Your account type is " << account.type << endl;
    cout << "Your balance is " << account.balance << "$" << endl;
    cout << endl;
    format_off();
}

/**
* \ brief ATM This is the function that runs when the program starts
*/
void ATM() {  // ATM

    print(
        "Welcome\n"
        "Enter your account number: ");
    num = check_int_input(1, 100);
    cout << endl;
    bool not_found = false;
    for (auto account : accounts_vector) {
        // Check if the account is not found
        if ((num) != account.acc_number) {
            not_found = true;
        }
    }
    // This method is used to check the account number and check the password and check the account number and check the account number and check the account type and check the account number and check the account type and check the account number and check the account type and check the account number and check the account number and check the account type and check the account number and check the account number and check the account type and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account
    if (not_found == true) {
        print(
            "Invalid account number\n"
            "Please try again Later\n\n\n");
    }

    else {
        print("Please enter your PIN number and press ENTER: ");
        pass = check_int_input(0, 10000);
        cout << endl;
        // This method is used to send the cash withdrawal and deposit.
        for (int j = 1; j < 3; j++) {
            // This method is used to send the account to the server.
            if (pass == accounts_vector[num - 1].password) {
                // This method is used to send the action to the server.
                while (true) {
                    format_on();
                    cout << "Welcome " << accounts_vector[num - 1].name << endl;
                    cout << "Your account number is "
                         << accounts_vector[num - 1].acc_number << endl;
                    cout << "Your account type is "
                         << accounts_vector[num - 1].type << endl;
                    cout << "Your available balance is "
                         << accounts_vector[num - 1].balance << "$" << endl;
                    cout << endl;
                    // Set the type of account to GOLD or SILVER
                    if (accounts_vector[num - 1].balance >= 1000000) {
                        accounts_vector[num - 1].type = "GOLD";
                    } else {
                        accounts_vector[num - 1].type = "SILVER";
                    }
                    cout << endl;
                    int option;
                    int exchange;
                    int num3;      // to check acc num
                    int num4 = 0;  // other account to be transfered to
                    cout << "Choose the action\n";
                    cout << "(1) Cash Withdrawal\n";
                    cout << "(2) Deposit\n";
                    cout << "(3) Fund Transfer\n";
                    cout << "(4) quit\n\n";
                    cout << "Type 1 or 2 or 3 or 4: ";

                    format_off();
                    option = check_int_input(1, 4);
                    cout << endl;
                    // This method is used to generate the cash and deposit cashs
                    if (option == 1) {  // cash withdrawal
                        print("Your Limit is 2000\n");
                        print("Enter amount of cash to be withdrawn: ");
                        exchange = check_int_input(0, 2000);
                        // This method is used to calculate the amount of cash withdrawn
                        if (exchange > accounts_vector[num - 1].balance) {
                            print("You do not have enough cash\n\n");
                        } else {
                            accounts_vector[num - 1].balance -= exchange;
                            print("Cash withdrawn successfully\n");
                            format_on();
                            cout << "-" << exchange << endl;
                            cout << "Available balance = "
                                 << accounts_vector[num - 1].balance << "$"
                                 << endl;
                            format_off();
                        }
                    // This method is used to determine the amount of cash you want to deposit put cash transfer cash to the other account
                    } else if (option == 2) {  // deposit (put cash)
                        print("Enter amount of cash you want to deposit: ");
                        format_on();
                        exchange = check_int_input(0, 100000);
                        accounts_vector[num - 1].balance += exchange;
                        cout << "+" << exchange << endl;
                        cout << "Available balance = "
                             << accounts_vector[num - 1].balance << "$" << endl;
                    // This method is called by the user to transfer cash to the other account.
                    } else if (option == 3) {
                        print(
                            "Enter account number you want to transfer cash "
                            "to: ");
                        num2 = check_int_input(1, 100);
                        for (auto account : accounts_vector) {
                            // check if the account number is valid
                            if ((num2 - 1) != account.acc_number) {
                                print("This account number is invalid\n");
                                not_found = true;
                            }
                        }
                        // This method is called by the user to transfer the cash to the other account.
                        if (not_found) {
                            print(
                                "Invalid account number\n"
                                "Please try again Later\n");
                        } else {
                            print("Enter amount of cash to be transfered: ");
                            exchange = check_int_input(0, 100000);
                            // This method is called by the user to transfer the cash to another account.
                            if (exchange > accounts_vector[num - 1].balance) {
                                print(
                                    "You do not have enough cash to transfer\n"
                                    "Please try again later\n");
                            } else {
                                accounts_vector[num - 1].balance -= exchange;
                                accounts_vector[num2 - 1].balance += exchange;
                                format_on();
                                cout << "-" << exchange
                                     << " are transfered successfully from "
                                        "your account\n";
                                cout << "+" << exchange
                                     << " are transfered successfully to the "
                                        "other account\n";
                                cout << "Cash transfered successfully\n";
                                cout << "Available balance = "
                                     << accounts_vector[num - 1].balance << "$"
                                     << endl;
                                format_off();
                            }
                        }
                    // This method is called by the user when the user clicks on the bank.
                    } else if (option == 4) {
                        print("Thank you for using our bank\n");
                        break;
                    } else {
                        print("Enter a valid number.");
                    }
                }
            } else {
                format_on();
                cout << "Incorrect password you have " << 3 - j
                     << " times left: ";
                format_off();
                pass = check_int_input(0, 10000);
            }
            cout << endl;
        }
    }
}

/**
* Prints a string to the screen. This is a debugging function to be used in conjunction with print_string
* 
* Args:
* 	 text: The string to print
*/
void print(string text) {
    cout << "\033[1m\033[34;3m" << text;
    cout << "\033[0m";
}

/**
* \ fn format_on \ brief Display format on screen and start formatting
*/
void format_on() { cout << "\033[1m\033[34;3m"; }

/**
* \ brief Turn off formatting \ ingroup QGIS_QUICK
*/
void format_off() { cout << "\033[0m"; }
/**
* Check passcode for correctness and convert to integer for efficient comparison This function is called by main. cpp
* 
* 
* Returns: 
* 	 int The integer representation of the passcode or 0 if
*/
int check_passcode() {
    string passcode;
    cin >> passcode;
    // Ensure passcode is a string with exactly four characters
    // Check if passcode is four characters long
    if (passcode.length() != 4) {
        print(
            "Passcode must be exactly four characters long.\n"
            "Please Create a Valid Passcode: ");
        return check_passcode();
    }

    // Check if each character is a digit
    for (char c : passcode) {
        // Check if the passcode is four digit number
        if (!isdigit(c)) {
            print("Passcode must be a four-digit number.\n");
            return check_passcode();  // Add the missing argument
        }
    }

    // Convert the passcode string to an integer for efficient comparison
    int passcode_int = stoi(passcode);
    return passcode_int;
}
/**
* Check if user input is between min and max. If not the user is prompted to enter a valid number
* 
* Args:
* 	 min: Minimum value of the input
* 	 max: Maximum value of the input ( inclusive ).
* 
* Returns: 
* 	 Integer that was entered or min if input isn't
*/
int check_int_input(int min, int max) {
    int input;
    cin >> input;

    // Check if the input operation with cin was successful
    // Check if the input is valid.
    if (cin.fail()) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n');  // Discard invalid input
        print("Invalid input. Please enter a valid number: ");
        return check_int_input(min, max);
    // Check if the input is within the range min max.
    } else if (input < min || input > max) {
        format_on();
        cout << "Invalid input. Please try again:";
        format_off();
        return check_int_input(min, max);
    } else {
        return input;
    }
}

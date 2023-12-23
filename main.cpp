#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function prototypes
void ATM();
void new_account();
int account_num_creation();
void print(string text);
void format_on();
void format_off();
int check_int_input(int min, int max);
int check_passcode();

struct Account {   // Account structure
    string name;        
    string type;
    int acc_number;
    int password;
    int balance;
};

vector<Account> accounts_vector; // Vector to store all accounts


// Global variables
int choice; //to check the choice
int num;    //to check the account number
int num2 = 0; //to check the account number
int pass;  //to check the password
int loop2 = 1; //to check if the user wants to exit the transaction
int option; //to check the option
int x = 1; //to check if the user wants to exit the transaction
string type; //to check the account type
string cancel; //to check if the user wants to exit the transaction

/**
* Main function for the program. Prints welcome message and prompts user for choice
*/
void main() {  // todo [JANA]
    // This method is used to ask for a new bank account and ATM
    while (true) {
        print(
            "Welcome to our bank\n"
            "You have two choices: \n"
            "(1) NEW BANK ACCOUNT \n"
            "(2) ATM \n"
            "Type 1 or 2: ");
        choice = check_int_input(1, 3); // This method is used to check the choice.
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


int account_num_creation() {  // ACCOUNT NUMBER CREATION FUNCTION  // todo [Nada]
    return accounts_vector.size() + 1;
}

/**
* NEW ACCOUNT FUNCTION Account creation and account number creation Function is called when user presses enter in new
*/
void new_account() {  // NEW ACCOUNT FUNCTION  // todo [Hend]
    Account account;  // Create a new account
    print(      // This method is used to print the welcome message.
        "Welcome\n"
        "Enter your name: ");
    cin >> account.name;  // This method is used to check the name.
    cout << endl; 
    print("Create your password: ");  // This method is used to print the password.
    account.password = check_passcode();  // This method is used to check the password.
    cout << endl;  
    print("Enter your balance: ");  // This method is used to print the balance.
    account.balance = check_int_input(0, 100000000);  // This method is used to check the balance.
    cout << endl;
    // Set account type to GOLD or SILVER
    if (account.balance >= 1000000) {  // This method is used to check the balance.
        account.type = "GOLD";      
    } else {
        account.type = "SILVER";
    }

    account.acc_number = account_num_creation();
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
void ATM() {  // ATM FUNCTION  // todo [Anas]

    print(
        "Welcome\n"
        "Enter your account number: ");
    num = check_int_input(1, 100);
    cout << endl;
    bool not_found = true;
    for (auto account : accounts_vector) {
        // Check if the account is not found
        if ((num) != account.acc_number) {
            not_found = false;
            break;
        }
    }
    // This method is used to check the account number and check the password and check the account number and check the account number and check the account type and check the account number and check the account type and check the account number and check the account type and check the account number and check the account number and check the account type and check the account number and check the account number and check the account type and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account number and check the account
    if (not_found) {
        print(
            "Invalid account number\n"
            "Please try again Later\n\n\n");
    }

    else {
        print("Please enter your PIN number and press ENTER: ");
        pass = check_int_input(0, 10000);
        cout << endl;
        // This method is used to send the cash withdrawal and deposit.
			for (int i = 1; i <= 100; i++) {
				if (num == accounts_vector[i].acc_number) {
					num2 = i; //variable to save index in to check in if condition
				}
			}
			if (num2 == 0) {
				cout << "This account number is incorrect" << endl; //how didnt continue
			}
			else {

				cout << "Please enter your PIN number and press ENTER: ";
				cin >> pass;
				cout << endl;
				for (int j = 1; j <= 3; j++) {

					if (pass == accounts_vector[num2].password) {
						for (x; x <= 100; x++) {
							cout << "You are customer number " << num2 << endl;
							cout << "Your name is " << accounts_vector[num2].name << endl;

							if (accounts_vector[num2].balance >= 1000000) {
								type = "GOLD";
							}

							else
							{
								type = "SILVER";
							}

							cout << "Availale balance is " << accounts_vector[num2].balance << endl;
							cout << "Your account type is " << type << endl;
							cout << endl;

							int choice2;
							double exchange;
							int num3; //to check acc num
							int num4 = 0; // other account to be transfered to

							cout << "Choose the action\n";
							cout << "(1) Cash Withdrawal\n";
							cout << "(2) Deposit\n";
							cout << "(3) Fund Transfer\n\n";
							cout << "Type 1 or 2 or 3: ";
							cin >> choice2;
							cout << endl;

							if (choice2 == 1) { //cash withdrawal
								cout << "Enter amount of cash to be withdrawn: ";
								cin >> exchange;
								if (exchange > accounts_vector[num2].balance) {
									cout << "You do not have enough cash\n\n";
								}
								else {
									accounts_vector[num2].balance = accounts_vector[num2].balance - exchange;
									cout << "-" << exchange << endl;
									cout << "Available balance = " << accounts_vector[num2].balance << endl;
								}
							}

							else if (choice2 == 2) { //deposit (put cash)

								cout << "Enter amount of cash you want to deposit: ";
								cin >> exchange;
								accounts_vector[num2].balance = accounts_vector[num2].balance + exchange;
								cout << "+" << exchange << endl;
								cout << "Available balance = " << accounts_vector[num2].balance << endl;

							}

							else if (choice2 == 3) {
								cout << "Enter account number you want to transfer cash to: ";
								cin >> num3;

								for (int k = 1; k <= 100; k++) {
									if (num3 == accounts_vector[k].acc_number) { //if not correct
										num4 = k; // num4 is index of the transfered acc
									}
								}
								if (num4 == 0) {
									cout << "This account number is invalid" << endl; //how didnt continue
								}
								else {
									cout << "Enter amount of cash to be transfered: ";
									cin >> exchange;
									if (exchange > accounts_vector[num2].balance) {
										cout << "You do not have enough cash to transfer\n";
										cout << "Please enter a valid number\n";
									}
									else {
										accounts_vector[num2].balance = accounts_vector[num2].balance - exchange;
										accounts_vector[num4].balance =accounts_vector[num4].balance + exchange;
										cout << "-" << exchange << " are transfered successfully from your account\n";
										cout << "+" << exchange << " are transfered successfully to the other account\n";
										cout << "Cash transfered successfully\n";
										cout << "Available balance = " << accounts_vector[num2].balance << endl;
									}
								}
							}
							else {
								cout << "Enter a valid number." << endl;
							}
							cout << "Do you want to exit the transaction?\n";
							cout << "yes or no\n";
							cin >> cancel;
							if (cancel == "yes") {
								x = 101;
							}
							else if (cancel == "no") {
								continue; 
							}
							else {
								cout << "Type yes or no\n";
							}
						}

					}
					else {
						cout << "Incorrect password you have " << 3 - j << " times left: ";
						cin >> pass;
					}
					cout << endl;
				}
			}
		}
}
/**
* Prints a string to the screen. This is a debugging function to be used in conjunction with print_string
* 
* Args:
* 	 text: The string to print
*/
void print(string text) {  // todo [Youssif]
    cout << "\033[1m\033[32;3m" << text;
    cout << "\033[0m";
}

/**
* \ fn format_on \ brief Display format on screen and start formatting
*/
void format_on() { cout << "\033[1m\033[32;3m"; }  // todo [Basmalla]

/**
* \ brief Turn off formatting \ ingroup QGIS_QUICK
*/
void format_off() { cout << "\033[0m"; }   // todo [Basmalla]
/**
* Check passcode for correctness and convert to integer for efficient comparison This function is called by main. cpp
* 
* 
* Returns: 
* 	 int The integer representation of the passcode or 0 if
*/
int check_passcode() {  // todo [Youssif]
    string passcode;
    cin >> passcode;
    // Ensure passcode is a string with exactly four characters
    // Check if passcode is four characters long
    if (passcode.length() != 4) {
        print(
            "Passcode must be exactly four Digits long.\n"
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
int check_int_input(int min, int max) {  // todo [Nada]
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
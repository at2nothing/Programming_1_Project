#include <iostream>
#include <string>
#include<vector>
using namespace std;


// todo: change everything to struct
// todo: add a function to check if the account number is already taken
// // add a function to check the int input
// // add a function to check the string input (???? how to do that)
// todo: add a function to check the password input (is 4 integers)
// todo: a function to change the the color of the output text and make it bold
// todo: change all the cout to  print function

void ATM();
void new_account();
int account_no_creation();
void print(string text);
void format_on();
void format_off();
int check_int_input(int input,int min,int max);
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
	int choice2;
	string cancel;



void main() {


	while (true) {

		print("Welcome to our bank\n"
			"You have two choices: \n"
			"(1) NEW BANK ACCOUNT \n"
			"(2) ATM \n"
			"Type 1 or 2: ");
		choice = check_int_input(1, 3);
		cout << endl;

		if (choice == 1) 
		{
			new_account();
		}
		else if (choice == 2) {
			ATM();
		}
		else if (choice == 3) {
			print("Thank you for using our bank\n");
			break;
		}
	}
	
}





/** FUNCTIONS**/


int account_no_creation(){  //ACCOUNT NUMBER CREATION FUNCTION

    return accounts_vector.size()+1;
}

void new_account(){  //NEW ACCOUNT FUNCTION
	Account account;
    print("Welcome\n"
        "Enter your name: ");
	cin >> account.name;
	cout << endl;
	print("Enter your password: ");
	account.password= check_passcode();
	cout << endl;
	print("Enter your balance: ");
	account.balance = check_int_input(0, 100000000);
	cout << endl;
	account.acc_number = account_no_creation();
	accounts_vector.push_back(account);

	format_on();
	cout<<"Your account is created successfully\n";
	cout<<"Your account number is " << account.acc_number << endl;
	cout<<"Your balance is " << account.balance << endl;
	cout << endl;
	format_off();
}


void ATM(){  //ATM FUNCTION
		cout<<"Welcome\n";
		cout<<"Enter your account number: ";
		cin >> num;
		cout << endl;
		for (int i = 1; i <= 100; i++) {
			if (num == acc_number[i]) {
				num2 = i; //variable to save index in to check in if condition
			}
		}
		if (num2 == 0) {
			cout<<"This account number is incorrect" << endl; //how didnt continue
		}
		else {
			cout<<"Please enter your PIN number and press ENTER: ";
			cin >> pass;
			cout << endl;
			for (int j = 1; j <= 3; j++) {
				if (pass == password[num2]) {
					for (x; x <= 100; x++) {
						cout<<"You are customer number " << num2 << endl;
						cout<<"Your name is " << name[num2] << endl;
						if (balance[num2] >= 1000000) {
							type = "GOLD";
						}
						else
						{
							type = "SILVER";
						}
						cout<<"Availale balance is " << balance[num2] << endl;
						cout<<"Your account type is " << type << endl;
						cout << endl;
						int choice2;
						double exchange;
						int num3; //to check acc num
						int num4 = 0; // other account to be transfered to
						cout<<"Choose the action\n";
						cout<<"(1) Cash Withdrawal\n";
						cout<<"(2) Deposit\n";
						cout<<"(3) Fund Transfer\n\n";
						cout<<"Type 1 or 2 or 3: ";
						cin >> choice2;
						cout << endl;
						if (choice2 == 1) { //cash withdrawal
							cout<<"Enter amount of cash to be withdrawn: ";
							cin >> exchange;
							if (exchange > balance[num2]) {
								cout<<"You do not have enough cash\n\n";
							}
							else {
								balance[num2] = balance[num2] - exchange;
								cout<<"-" << exchange << endl;
								cout<<"Available balance = " << balance[num2] << endl;
							}
						}
						else if (choice2 == 2) { //deposit (put cash)
							cout<<"Enter amount of cash you want to deposit: ";
							cin >> exchange;
							balance[num2] = balance[num2] + exchange;
							cout<<"+" << exchange << endl;
							cout<<"Available balance = " << balance[num2] << endl;
						}
						else if (choice2 == 3) {
							cout<<"Enter account number you want to transfer cash to: ";
							cin >> num3;
							for (int k = 1; k <= 100; k++) {
								if (num3 == acc_number[k]) { //if not correct
									num4 = k; // num4 is index of the transfered acc
								}
							}
							if (num4 == 0) {
								cout<<"This account number is invalid" << endl; //how didnt continue
							}
							else {
								cout<<"Enter amount of cash to be transfered: ";
								cin >> exchange;
								if (exchange > balance[num2]) {
									cout<<"You do not have enough cash to transfer\n";
									cout<<"Please enter a valid number\n";
								}
								else {
									balance[num2] = balance[num2] - exchange;
									balance[num4] = balance[num4] + exchange;
									cout<<"-" << exchange << " are transfered successfully from your account\n";
									cout<<"+" << exchange << " are transfered successfully to the other account\n";
									cout<<"Cash transfered successfully\n";
									cout<<"Available balance = " << balance[num2] << endl;
								}
							}
						}
						else {
							cout<<"Enter a valid number." << endl;
						}
						cout<<"Do you want to exit the transaction?\n";
						cout<<"yes or no\n";
						cin >> cancel;
						if (cancel == "yes") {
							x = 101;
						}
						else if (cancel == "no") {
							continue; 
						}
						else {
							cout<<"Type yes or no\n";
						}
					}
				}
				else {
					cout<<"Incorrect password you have " << 3 - j << " times left: ";
					cin >> pass;
				}
				cout << endl;
			}
		}
}

void print(string text){
	cout<<"\033[1m\033[34;3m" << text;
	cout<<"\033[0m";
}

void format_on(){
	cout<<"\033[1m\033[34;3m" ;
}

void format_off(){
	cout<<"\033[0m";
}
int check_passcode() {
	string passcode;
	print("Enter your passcode: ");
	cin >> passcode;
 // Ensure passcode is a string with exactly four characters
 if (passcode.length() != 4) {
	 print("Passcode must be exactly four characters long.\n");
	 check_passcode(); // Add the missing argument
 }

 // Check if each character is a digit
 for (char c : passcode) {
	 if (!isdigit(c)) {
		print("Passcode must be a four-digit number.\n");
	 	check_passcode(); // Add the missing argument
	 }
 }

 // Convert the passcode string to an integer for efficient comparison
 int passcode_int = stoi(passcode);
 return passcode_int;
}
int check_int_input(int min, int max) {
	int input;
	cin >> input;
    while (true) {
        cout<<"Please enter a number between " << min << " and " << max << ": ";
        cin >> input;

        // Check if the input operation with cin was successful
        if (cin.fail()) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
			print("Invalid input. Please enter a valid number.\n");
			check_int_input(min, max); 
        } else if (input < min || input > max) {
			format_on();
            cout<<"Number out of range. Please enter a number between " << min << " and " << max << ".\n";
			format_off();
			check_int_input(min, max);
        } else {
            break;  // Valid input, exit the loop
        }
    }
	return input;
}

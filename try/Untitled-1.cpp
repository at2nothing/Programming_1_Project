#include <iostream>
#include <string>
using namespace std;
int main() {

	string name[100];
	string type;
	long acc_number[100];
	int password[100];
	double balance[100];
	int choice;
	int num;
	int num2 = 0;
	int pass;
	int loop2 = 1;
	int choice2;
	int x = 1;
	string cancel;

	for (int loop = 1; loop <= 100;) {

		x = 1; // will not enter the for loop in line 81

		cout << "You have two choices: \n";
		cout << "(1) NEW BANK ACCOUNT \n";
		cout << "(2) ATM \n";
		cout << "Type 1 or 2: ";
		cin >> choice;
		cout << endl;

		if (choice == 1) {

			for (loop2; loop2 <= 100;) { //reset everytime and type 1 because of (break)
				loop++; // to increase 1 only everytime sb sign in (when type 1)
				cout << "Welcome to our website\n";
				cout << "Now you have to fill some information about yourself\n\n";

				cout << "Enter your account number: ";
				cin >> acc_number[loop2];
				cout << endl;

				cout << "Thank you\n";
				cout << "Your are customer number " << loop2 << endl;
				cout << "Enter your name: ";
				cin >> name[loop2];
				cout << endl;

				cout << "Create a password of 4 digit-number: ";
				cin >> password[loop2];
				cout << endl;

				balance[loop2] = 0;

				break;
			}
			loop2++; // same reason
		}
		else if (choice == 2) {
			cout << "Welcome\n";

			cout << "Enter your account number: ";
			cin >> num;
			cout << endl;

			for (int i = 1; i <= 100; i++) {
				if (num == acc_number[i]) {
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

					if (pass == password[num2]) {
						for (x; x <= 100; x++) {
							cout << "You are customer number " << num2 << endl;
							cout << "Your name is " << name[num2] << endl;

							if (balance[num2] >= 1000000) {
								type = "GOLD";
							}

							else
							{
								type = "SILVER";
							}

							cout << "Availale balance is " << balance[num2] << endl;
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
								if (exchange > balance[num2]) {
									cout << "You do not have enough cash\n\n";
								}
								else {
									balance[num2] = balance[num2] - exchange;
									cout << "-" << exchange << endl;
									cout << "Available balance = " << balance[num2] << endl;
								}
							}

							else if (choice2 == 2) { //deposit (put cash)

								cout << "Enter amount of cash you want to deposit: ";
								cin >> exchange;
								balance[num2] = balance[num2] + exchange;
								cout << "+" << exchange << endl;
								cout << "Available balance = " << balance[num2] << endl;

							}

							else if (choice2 == 3) {
								cout << "Enter account number you want to transfer cash to: ";
								cin >> num3;

								for (int k = 1; k <= 100; k++) {
									if (num3 == acc_number[k]) { //if not correct
										num4 = k; // num4 is index of the transfered acc
									}
								}
								if (num4 == 0) {
									cout << "This account number is invalid" << endl; //how didnt continue
								}
								else {
									cout << "Enter amount of cash to be transfered: ";
									cin >> exchange;
									if (exchange > balance[num2]) {
										cout << "You do not have enough cash to transfer\n";
										cout << "Please enter a valid number\n";
									}
									else {
										balance[num2] = balance[num2] - exchange;
										balance[num4] = balance[num4] + exchange;
										cout << "-" << exchange << " are transfered successfully from your account\n";
										cout << "+" << exchange << " are transfered successfully to the other account\n";
										cout << "Cash transfered successfully\n";
										cout << "Available balance = " << balance[num2] << endl;
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
		else {
			cout << "please enter a valid number\n";
        }
	}
	return 0;
}
#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
/*
Mini Project ATM
#Check balance
#Cash withdraw
#User details
#Update mobile no.
*/
class ATM
{
private:
	long int acc_no;
	double balance;
	string name;
	int PIN;
	string mobile;
public:
	void setdata(long int acc_no1, double balance1, string name1, int PIN1, string mobile1)
	{
		acc_no = acc_no1;
		balance = balance1;
		name = name1;
		PIN = PIN1;
		mobile = mobile1;

	}
	long int getacc_no()
	{
		return acc_no;
	}
	double getbalance()
	{
		return balance;
	}
	string getname()
	{
		return name;
	}
	int getPIN()
	{
		return PIN;
	}
	string getmobile()
	{
		return mobile;
	}
	void cashWithdraw(int amnt)
	{
		if (amnt > 0 && amnt < balance)
		{
			balance -= amnt;
			cout << "Collect your cash : ";
			cout << "Available Balance : " << balance;
			_getch();
		}
		else
		{
			cout << "Invalid Amount!!";
			_getch();
		}
	}
	void setmobile(string old1, string new1)
	{
		if (old1 == mobile)
		{
			mobile = new1;
			cout << endl << "Successfully Updated ";
			_getch();
		}
	}

};
void main()
{
	int choice = 0, enterPIN;
	long int enterACC;
	system("cls");
	ATM user1;
	user1.setdata(12345678, 100000, "Muskan", 0000, "9988776655");
	do
	{
		system("cls");
		cout << "**********Welcome to ATM**********" << endl;
		cout << endl << "Enter your Account Number : ";
		cin >> enterACC;
		cout << endl << "Enter your PIN : ";
		cin >> enterPIN;
		if ((enterACC == user1.getacc_no()) && (enterPIN == user1.getPIN()))
		{
			do 
			{
				int amount = 0;
				string oldmobile, newmobile;
				system("cls");
				cout << "**********Welcome to ATM**********" << endl;
				cout << endl << "Select your choice";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash Withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << endl << "Your Bank Balance is : " << user1.getbalance();
					_getch();
					break;
				case 2:
					cout << endl << "Enter the Amount : ";
					cin >> amount;
					user1.cashWithdraw(amount);
					_getch();
					break;
				case 3:
					cout << "Your Details : " << endl;
					cout << "Account Number : " << user1.getacc_no() << endl;
					cout << "Name : " << user1.getname() << endl;
					cout << "Balance : " << user1.getbalance() << endl;
					cout << "Mobile Number : " << user1.getmobile() << endl;
					_getch();
					break;
				case 4:
					cout << "Enter your old mobile number : ";
					cin >> oldmobile;
					cout << endl << "Enter your new mobile number : ";
					cin >> newmobile;
					user1.setmobile(oldmobile, newmobile);
					break;
				case 5:
					exit(0);
				default:
					cout << endl << " Enter Valid Data!! ";
				}

			} while (1);
		}


	} while (1);

}
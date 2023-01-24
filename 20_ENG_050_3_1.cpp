//header files
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<Windows.h>

double TotMonRepaid = 0;
double TotmonInterest = 0;
int month = 1;

using namespace std;


double calMonInterest(float LoanAmountf,float interestRatef, float monPaymentf,float IRf,int nf)
{
	float monInterest, MonRepaid;
	monInterest = LoanAmountf * IRf;
	MonRepaid = monPaymentf - monInterest;
	LoanAmountf = LoanAmountf - MonRepaid;
	/*cout << endl;
	cout << "\nFor " << month << " month" << endl;
	cout << "  month Repaid- " << fixed << setprecision(2) << MonRepaid << endl;
	cout << "  month Interest- " << fixed << setprecision(2) << monInterest << endl;
	cout << endl;*/
	ofstream table;
	table.open("table.txt", ios::app);
	table << month << "\t\t" << fixed << setprecision(2) << LoanAmountf << "\t\t" << fixed << setprecision(2) << monInterest << "\t\t" << fixed << setprecision(2) << MonRepaid << endl;
	TotMonRepaid = TotMonRepaid + MonRepaid;
	TotmonInterest = TotmonInterest + monInterest;
	month++;
	if (month<=nf)
	{
		calMonInterest(LoanAmountf, interestRatef, monPaymentf,IRf,nf);
	}
	else
	{
		
		return 0;
	}	
	
}

class getLoan
{
private:
	string Name, LoanName;
	int age=0, Income=0;
	int n,type, MaxN;
	double IR, D, monPayment, monInterest, LoanAmount, remainLoan;
	double b, c, d;
	int a;

public:
	void getDetails()
	{
		cout << "Enter customer name : " ;
		cin >> Name;
		cout << "Enter customer age :  " ;
		cin >> age;
		cout << "Enter customer monthly income : ";
		cin >> Income;
	}

	double loanDetails()
	{
		double var2 = 0.0;
		if (age > 18 && age < 55)
		{
			if (Income > 45000)
			{
				cout << "\nLoan Name \t\t: Vehicle\n";
				cout << "Max. Loan Amount \t: Rs. 1000000\n";
				cout << "Max. repay period \t: 60\n";
				cout << "Interest Rate \t\t: 14% \n\n";
				var2 = 1.1;
			}
			
			
		}

		if (age > 25 && age < 55 )
		{
			if (Income > 100000)
			{
				cout << "Loan Name \t\t: Housing\n";
				cout << "Max. Loan Amount \t: Rs. 2500000\n";
				cout << "Max. repay period \t: 60\n";
				cout << "Interest Rate \t\t: 8% \n\n";
				var2 = 1.1;
			}
			
			
		}

		if (age > 25 && age < 35 )
		{
			if (Income > 45000)
			{
				cout << "Loan Name \t\t: Eductaion\n";
				cout << "Max. Loan Amount \t: Rs. 1500000\n";
				cout << "Max. repay period \t: 284\n";
				cout << "Interest Rate \t\t: 6% \n\n";
				var2 = 1.1;
			}
			
			
		}

		if (age > 60)
		{
			if (Income > 35000)
			{
				cout << "Loan Name \t\t: Senior Citizen\n";
				cout << "Max. Loan Amount \t: Rs. 500000\n";
				cout << "Max. repay period \t: 60\n";
				cout << "Interest Rate \t\t: 4.5% \n\n";
				var2 = 1.1;
			}
			
			
		}

		if (age > 30 && age < 55 )
		{
			if (Income > 100000)
			{
				cout << "Loan Name \t\t: Personal\n";
				cout << "Max. Loan Amount \t: Rs. 2000000\n";
				cout << "Max. repay period \t: 60\n";
				cout << "Interest Rate \t\t: 14.5% \n\n";

				cout << "\nLoan Name \t\t: Personal\n";
				cout << "Max. Loan Amount \t: Rs. 3000000\n";
				cout << "Max. repay period \t: 84\n";
				cout << "Interest Rate \t\t: 16.2% \n\n";
				var2 = 1.1;
			}
			
		}
		return var2;
		
	}
	
	double SelectLoan()
	{
		cout << "\n1 for Vehicle\n2 for Housing\n3 for Education\n4 for Senior Citizen\n5 for Personal\n\n";
		cout << "Enter Your Loan Name \t: " ;
		cin >> type;
		cout << "Enter Your Loan Amount \t: ";
		cin >> LoanAmount;
		double var1;
		var1 = 0.0;
		if (type == 1)
		{
			if (LoanAmount <= 1000000)
			{
				cout << "\nYour posible repay period is 60 \n";
				var1 = 1.1;
			}
			else
			{
				cout << "\nYou exceed the max loan amount. \n";
			}
		}

		else if (type == 2)
		{
			if (LoanAmount <= 2500000)
			{
				cout << "\nYour posible repay period is 60 \n";
				var1 = 1.1;
			}
			else
			{
				cout << "\nYou exceed the max loan amount. \n";
		
				
			}
		}

		else if (type == 3)
		{
			if (LoanAmount <= 1500000)
			{
				cout << "\nYour posible repay period is 284 \n";
				var1 = 1.1;
			}
			else
			{
				cout << "\nYou exceed the max loan amount. \n";
				
				
			}
		}

		else if (type == 4)
		{
			if (LoanAmount < 500000)
			{
				cout << "\nYour posible repay period is 60 \n";
				var1 = 1.1;
			}
			else
			{
				cout << "\nYou exceed the max loan amount. \n";
				

			}
		}

		else if (type == 5)
		{
			cout << "Enter Your choice for Max Period : ";
			cin >> MaxN;
			if (MaxN==60)
			{
				cout << "\nYour posible repay period is 60 \n";
				var1 = 1.1;
			}
			else if (MaxN==84)
			{
				cout << "\nYour posible repay period is 84 \n";
				var1 = 1.1;
			}
			else
			{
				cout << "\nYou exceed the max loan amount. \n";
				
			}
		}

		else
		{
			cout << "\nYou entered Loan Name is Wrong. Please Try Again..!" << endl;
			return 0;
		}
		return var1;
	}

	double calRepayAmount()
	{
		if (type==1)
		{
			cout << "\nEnter your payback period \t: ";
			cin >> n;
			if (n <= 60)
			{
				IR = 0.12 / 12;
				D = ((pow((1 + IR), n) - 1) / (IR * pow((1 + IR), n)));
				monPayment = LoanAmount / D;
				cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

				calMonInterest(LoanAmount, 0.12, monPayment, IR, n);
				cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << monPayment*n << endl;
				cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << (monPayment * n)- LoanAmount << endl;
			}
			else
			{
				cout << "\nYou exceed your max. pay period" << endl;
				return 0;
			}
			
			
		}

		else if (type == 2)
		{
			cout << "\nEnter your payback period \t: ";
			cin >> n;
			if (n <= 60)
			{
				IR = 0.08 / 12;
				D = ((pow(1 + IR, n) - 1) / (IR * pow(1 + IR, n)));
				monPayment = LoanAmount / D;
				cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

				calMonInterest(LoanAmount, 0.08, monPayment, IR, n);
				cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << TotMonRepaid << endl;
				cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << TotmonInterest << endl;
			}

			else
			{
				cout << "\nYou exceed your max. pay period" << endl;
				
			}

		

		}

		else if (type == 3)
		{
			cout << "\nEnter your payback period \t: ";
			cin >> n;
			if (n <= 284)
			{
				IR = 0.06 / 12;
				D = ((pow(1 + IR, n) - 1) / (IR * pow(1 + IR, n)));
				monPayment = LoanAmount / D;
				cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

				calMonInterest(LoanAmount, 0.06, monPayment, IR, n);
				cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << TotMonRepaid << endl;
				cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << TotmonInterest << endl;
			}
			else
			{
				cout << "\nYou exceed your max. pay period" << endl;
				
			}


		}

		else if (type == 4)
		{
			cout << "\nEnter your payback period : ";
			cin >> n;
			if (n <= 60)
			{
				IR = 0.045 / 12;
				D = ((pow(1 + IR, n) - 1) / (IR * pow(1 + IR, n)));
				monPayment = LoanAmount / D;
				cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

				calMonInterest(LoanAmount, 0.045, monPayment, IR,n);
				cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << TotMonRepaid << endl;
				cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << TotmonInterest << endl;
			}
			else
			{
				cout << "\nYou exceed your max. pay period" << endl;
				return 0;
			}

		}

		else if (type == 5)
		{
			
			
				if (MaxN == 60)
				{
					cout << "\nEnter your payback period : ";
					cin >> n;
					IR = 0.145 / 12;
					D = ((pow(1 + IR, n) - 1) / (IR * pow(1 + IR, n)));
					monPayment = LoanAmount / D;
					cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

					calMonInterest(LoanAmount, 0.145, monPayment, IR,n);
					cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << TotMonRepaid << endl;
					cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << TotmonInterest << endl;
				}
			
			
				else if (MaxN == 84)
				{
					cout << "\nEnter your payback period : ";
					cin >> n;
					IR = 0.162 / 12;
					D = ((pow(1 + IR, n) - 1) / (IR * pow(1 + IR, n)));
					monPayment = LoanAmount / D;
					cout << "\nTotal Monthly Payment \t: " << fixed << setprecision(2) << monPayment;

					calMonInterest(LoanAmount, 0.162, monPayment, IR, n);
					cout << "\nTotal Monthly Repaid \t: " << fixed << setprecision(2) << TotMonRepaid << endl;
					cout << "\nTotal Monthly Interest \t: " << fixed << setprecision(2) << TotmonInterest << endl;
				}
			

				else
				{
					cout << "\nYou exceed your max. pay period" << endl;
				}
			

		}
	}

	void File()
	{
		ofstream myFile;
		myFile.open(Name +".txt", ofstream::out);

		myFile << "Name \t\t\t: " << Name << endl;
		if (type == 1)
		{
			myFile << "Selected Loan \t\t: Vehicle" << endl;
			myFile << "MaxRepayAmount \t\t: 60" << endl;
			myFile << "AnnualInterestRate \t: 14%" << endl;
			myFile << "Repay Period \t\t: " <<n<< endl;
			myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
			myFile << "\n==================================================================================" << endl;
			myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
			myFile << "==================================================================================" << endl;
			fstream file;
			file.open("table.txt", ios::in);
			file >>a>>b>>c>>d ;

			while (!file.eof())
			{
				myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t\t" << fixed << setprecision(2) << d << endl;
				file >> a >> b >> c >> d;
			}

		}
		else if (type == 2)
		{
			myFile << "Selected Loan \t\t: Housing" << endl;
			myFile << "MaxRepayPeriod \t\t: 60" << endl;
			myFile << "AnnualInterestRate \t: 8%" << endl;
			myFile << "Repay Period \t\t: " << n << endl;
			myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
			myFile << "\n==================================================================================" << endl;
			myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
			myFile << "==================================================================================" << endl;
			fstream file;
			file.open("table.txt", ios::in);
			file >> a >> b >> c >> d;

			while (!file.eof())
			{
				myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t" << fixed << setprecision(2) << d << endl;
				file >> a >> b >> c >> d;
			}
		}
		else if (type == 3)
		{
			myFile << "Selected Loan \t\t: Education" << endl;
			myFile << "MaxRepayPeriod\t\t: 284" << endl;
			myFile << "AnnualInterestRate \t: 6%" << endl;
			myFile << "Repay Period \t\t: " << n << endl;
			myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
			myFile << "\n==================================================================================" << endl;
			myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
			myFile << "==================================================================================" << endl;
			fstream file;
			file.open("table.txt", ios::in);
			file >> a >> b >> c >> d;

			while (!file.eof())
			{
				myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t" << fixed << setprecision(2) << d << endl;
				file >> a >> b >> c >> d;
			}
		}
		else if (type == 4)
		{
			myFile << "Selected Loan \t\t: Senior Citizen" << endl;
			myFile << "MaxRepayPeriod \t\t: 60" << endl;
			myFile << "AnnualInterestRate \t: 4.5%" << endl;
			myFile << "Repay Period \t\t: " << n << endl;
			myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
			myFile << "\n==================================================================================" << endl;
			myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
			myFile << "==================================================================================" << endl;
			fstream file;
			file.open("table.txt", ios::in);
			file >> a >> b >> c >> d;

			while (!file.eof())
			{
				myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t" << fixed << setprecision(2) << d << endl;
				file >> a >> b >> c >> d;
			}
		}
		else if (type == 5)
		{
			if (MaxN == 60)
			{
				myFile << "Selected Loan \t\t: Personal" << endl;
				myFile << "MaxRepayPeriod \t\t: 60" << endl;
				myFile << "AnnualInterestRate \t: 14.5%" << endl;
				myFile << "Repay Period \t\t: " << n << endl;
				myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
				myFile << "\n==================================================================================" << endl;
				myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
				myFile << "==================================================================================" << endl;
				fstream file;
				file.open("table.txt", ios::in);
				file >> a >> b >> c >> d;

				while (!file.eof())
				{
					myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t" << fixed << setprecision(2) << d << endl;
					file >> a >> b >> c >> d;
				}
			}
			
			else if (MaxN == 84)
			{
				myFile << "Selected Loan \t\t: Personal" << endl;
				myFile << "MaxRepayPeriod \t\t: 84" << endl;
				myFile << "AnnualInterestRate \t: 16.2%" << endl;
				myFile << "Repay Period \t\t: " << n << endl;
				myFile << "RequestLoanAmount \t: " << fixed << setprecision(2) << LoanAmount << endl;
				myFile << "\n==================================================================================" << endl;
				myFile << "Month\t\tRemainLoanAmount\tInterest\t\tRepaid Loan Amount" << endl;
				myFile << "==================================================================================" << endl;
				fstream file;
				file.open("table.txt", ios::in);
				file >> a >> b >> c >> d;

				while (!file.eof())
				{
					myFile << a << "\t\t" << fixed << setprecision(2) << b << "\t\t" << fixed << setprecision(2) << c << "\t\t" << fixed << setprecision(2) << d << endl;
					file >> a >> b >> c >> d;
				}
			}

		}
		ofstream newtable;
		newtable.open("table.txt", ofstream::out);
	}
};

int main()
{
	double var1,var2;
	getLoan loan1;
	loan1.getDetails();
	var2=loan1.loanDetails();
	if (var2 == 1.1)
	{
		var1 = loan1.SelectLoan();
		if (var1 == 1.1)
		{
			loan1.calRepayAmount();
			loan1.File();
		}
	}
	
	

	
	return 0;
}
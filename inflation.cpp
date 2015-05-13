//********************************************************************************
//
//	Author:           Shairam (Sai) Narendran
//	Date Created:     3/24/15
//	Revisions:        None.
//
//	Purpose:          Use functions in order to calculate inflation rates 
//
//	Input:            Current Price, Last Year's Price, Price from 2 years ago
//                   
//	Output:           inflation rate from this year to last year
//                    inflation rate from last year to two years ago 
//
//********************************************************************************

#include <iostream> 
#include <iomanip>

using namespace std; 

void getPrices (double& currentPrice, double& lastPrice, double& oldPrice);
double verifyInputs (double& number1);
void calculateInflation (double currentPrice, double lastPrice, double oldPrice,
						 double& inflationOneYear, double& inflationTwoYear);
void printResults (double inflationOneYear, double inflationTwoYear);

int main()
{
	double price;
	double lastyearprice;
	double oldyearprice;
	double inflationOne;
	double inflationTwo;

	getPrices(price, lastyearprice, oldyearprice); 

	cout << "this is the current years price: " << price << endl;

	calculateInflation (price, lastyearprice, oldyearprice, inflationOne, inflationTwo);

	printResults (inflationOne, inflationTwo); 

	return 0;
}

void getPrices (double& currentPrice, double& lastPrice, double& oldPrice)
{
	cout << "Please enter current price of the item: ";
	cin >> currentPrice;
	cout << endl;

	cout << "Please enter price of the item one year ago: ";
	cin >> lastPrice;
	cout << endl;

	cout << "Please enter price of the item two years ago: ";
	cin >> oldPrice;
	cout << endl;
}


// Function created to verify data input. However it keeps messing up output values 
//double verifyInputs (double& number1)
//{  
//		while (number1 <= 0)
//		{
//			cout << "I am sorry but you have entered an invalid input. "; 
//			cout <<	"Please re-enter a positive integer greater than zero: ";
//			cin >> number1; 
//			cout << endl; 
//		}
//		return number1;
//
//}


void calculateInflation (double currentPrice, double lastPrice, double oldPrice,
						 double& inflationOneYear, double& inflationTwoYear)
{
	inflationOneYear = (currentPrice - lastPrice)/(lastPrice);

	inflationTwoYear = (lastPrice - oldPrice)/(oldPrice);
}

void printResults (double inflationOneYear, double inflationTwoYear)

{
	cout << "this is the rate of inflation from last year to this year: ";
	cout <<	inflationOneYear << endl;
	cout << "this is the rate of inflation from two years ago to this last year: ";
	cout <<	inflationTwoYear << endl; 
	
	if (inflationOneYear == inflationTwoYear)
		cout << "The rate of inflation has remained the same over the given span of time." << endl;
	else if (inflationOneYear > inflationTwoYear)
		cout << "Inflation is increasing." << endl;
	else 
		cout << "Inflation is decreasing." << endl;
	
}

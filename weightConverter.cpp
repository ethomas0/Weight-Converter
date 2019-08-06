//Name: Ethan Thomas
//CS& 131 Section A
//Description: This program will convert pounds and ounces to kilograms and
//grams for you. Also if the program sees that you have over a thousand
//grams, it will convert it automatically to kilograms.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const double POUND_TO_GRAMS = 453.6;
const double OUNCES_TO_GRAMS = 28.3495;
int promptAndGetInt(string promtMessage);
int convertToGrams(int pounds, int ounces);
void outputResults(int pounds, int ounces, int grams);
int main()
{
	int pounds = 0;
	int ounces = 0;
	int grams = 0;
	cout << "This program will convert from pounds and ounces to kilograms"
		<< " and grams." << endl;
	pounds = promptAndGetInt("Enter the amount of pounds: ");
	ounces = promptAndGetInt("Enter the amount of ounces: ");
	grams = convertToGrams(pounds, ounces);
	system("CLS");
	outputResults(pounds, ounces, grams);
	
	
	system("pause");
	return 0;
	
}
//This function determines whether or not the user put the correct input. 
//Also if the user puts a mixture of letters and numbers, the function 
//will sift through and grab the first digits it can. 
//Once it finds the correct input
//it puts the numbers back into the stream.
int promptAndGetInt(string promtMessage)
{
	cout << promtMessage;
	char ch;
	cin >> ch;
	while (isdigit(ch) == false)
		cin >> ch;
	
	cin.putback(ch);
	int response;
	cin >> response;
	return response;
}
//This function converts pounds and ounces to grams and adds the grams together. 
//It also will either round up or down automatically for you
int convertToGrams(int pounds, int ounces)
{
	return ((pounds * POUND_TO_GRAMS) + (ounces * OUNCES_TO_GRAMS) + .5);
}
//This function outputs the results and also converts grams into kilograms
//and also ensures that if grams is over 1000, 
//it will automatically convert to kilograms
void outputResults(int pounds, int ounces, int grams)
{
	cout << pounds << " Pound(s) & " << ounces << " Ounce(s) convert to:" << endl;
	cout << grams / 1000 << " Kilogram(s) & " << grams % 1000 
		<< " Gram(s)" << endl;
}

//Output:
//This program will convert from pounds and ounces to kilograms and grams.
//Enter the amount of pounds : 5
//Enter the amount of ounces : 4
//5 Pound(s) & 4 Ounce(s) convert to :
//2 Kilogram(s) & 381 Gram(s)
//
//This program will convert from pounds and ounces to kilograms and grams.
//Enter the amount of pounds : 13
//Enter the amount of ounces : 11
//13 Pound(s) & 11 Ounce(s) convert to :
//6 Kilogram(s) & 209 Gram(s)

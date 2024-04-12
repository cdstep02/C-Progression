/* 
    Author Information: Christopher Stephens
    Lab #2
    Lab Section: B
    Program Description: Program outputs a foreign currency exchange table for the value the user enters
    Date 1/20/2022
    
*/

#include <stdio.h>

int main()
{
	//the following are conversion rates for countries in the table 
	//foregin currency exchange rates vary from day to day. So conversions won't be exact but will be in the ballpark
	const float gbprate = 0.73438; //great british pound
	const float eurorate = 0.88186; //euro
	const float audrate = 1.38747; //austrailian dollar
	const float chfrate = .91592; //swiss franc
	const float cadrate = 1.24955; //canadian dollar
	
	//variable to store the users value
	float currency = 0;
	//ask user to input the currency they would like to exchange
	printf("Please enter the currency amount you wish to see exchanged:  ");
	//get currency from user
	scanf("%f", &currency);
	
	
	//converts the currency entered into USD equivalent of whichever currency is selected
	//I made these variables because performing this option below made it difficult to read and debug
	float usd2gbp = currency / gbprate; 
	float usd2euro = currency / eurorate;
	float usd2aud = currency / audrate;
	float usd2chf = currency / chfrate;
	float usd2cad = currency / cadrate;
	
	//Performs final conversion operations on above variables ,before outputting table to screen
	//outputs the table to screen
	printf("\n\n\t USD \t GBP \t EUR \t AUD \t CHF \t CAD");
	printf("\n\n USD \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", currency, usd2gbp, usd2euro, usd2aud, usd2chf, usd2cad);
	printf("\n\n GBP \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", gbprate * currency, usd2gbp * gbprate, usd2euro * gbprate, usd2aud * gbprate, usd2chf * gbprate, usd2cad * gbprate);
	printf("\n\n EUR \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", eurorate * currency, usd2gbp * eurorate, usd2euro * eurorate, usd2aud * eurorate, usd2chf * eurorate, usd2cad * eurorate);
	printf("\n\n AUD \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", audrate * currency, usd2gbp * audrate, usd2euro * audrate, usd2aud * audrate, usd2chf * audrate, usd2cad * audrate);
	printf("\n\n CHF \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", chfrate * currency, usd2gbp * chfrate, usd2euro * chfrate, usd2aud * chfrate, usd2chf * chfrate, usd2cad * chfrate);
	printf("\n\n CAD \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f", cadrate * currency, usd2gbp * cadrate, usd2euro * cadrate, usd2aud * cadrate, usd2chf * cadrate, usd2cad * cadrate);
	return 0;
}


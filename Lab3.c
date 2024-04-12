/* 
Author Information: Christopher Stephens
Lab #3 section B
Description: Created a program that simulates a calculator
*/
#include <stdio.h>
int main()
{
	int menuOption, dividend2, divisor2, modulus, isPrime, isPrime2;
	float addition1, addition2, sum, subtraction1, subtraction2, difference,  multiplicand, multiplier, product, dividend, divisor, quotient;
	//a do while loop is used because I need to output the menu to the user at least once
	do {
		//Giving intructions to the user and accepting their input
		printf("\n Calculator Menu \n");
		printf("(1) Addition \n");
		printf("(2) Subtraction \n");
		printf("(3) Multiplication \n");
		printf("(4) Division \n");
		printf("(5) Modulus (integers only) \n");
		printf("(6) Test if prime (integers only) \n");
		printf("(7) Exit \n");
		printf("\n Please enter the number of the operation you wish to perform:");
		scanf("%d", &menuOption);
		//used swich case cause it looks better
		switch(menuOption)
		{
			case 1:
				printf("\n Please enter the first number:");
				scanf("%f", &addition1);
				printf("\n Please enter the second number:");
				scanf("%f", &addition2);
				sum = addition1 + addition2;
				printf("\n %.2f + %.2f = %.2f \n", addition1, addition2, sum);
				break;
			
			case 2:
				printf("\n Please enter the number you want to subtract from:");
				scanf("%f", &subtraction1);
				printf("\n Please enter the number you want to subtract from the previous number:");
				scanf("%f", &subtraction2);
				difference = subtraction1 - subtraction2;
				printf("\n %.2f - %.2f = %.2f \n", subtraction1, subtraction2, difference);
				break;
			
			case 3: 
				printf("\n Please enter the multiplicand:");
				scanf("%f", &multiplicand);
				printf("\n Please enter the multiplier:");
				scanf("%f", &multiplier);
				product = multiplicand * multiplier;
				printf("\n %.2f * %.2f = %.2f \n", multiplicand, multiplier, product);
				break;
			//fix it so the user cannot divide by 0
			case 4: 
				printf("\n Please enter the dividend:");
				scanf("%f", &dividend);
				printf("\n Please enter the divisor:");
				scanf("%f", &divisor);
				if(divisor == 0)
				{
					printf("Division by 0 is impossible. Please try again");
					break;
				}
				else
				{
				quotient = dividend / divisor;
				printf("\n %.2f / %.2f = %.2f \n", dividend, divisor, quotient);
				break;
				}
			
			
			case 5:
				printf("\n Please enter the dividend: ");
				scanf("%d", &dividend2);
				printf("\n Please enter the divisor: ");
				scanf("%d", &divisor2);
				modulus = dividend2 % divisor2;
				printf("\n The remainder is %d \n", modulus);
				break;
			
			//for this case I test if a number is prime
			case 6: 
				printf("\n Please enter a number to test: ");
				scanf("%d", &isPrime);
				int k;
				int counter = 0; //stores the values for the if statements
				if(isPrime == 0 || isPrime == 1) //these cannot be prime
				{
					printf("\n %d is not a prime \n", isPrime);	
				}
				else 
				{	
				for(k = 2; k < isPrime / 2; k++)
				{
					if(isPrime % k == 0)
					{
						isPrime2 = isPrime / k;
						counter = 1;//this is for not prime numbers
						printf("\n %d is not a prime. %d * %d = %d \n", isPrime, isPrime2, k, isPrime);
						break;
					}
					else 
					{
						counter = 0;// for numbers that are prime
					}
					
				}
				if(counter == 0)//all the numbers that aren't picked up during the loop conditional statement are prime
				{
					printf("\n %d is a prime.\n", isPrime);
				}
				}
				break;
			
			//this case exits the case swtich statement
			case 7: 
				printf("\n See ya");
				break;
			//this case will be used if the user does not enter a valid operation number	
			default:
				printf("\n The operation you chose does not exist. Please select another below. \n");
				break;
			
			
		}
		
		
	}
	while(menuOption != 7);//this loop makes sure the program will continue until 7 is chosen
	
	return 0;
}

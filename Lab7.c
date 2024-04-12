/*
	Author Information: Christopher Stephens
	Date: 				3/3/2022
	Lab #7
	Lab Section B
	Program Description:This program adds more functionality to the phone book from the previous lab.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the structure that will be used to store data
typedef struct friendInfo
 	{
 		char fname[15];
 		char lname[15];
 		char number[15];
 	} f; 
 
 //this variable will be used to tie a name to a number to go through the loops. That is why I made it global
 int tie = 0;
 
 //function prototype for adding friends to the phone book
void addFriend(f [], char[], char[], char[]); 
//functtion prototype for deleting friends
void deleteFriend(f [], char[], char[]); 
//function prototype for displaying the phone book
void showBook(f []); 
//function prototype for alphabetically sorting the phone book
void sortBook(f []);
//function prototype for finding a friends number
void findNum(f [], char[]);
//function prototype for randomly choosing a friend to call
void randCall(f []);
//function prototype for deleting the entire phone book
void deleteBook(f []);


 
 int main()
 {
 	//declaring variables that will be used later
 	int iUserChoice = 0;
 	int numOfStruct = 9;
 	//allocating memory for the structure so now I can have an array of structures
 	f* friendarr = malloc(numOfStruct * sizeof(friendarr));
 	if(friendarr == NULL)
 	{
 		printf("\n Out of Memory");
 	}
 
 	//allocating memory for the strings entered by user
 	char fNameTemp1[15];
 	char lNameTemp2[15];
 	char *fName;
 	char *lName;
 	char *fNum;
 	fName = (char *) malloc(15 * sizeof(char));
 	lName = (char *) malloc(15 * sizeof(char));
 	fNum = (char *) malloc(15 * sizeof(char));
 	//memory check
 	if(fName == NULL || lName == NULL || fNum == NULL)
 	{
 		printf("Out of memory");
 	}
 	
 	//do-while loop to keep repeating until user chooses 4
 	do
 	{
 		printf("\n Phone Book Application");
 		printf("\n \t 1) Add Friend");
 		printf("\n \t 2) Delete Friend");
 		printf("\n \t 3) Show Phone Book");
 		printf("\n \t 4) Alphabetically Sort Friends by first name");
 		printf("\n \t 5) Find Friend Phone number");
 		printf("\n \t 6) Randomly Select Friend to call");
 		printf("\n \t 7) Delete all contacts");
 		printf("\n \t 8) Quit");
 		printf("\n \n What do you want to do: ");
 		scanf("%d", &iUserChoice);
 		
 		
 		//switch statement
 		switch(iUserChoice)
 		{
 			//enters entries into the phone book
 			case 1: 
 			printf("\n First name: ");
 			scanf("%s", fName);
 			printf("\n Last name: ");
 			scanf("%s", lName);
 			printf("\n Phone Number: ");
 			scanf("%s", fNum);
 			addFriend(friendarr, fName, lName, fNum);
 			break;
 			
 			//deletes entries from the phone book
 			case 2: 
 			printf("\n First Name: ");
 			scanf("%s", fNameTemp1);
 			printf("\n Last Name: ");
 			scanf("%s", lNameTemp2);
 			printf("\n Friend deleted");
 			deleteFriend(friendarr, fNameTemp1, lNameTemp2);
 			break;
 			
 			//dispays the phone book
 			case 3:
 			showBook(friendarr);
 			break;
 			
 			//this case will sort the users friends by first name
 			case 4:
 			sortBook(friendarr);
 			break;
 			
 			//finds the number of a friend the user inputs
 			case 5:
 			printf("Enter your friends first name: ");
 			scanf("%s", fName);
 			findNum(friendarr, fName);
 			break;
 			
 			//gives the user a random friend to call
 			case 6:
 			randCall(friendarr);
 			break;
 			
 			//this will delete all user contacts by freeing the memory from the array of structures
 			case 7: 
 			deleteBook(friendarr);
 			break;
 			
 			//This is the exit case and it frees all the memory
 			case 8: 
 			printf("\n See ya!");
 			free(friendarr); //free memory because you don't need it anymore		
 			break;
 			
 			//this is the default case to make sure the user enters a correct choice
 			default:
 			printf("\n Please select a listed choice:");
 			break;
 			
 		}
 		
 	}
	while(iUserChoice != 8);
	
 	return 0;
 }
 //function definiton for adding a friend
 void addFriend(f fri[], char first[], char last[], char num[])
 {
 	//reallocating memory in a different location so I can have more space
 	char *fri2;
 	fri2 = realloc(fri, (tie + 1) * sizeof(fri));
 	if(fri == NULL)
 	{
 		printf("Out of memory");
 	}
 	strcpy(fri[tie].fname, first);// this will copy user input and stick it into the structure
 	strcpy(fri[tie].lname, last);//this will copy user input and stick it into the structure
 	strcpy(fri[tie].number, num); //this will copy user input and stick it into the structure
 	tie++;
 }
 
 //fucntion definition for deleting a friend
 void deleteFriend(f fri[], char temp1[], char temp2[])
 {
 	int x;
 	int cmp;//variable will be used to delete/drop the selected function
 	//for loop will search for the contact to delete by comparing the string entered by the user to the previously entered user strings
 	for(x = 0; x < tie; x++)
 	{
 		
 		if(strcmp(temp1, fri[x].fname) == 0 && strcmp(temp2, fri[x].lname) == 0)
 		{
 		
 			for(cmp = x; cmp < tie - 1; ++cmp)
 			{
 				fri[cmp] = fri[cmp + 1];
 			}
 			tie--;
 			break;
 		}
 	}
 	//resizing the memory after deleting the contact
 	fri = realloc(fri, (tie) * sizeof(fri));
 	if(fri == NULL)
 	{
 		printf("Out of memory");
 	}
 } 
 //function definition for showing the book
 void showBook(f fri[])
 {
 	int y;
 	//for loop to sort through the array of structures
 	for(y = 0; y < tie; ++y)
 	{
 		printf("\n %s %s %s \n", fri[y].fname, fri[y].lname, fri[y].number);
 	}
 } 
 
 //function definition for finding the users number
 void findNum(f fri[], char tempFirst[])
 {
 	int p;
 	for(p = 0; p < tie; p++)
 	{
 		//we compare the first name the user entered to the names in here
 		if(strcmp(tempFirst, fri [p].fname) == 0)
 		{
 			printf("%s's number is %s \n", tempFirst, fri [p].number);
 		}
 	}
 }
 
 //function definition for giving the user a random friend to call
 void randCall(f fri[])
 {
 	srand(time(0));
 	int iRand = rand() % tie;
	printf("\n The program has randomly selected %s. Here is their phone number: %s \n", fri[iRand].fname, fri[iRand].number); 
 }
 
 //function definition for deleting all the contacts from the book at once
 void deleteBook(f fri[])
{
	int loop1;
	int loop2;
	//for this loop I select the last value(Null value) in the array and move it forward and shrink the array until it is all that is left in the array
	for(loop1 = tie; loop1 >= 0; loop1--)
	{
		fri[loop1] = fri[loop1 + 1];
		tie--;
	}
	fri = realloc(fri, (tie) * sizeof(fri));
	printf("Phone book contacts deleted!");
}
//function for alphabetically sorting the users friends by their first name
void sortBook(f fri[])
{
	char temp[15];
	char temp2[15];
	char temp3[15];
	int i;
	int k;
	//I made a nested loop for my comparison function to run on
	for(i = 0; i < tie - 1; i++)
	{
		for(k = i + 1; k < tie; k++)
		{
			//here I compare and sort the values in my array of structures
			if(strcmp(fri[i].fname, fri[k].fname) > 0)
			{
				strcpy(temp, fri[i].fname);
				strcpy(temp2, fri[i].lname);
				strcpy(temp3, fri[i].number);
				strcpy(fri[i].fname, fri[k].fname);
				strcpy(fri[i].lname, fri[k].lname);
				strcpy(fri[i].number, fri[k].number);
				strcpy(fri[k].fname, temp);
				strcpy(fri[k].lname, temp2);
				strcpy(fri[k].number, temp3);
			}
		}
	}
	printf("\n Alphabetically sorted friends by first name: \n");
	//this loop prints out the values
	for(i = 0; i < tie; i++)
	{
		printf("%s %s %s \n", fri[i].fname, fri[i].lname, fri[i].number);
	}
}


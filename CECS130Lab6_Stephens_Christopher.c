/*
	Author Information: Christopher Stephens
	Date: 				2/24/2022
	Program Description:Program simulates a phone book, where the user can add, delete, or display friends. 
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
 
 int main()
 {
 	//declaring variables that will be used later
 	int userChoice = 0;
 	int numOfStruct = 9;
 	//allocating memory for the structure so now I can have an array of structures
 	f* friendarr = malloc(numOfStruct * sizeof(friendarr));
 	if(friendarr == NULL)
 	{
 		printf("\n Out of Memory");
 	}
 
 	//allocating memory for the strings entered by user
 	char tempStor1[15];
 	char tempStor2[15];
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
 		printf("\n \t 4) Quit");
 		printf("\n \n What do you want to do: ");
 		scanf("%d", &userChoice);
 		
 		
 		//switch statement
 		switch(userChoice)
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
 			scanf("%s", tempStor1);
 			printf("\n Last Name: ");
 			scanf("%s", tempStor2);
 			printf("\n Friend deleted");
 			deleteFriend(friendarr, tempStor1, tempStor2);
 			break;
 			
 			//dispays the phone book
 			case 3:
 			showBook(friendarr);
 			break;
 			
 			//This is the exit case and it frees all the memory
 			case 4: 
 			printf("\n See ya!");
 			free(friendarr); //free memory because you don't need it anymore		
 			break;
 			
 			//this is the default case to make sure the user enters a correct choicd
 			default:
 			printf("\n Please select a listed choice");
 			break;
 			
 		}
 		
 	}
	while(userChoice != 4);
	
 	return 0;
 }
 //function definiton for adding a friend
 void addFriend(f fri[], char first[], char last[], char num[])
 {
 	//creating an index and allocating memory
 	char *fri2;
 	fri2 = realloc(fri, (tie + 1) * sizeof(fri));
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

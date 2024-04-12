/*
	Author Information: Christopher Stephens
	Date: 				3/23/2022
	Lab #8
	Lab Section B
	Program Description:This program adds more functionality to the phone book from the previous lab,mby using files to store user information.
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
void addFriend(char[], char[], char[], char[]); 

//functtion prototype for deleting friends
void deleteFriend(char[], char[], f []); 
//function prototype for displaying the phone book
void showBook(); 

//function prototype for alphabetically sorting the phone book
void sortBook();
//function prototype for finding a friends number
void findNum(f [], char[], char[], char[]);

//function prototype for randomly choosing a friend to call
void randCall(f []);
//function prototype for deleting the entire phone book
void deleteBook();


 
 int main()
 {
 	//declaring variables that will be used later
 	int iUserChoice = 0;
 	int numOfStruct = 15;
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
 	char response[5];
 	char promptTemp[5];
 	char *lName;
 	char *fileName;
 	char *fNum;
 	fName = (char *) malloc(15 * sizeof(char));
 	lName = (char *) malloc(15 * sizeof(char));
 	fNum = (char *) malloc(15 * sizeof(char));
 	fileName = (char *) malloc(15 * sizeof(char));
 	//memory check
 	if(fName == NULL || lName == NULL || fNum == NULL || fileName == NULL)
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
 			addFriend(fName, lName, fNum, fileName);
 			break;
 			
 			//deletes entries from the phone book
 			case 2: 
 			printf("\n First Name: ");
 			scanf("%s", fNameTemp1);
 			printf("\n Last Name: ");
 			scanf("%s", lNameTemp2);
 			deleteFriend(fNameTemp1, lNameTemp2, friendarr);
 			break;
 			
 			//dispays the phone book
 			case 3:
 			showBook();
 			break;
 			
 			//this case will sort the users friends by first name
 			case 4:
 			sortBook(friendarr);
 			break;
 			
 			//finds the number of a friend the user inputs
 			case 5:
 			printf("Enter your friends first name: ");
 			scanf("%s", fName);
 			printf("Did you save your friend in specific file-location (Y/N):");
 			scanf("%s", response);
 			findNum(friendarr, fName, fileName, response);
 			break;
 			
 			//gives the user a random friend to call
 			case 6:
 			randCall(friendarr);
 			break;
 			
 			//this will delete all user contacts by freeing the memory from the array of structures
 			case 7: 
 			
 			deleteBook();
 			break;
 			
 			//This is the exit case and it frees all the memory
 			case 8: 
 			printf("\n See ya!");
 			//free(friendarr); //free memory because you don't need it anymore		
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
 void addFriend(char first[], char last[], char num[], char file[])
 {
 	//new stuff involving files below:
 	char yesNo[3];
 	char *str1 = "Y";
 	char *str2 = "y";
 	FILE *pWrite;
 	printf("Would you like to store this entry anywhere specific (Y/N):");
 	scanf("%s", yesNo);
 	
 	if(strcmp(str1, yesNo) == 0 || strcmp(str2, yesNo)== 0)
 	{
 		printf("What would you like to call this file:");
 		scanf("%s", file);
 		pWrite = fopen(file , "a");
 		if(pWrite != NULL)
 		{
 			fprintf(pWrite, "%s %s %s \n", first, last, num);
 			fclose(pWrite);
 		}
 		else 
 		{
 			printf("File could not be opened");
 		}
 	}
 	else
 	{
 		pWrite = fopen("default.dat", "a");
		if(pWrite != NULL)
		{
			fprintf(pWrite, "%s %s %s \n", first, last, num);
			fclose(pWrite);
		}	
		else
		{
			printf("File could not be opened");
		}
 	}
 	
 }
 
 //fucntion definition for deleting a friend
 void deleteFriend(char temp1[], char temp2[], f fri[])
 {
 	char response[5];
 	int i;
 	char userFile[15];
 	char *str1 = "Y";
 	FILE *pRead;
 	FILE *pWrite;
 	FILE *pWrite2;
 	FILE *pRead2;
 	char *str2 = "y";
 	printf("Is the contact you want to delete in a specific location? (Y/N)");
 	scanf("%s", response);
 	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
 	{
 		printf("What is the name of the file:");
 		scanf("%s", userFile);
 		pRead = fopen(userFile, "r");
 		if(pRead != NULL)
 		{
 			fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead))
 			{
 				++tie;
 				fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 				
 			}
 			fclose(pRead);
 		}
 		else
 		{
 			printf("File couldn't be opened");
 		}
 	}
 	else
 	{
 		pRead2 = fopen("default.dat", "r");
 		if(pRead2 != NULL)
	 	{
	 		
 			fscanf(pRead2, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead2))
 			{
 				++tie;
 				fscanf(pRead2,"%s %S %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
 	}
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
 	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
 	{
 		pWrite = fopen(userFile, "w");
 		if(pWrite != NULL)
 		{
 			for(i = 0; i < tie; ++i)
 			{
 				fprintf(pWrite, "%s %s %s", fri[i].fname, fri[i].lname, fri[i].number);
 			}
 			fclose(pWrite);
 		}
 		else
 		{
 			printf("File couldn't be opened");
 		}
 	}
 	else
 	{
 		pWrite2 = fopen("default.dat", "w");
 		if(pWrite2 != NULL)
	 	{
	 		for(i = 0; i < tie; ++i)
 			{
 				fprintf(pWrite2, "%s %s %s", fri[i].fname, fri[i].lname, fri[i].number);
 			}
 			fclose(pWrite2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
 	}
 	int loop1;
	int loop2;
	//for this loop I select the last value(Null value) in the array and move it forward and shrink the array until it is all that is left in the array
	for(loop1 = tie; loop1 >= 0; loop1--)
	{
		fri[loop1] = fri[loop1 + 1];
		tie--;
	}
	fri = realloc(fri, (tie) * sizeof(fri));
 } 
 
 //function definition for showing the book
 void showBook()
 {
 	FILE *pRead3;
 	char *str1 = "Y";
 	char *str2 = "y";
 	char response[5];
 	char filename[15];
 	FILE *pRead4;
 	char fName[15];
 	char lName[15];
 	char num[15];
 	printf("Did your file-location have a specific name (Y/N):");
 	scanf("%s", response);
 	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
 	{
 		printf("Please enter the name of the file-location:");
 		scanf("%s", filename);
 		pRead3 = fopen(filename, "r");
 		printf("Heres your %s phone book: \n", filename);
 		if(pRead3 != NULL)
 		{
 			fscanf(pRead3, "%s %s %s", fName, lName, num);
 			while(!feof(pRead3))
 			{
 			printf("%s \t %s \t %s \n", fName, lName, num);
 			fscanf(pRead3, "%s %s %s", fName, lName, num);
 			}
 			fclose(pRead3);
 		}
 		else
 		{
 			printf("File couldn't be opened");
 		}
 	}
 	else
 	{
 		pRead4 = fopen("default.dat", "r");
 		printf("Here's your default phone book: \n");
 		if(pRead4 != NULL)
 		{
 	
 			fscanf(pRead4, "%s%s%s", fName, lName, num);
 			while(!feof(pRead4))
 			{
 				printf("%s \t %s \t %s \n", fName, lName, num);
 				fscanf(pRead4, "%s%s%s", fName, lName, num);
 			}
 			fclose(pRead4);
 		}
		 else
		 {
		 	printf("File couldn't be opened");
		 }	
 	}
	
 	
}
 //function definition for finding the users number
 void findNum(f fri[], char tempFirst[], char file[], char response[])
 {
 	int counter;
 	char userFile[15];
 	char *fri2;
 	char *str1 = "Y";
 	char *str2 = "y";
 	FILE *pRead;
 	FILE *pRead2;
 	
 	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
 	{
 		printf("What is the name of the file:");
 		scanf("%s", &userFile);
 		pRead = fopen(userFile, "r");
 		if(pRead != NULL)
 		{
 			fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead))
 			{
 				++tie;
 				fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 				
 			}
 			fclose(pRead);
 		}
 		else
 		{
 			printf("File couldn't be opened");
 		}
 	}
 	else
 	{
 		pRead2 = fopen("default.dat", "r");
 		if(pRead2 != NULL)
	 	{
	 		
 			fscanf(pRead2, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead2))
 			{
 				++tie;
 				fscanf(pRead2,"%s %S %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
 		
 
 	}
 	for(counter = 0; counter < tie; ++counter)
 	{
 		if(strcmp(tempFirst, fri[counter].fname) == 0)
 		{
 			printf("%s's number is %s", tempFirst, fri[counter].number);
 			
 		}
 	}
 	int loop1;
	int loop2;
	//for this loop I select the last value(Null value) in the array and move it forward and shrink the array until it is all that is left in the array
	for(loop1 = tie; loop1 >= 0; loop1--)
	{
		fri[loop1] = fri[loop1 + 1];
		tie--;
	}
	fri = realloc(fri, (tie) * sizeof(fri));
 	
 }
 
 //function definition for giving the user a random friend to call
 void randCall(f fri[])
 {
 	char response[5];
 	FILE *pRead;
 	char *str1 = "Y";
 	char *str2 = "y";
 	FILE *pRead2;
 	char userFile[15];
 	printf("Would you like to randomly call a friend in a specific file-location (Y/N)");
 	scanf("%s", response);
 	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
	{
		printf("What is the name of the file:");
 		scanf("%s", userFile);
 		pRead = fopen(userFile, "r");
 		if(pRead != NULL)
 		{
 			fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead))
 			{
 				++tie;
 				fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead);
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
	}
	else
	{
		pRead2 = fopen("default.dat", "r");
		if(pRead2 != NULL)
	 	{
	 		
 			fscanf(pRead2, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead2))
 			{
 				++tie;
 				fscanf(pRead2,"%s %S %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
		fclose(pRead2);
	}
 	srand(time(0));
 	int iRand = rand() % tie;
	printf("\n The program has randomly selected %s. Here is their phone number: %s \n", fri[iRand].fname, fri[iRand].number); 
	int loop1;
	int loop2;
	//for this loop I select the last value(Null value) in the array and move it forward and shrink the array until it is all that is left in the array
	for(loop1 = tie; loop1 >= 0; loop1--)
	{
		fri[loop1] = fri[loop1 + 1];
		tie--;
	}
	fri = realloc(fri, (tie) * sizeof(fri));
 }
 
 //function definition for deleting all the contacts from the book at once
 void deleteBook()
{
	char *str1 = "Y";
 	char *str2 = "y";
 	char *str3 = " ";
 	char response[5];
 	FILE *pRead;
 	FILE *pRead2;
 	char userFile[15];
	printf("Would you like to delete a specific file-location (Y/N)");
	scanf("%s", response);
	if(strcmp(response, str1) == 0 || strcmp(response, str2) == 0)
	{
		printf("What is the name of the file:");
 		scanf("%s", &userFile);
 		pRead = fopen(userFile, "w");
 		fclose(pRead);
	}
	else
	{
		pRead2 = fopen("default.dat", "w");
		fclose(pRead2);
	}
	
}
//function for alphabetically sorting the users friends by their first name
void sortBook(f fri[])
{
	char responses[5];
 	FILE *pRead;
 	FILE *pWrite;
 	FILE *pWrite2;
 	char *str1 = "Y";
 	char *str2 = "y";
 	FILE *pRead2;
 	char userFile[15];
 	printf("Would you like to sort a specific file-location (Y/N)");
 	scanf("%s", responses);
 	if(strcmp(responses, str1) == 0 || strcmp(responses, str2) == 0)
	{
		printf("What is the name of the file:");
 		scanf("%s", userFile);
 		pRead = fopen(userFile, "r");
 		if(pRead != NULL)
 		{
 			fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead))
 			{
 				++tie;
 				fscanf(pRead, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead);
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
	}
	else
	{
		pRead2 = fopen("default.dat", "r");
		if(pRead2 != NULL)
	 	{
	 		
 			fscanf(pRead2, "%s %s %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			while(!feof(pRead2))
 			{
 				++tie;
 				fscanf(pRead2,"%s %S %s", fri[tie].fname, fri[tie].lname, fri[tie].number);
 			}
 			fclose(pRead2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
		fclose(pRead2);
	}
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
	
	if(strcmp(responses, str1) == 0 || strcmp(responses, str2) == 0)
 	{
 		pWrite = fopen(userFile, "w");
 		if(pWrite != NULL)
 		{
 			for(i = 0; i < tie; ++i)
 			{
 				fprintf(pWrite, "%s %s %s \n", fri[i].fname, fri[i].lname, fri[i].number);
 			}
 			fclose(pWrite);
 		}
 		else
 		{
 			printf("File couldn't be opened");
 		}
 	}
 	else
 	{
 		pWrite2 = fopen("default.dat", "w");
 		if(pWrite2 != NULL)
	 	{
	 		for(i = 0; i < tie; ++i)
 			{
 				fprintf(pWrite2, "%s %s %s \n", fri[i].fname, fri[i].lname, fri[i].number);
 			}
 			fclose(pWrite2);
 		
 		}
 		else
 		{
 			printf("File couldn't be opened");	
 		}
 	}
	
	
	int loop1;
	int loop2;
	//for this loop I select the last value(Null value) in the array and move it forward and shrink the array until it is all that is left in the array
	for(loop1 = tie; loop1 >= 0; loop1--)
	{
		fri[loop1] = fri[loop1 + 1];
		tie--;
	}
	fri = realloc(fri, (tie) * sizeof(fri));
	
}


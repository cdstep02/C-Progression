/*
	Author Information: Christopher Stephens
	Date: 2/18/2022
	Lab #5
	Lab Section: B
	Program Description: Program prompts the user for personal information. With the personal information, the program makes a short story that will have alternative endings and run differently each time	
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	//intializes arrays to hold the user input
	char name[50];
	char cAge[3];
	char cJob[50];
	char cColor[20];
	char cSuperhero[20];
	char cFood[25];
	
	
	//These are the questions for the user
	//I scan the user entry but do not need an & because the array is a pointer
	printf("What is your name? ");
	scanf("%s", name); 
	printf("\n How old are you? ");
	scanf("%s", cAge);
	printf("\n What job do you have? ");
	scanf("%s", cJob);
	printf("\n What is your favorite color? ");
	scanf("%s", cColor);
	printf("\n Who is your favorite superhero? ");
	scanf("%s", cSuperhero);
	printf("\n What is your favorite food? ");
	scanf("%s", cFood);
	
	//here are my arrays that utilize pointers
	//below are my arrays of strings, which are pointer arrays
	//these will also be randomized when put in the story
	char*cMovieTheatre[4]={"TinsleTown", "Village8", "Xscape", "AMC"};
	char*cCar[4]={"Ferrari", "Corvette", "Porsche", "Camaro"};
	char*cResturant[4]={"Golden Coral", "The MarketPlace", "Outback", "O'Charleys"};
	char*cActivity[4]={"play videogames", "go to sleep","relax", "watch tv"};
	
	//here I use the srand function and put it in a variable so it can choose a random value from the above arrays
	//seed the random number function with 0 so it changes everytime
	srand(time(0));
	int randChoice = rand() % 4;
	
	//below is my story
	printf("\n \n %s is a %s year old %s who has a %s %s. After a long, hard week at work %s decides he's going to treat himself today. So today %s decides to go watch a %s movie at %s.", name, cAge, cJob, cColor, cCar[randChoice], name, name, cSuperhero, cMovieTheatre[randChoice]);
	printf(" After watching the %s movie, %s goes to eat %s at %s for dinner. After dinner %s decides to %s for the rest of the night. \n",cSuperhero, name, cFood, cResturant[randChoice], name, cActivity[randChoice]);
	return 0;
	
}

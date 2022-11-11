#include <stdio.h>
int main()
{
	char name[30];
	printf("Enter your name: ");
	//this function makes it easy to take input with a space in between
	gets(name);
	int c = 0, vowels, dVowels, consonants, dConsonants;
	char vowel[6] = {'A', 'E', 'I', 'O', 'U',};
	char consonant[22] = {'B', 'C', 'D', 'F', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
	
	while(name[c] != '\0')
	{
		int i, x;
		//for both for loops check to see how to make sure you don't repeat count vowels and constonants
		for(i = 0; vowel[i] != '\0'; ++i)
		{
		//this will increment for 
			if(vowel[i] == name[c] || vowel[i] + 32 == name[c])
			{
				vowels += 1;
				break;
			}
			
		}
		
		for(x = 0; consonant[x] != '\0'; ++x)
		{
			if(consonant[x] == c || consonant[x] + 32 == name[c])
			{
				consonants += 1;
				break;
			}
			
		}
		++c;
	}
	
	printf("There are %d vowels and %d consonants in your name. \n", vowels, consonants);
}

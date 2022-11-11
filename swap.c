#include <stdio.h>
#define swap(a, b, t) (t = a, a = b, b = t)

int main()
{
	int tempStore = 0, firstnum = 0, secondnum = 0;
	printf("Enter your first number: ");
	scanf("%d", &firstnum);
	printf("Enter your second number: ");
	scanf("%d", &secondnum);
	swap(firstnum, secondnum, tempStore);
	printf("%d %d \n", firstnum, secondnum);
	
	
	return 0;
}

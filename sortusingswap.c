#include <stdio.h>
#define swap(a, b, t) (t = a, a = b, b = t)


int main()
{
	//values to be sorted
	int arr[10] = {2, 3, 1, 5, 6, 7, 12, 9, 4, 13};
	printf("Origninal array: ");
	for(int t = 0; t < 10; ++t)
	{
		printf("%d ", arr[t]);
	}
	printf("\n");
	int l, temp;
	//the following loops sort the array.
	//This iterates over the values in the array
	for(int i = 0; i < 10; ++i)
	{
		
		//this tests to see which values should be in front of the other
		while(arr[l] > arr[l + 1] && l >= 0)
		{
			swap(arr[l], arr[l + 1], temp);
			--l;
		}
		l = i;
		
	}
	printf("Here is your sorted array: ");
	for(int j = 0; j < 10; ++j)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}

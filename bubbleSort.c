#include <stdio.h>

void print_arr(int arr[] ,int size)
{
    int i;

    for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}

void bubble_sort(int arr[],int size)
{
	int i;

	for(i=0;i<size-1;i++)
	{
		int j;
		int flag = 1;
		for(j=0;j<size-1-i;j++)
		{
			if(arr[j] < arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	print_arr(arr,size);
	printf("\n");
}

int main()
{
	int arr[] = {5,4,7,2,5,9,3,2,8,0};

	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array:\n");
	print_arr(arr,size);
	printf("\n");

	printf("Sorted array:\n");
	bubble_sort(arr,size);

	return 0;
}

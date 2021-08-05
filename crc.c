#include<stdio.h>
void print(int*arr, int n)
{
	int i;
	for(i =0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int len_data_word, len_divisor, i, j, k;
	int data_word[100];
	int divisor[100];
	int code[100];
	
	printf("Enter length of data word");
	scanf("%d", &len_data_word);
	
	for(i =0; i<len_data_word; i++)
	{
		scanf("%d", &data_word[i]);
	}
	for(i =0; i<len_data_word; i++)
	{
		code[i] = data_word[i];
	}
	
	
	printf("Enter length divisor");
	scanf("%d", &len_divisor);	
	for(i =0; i<len_divisor; i++)
	{
		scanf("%d", &divisor[i]);
	}
	
	for(i=len_data_word; i<len_data_word+len_divisor-1; i++)
	{
		data_word[i] = 0;
	}
	
	print(data_word, len_data_word+len_divisor - 1);
	print(divisor, len_divisor);
	
	for(i = 0; i<len_data_word+len_divisor; i++)
	{
		if(data_word[i] == 0)
		{
			continue;
		}
		if((len_data_word+ len_divisor)- i < len_divisor)
		{
			break;
		}
		for(j = 0; j<len_divisor; j++)
		{
			data_word[i+j] = data_word[i+j] ^ divisor[j];
		}
		print(data_word, len_data_word+len_divisor - 1);
	}
	
	
	for(i = len_data_word; i < len_data_word+len_divisor-1; i++)
	{
		code[i] = data_word[i];
	}
	
	
	printf("Sender: ");
	print(code, len_data_word+len_divisor - 1);
	
	
	//receiver part;
	
	for(i = 0; i<len_data_word+len_divisor; i++)
	{
		if(code[i] == 0)
		{
			continue;
		}
		if((len_data_word+ len_divisor)- i < len_divisor)
		{
			break;
		}
		for(j = 0; j<len_divisor; j++)
		{
			code[i+j] = code[i+j] ^ divisor[j];
		}
		print(code, len_data_word+len_divisor - 1);
	}
	
	printf("receiver: ");
	print(code, len_data_word+len_divisor - 1);
}






#define _CRT_SECURE_NO_WARNINGS




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



//typedef int Item;
//typedef struct node *link;
typedef struct node
{
	int data[1000];
	struct node *next;
}link;






void stackinit(int x);
link *STACKpush(link *headptr, int *d);
link *STACKpop(link *headptr, int *d);
void printlist(link *head);


int main(void)
{
	link *head = NULL;

	int x;
	int i;
	int j;
	
	int arr[1000] = { 0 }, d[1000];
	
	int k;
	int c;
	printf("give number\n");
	scanf("%d", &x);
	k = 0;
	head=STACKpush(head, arr);	
	
	head = STACKpop(head, d);

	for (i = x-1; i>=1; i--)
	{
		for (j = 1; j<=x-1; j++)
		{
			if ((i + j) == x)
			{
				arr[0] = j;
				arr[1] = i;
				head=STACKpush(head, arr);
				
			}
		}
	}


	printlist(head);

	
	do
	{
		head = STACKpop(head, d);
		
			for (i = d[0] - 1,j=1; i >= 1,j<=d[0]-1 ; i--,j++)
			{
				
					
					for (c = 1; c < 1000; c++)	//copying the board
					{
						arr[c + 1] = d[c];
					}

					arr[0] = i;
					arr[1] = j;

					if (arr[0] == 1)	//if it is 1 dont push
					{
						for (c = 0; arr[c] != 0; c++)	//running until it finds 0
						{
							printf("%d ", arr[c]);
						}

						printf("\n");
					}
					else	//else push the new reduced by 1 element
					{
						head = STACKpush(head, arr);

						for (c = 0; arr[c] != 0; c++)	//running until it finds 0
						{
							printf("%d ", arr[c]);
						}

						printf("\n");
					}
					
				
			}

	} while (head != NULL);
	
	
	








	return 0;
 }




link *STACKpush(link *headptr, int *d)
{
	int i;
	link *t= (link *)malloc(sizeof(link));	//allocating memory  for next push operation 
	for (i = 0; i < 1000; i++)
	{
		t->data[i] = d[i];	//filling the data array
	}

	t->next = headptr;	//pushing into stack

	return t;	//returning the pushed element
}




link *STACKpop(link *headptr, int *d)
{
	int i;
	link *tmp;

	if (headptr == NULL)
	{
		return NULL;	//returning NULL if stack is empty
	}
	else
	{

		for (i = 0; i < 1000; i++)
		{
			d[i] = headptr->data[i];	//saving the poped element into the main array (d[i])
		}

		tmp = headptr;	//storing the stack head into tmp 

		headptr = headptr->next;	//setting the head pointer to the next element from the one pushed

		free(tmp);	//freeing tmp pointer

		return headptr;	//returning stack head

	}
}


void printlist(link *head)
{

	int i;
	link *tmp = head;	


	do
	{
		for (i=0 ; tmp->data[i]!=0 ; i++)
		{
			printf("%d ", tmp->data[i]);	//printing the stack elements
		}

		printf("\n");	

		tmp = tmp->next;	//setting the tmp pointer to next element
	} while (tmp != NULL);	//looping until it reaches the end of the stack
}
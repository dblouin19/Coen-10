#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Joseph Sindelar
//Global Variables
int groups[5];
int total=0;
char lessons[5][20];
char phones[5][20];
//Functions
void request();
void cancel();
void list();
void search();
void groupsize();
int priority();
int countletter(char);
int main(){
	int option;
	char letter;
	int number;
	int priority_flag;
	while(1){
		printf(" Option 1 is to Add\n Option 2 is to Cancel\n Option 3 is to List the lessons\n Option 4 Checks if you have a reservation\n Option 5 Checks group sizes\n Option 6 is for priority use\n Option 7 Counts a letter\n Option 9 is to exit\n");
		scanf("%d",&option);
		switch (option){
			case 1:
				//Adds a class
				printf("Write your name, number, and group size.\n");
				request();
				break;
			case 2:
				//Cancels a class
				cancel();
				break;
			case 3:
				//Lists the Reservations
				list();
				break;
			case 4:
				//Searches for a Reservation
				search();
				break;
			case 5:
				//Prints names by group size
				groupsize();
				break;
			case 6:
				//Adds priority option
				if(!priority_flag)
					priority_flag=priority();
				else
					printf("Celeb already inbound\n");
				break;
			case 7:
				//Counts a letter
				printf("Letter?");
				fpurge(stdin);
				scanf("%c", &letter);
				fpurge(stdin);
				number = countletter(letter);
				printf("Found %d occurences of %c\n", number, letter);
				break;
			case 9:
				//Ends it all
				return 1;
			default:
				printf("Invalid Option\n");
		}
	}	
}
void request()
	{
	//Adds a class
	char tempphon[20];
	char tempname[20];
	int tempsize;
	int i;
	if (total==5)
		{
		printf("Full\n");
		}
	else
		{
		scanf("%s",tempname);
		for (i=0;i<5;i++)
			{
			if (strcmp(lessons[i],tempname)==0)
				{
				printf("Already signed up\n");
				return;
				}
			}
		scanf("%s",tempphon);
		scanf("%d",&tempsize);
		if (tempsize<1 || tempsize>4)
			{
			printf("Size too big\n");
			return;
			}
		strcpy(lessons[total],tempname);
		strcpy(phones[total],tempphon);
		groups[total]=tempsize;
		total++;
		}
	}
void cancel()
	{
	//Cancels a class
	int i;
	int j;
	char name[20];
	printf("What is the name of the reservation?\n");
	if (total!=0)
		{
		scanf("%s",name);
		for (i=0;i<5;i++)
			{
			if (strcmp(lessons[i],name)==0)
				{
				for (j=i;j<total-1;j++)
					{												
					strcpy (lessons[j],lessons[j+1]);
					strcpy (phones[j],phones[j+1]);
					groups[j]=groups[j+1];
					printf("%s is moved to %d, their phone number is %s\n",lessons[j],j+1,phones[j]);
					}
				lessons[total-1][0]='\0';
				total--;
				break;
				}
			}
		}
	else
		printf("Nothing to cancel.\n");
	}
void list()
	{
	//Lists the Reservations
	int i;
	for (i=0;i<5;i++)
		if(lessons[i][0]=='\0')
			printf("%dpm-free\n",i+1);
		else
			printf("%s has a lesson at %dpm, their phone number is %s, and their group size is %d\n",lessons[i],i+1,phones[i], groups[i]);
	}
void search()
	{	
	//Searches for a Reservation
	int i;
	char letter;
	fpurge(stdin);
	scanf("%c",&letter);
	fpurge(stdin);
	for (i=0;i<5;i++)
		{
		if (lessons[i][0]==letter)
			printf("%s has a lesson\n",lessons[i]);
		}
	}
void groupsize()
	//Searches for all reservations with a certain group size
	{
	int i;
	int coun;
	int tempgroup;
	coun=0;
	scanf("%d",&tempgroup);
	for (i=0;i<5;i++)
		{
		if (groups[i]==tempgroup)
			{
			printf("%s has a group size of %d\n",lessons[i],groups[i]);
			coun++;
			}
		}
	if (coun==0)
		printf("No match");
	}
int priority()
	//Adds in a priority client
	{
	printf("Input Celeb name, number, and group size\n");
	char tempphon[20];
	char tempname[20];
	int tempsize;
	int i;
	scanf("%s",tempname);
	for (i=0;i<5;i++)
		{
		if (strcmp(lessons[i],tempname)==0)
			{
			printf("Already signed up\n");
			return 0;
			}
		}
	scanf("%s",tempphon);
	scanf("%d",&tempsize);
	if (tempsize<1 || tempsize>4)
		{
		printf("Size too big\n");
		return 0;
		}
	if (total==5)
		printf("%s is cancelled\n",lessons[4]);
	for(i=3;i>=0;i--)
		{
		strcpy(lessons[i+1],lessons[i]);
		strcpy(phones[i+1],phones[i]);
		groups[i+1]=groups[i];
		}
	strcpy(lessons[0],tempname);
	strcpy(phones[0],tempphon);
	groups[0]=tempsize;
	if (total<5)
		total++;
	return 1;
	}
int countletter(char letter)
	//Counts letters
	{
	char *p;
	int count=0;
	int i;
	for(i=0;i<5;i++)
		{
		p= lessons[i];
		while(*p!='\0')
			{
			if (*p==letter)
				count++;
			p++;
			}
		}
	return count;
	}










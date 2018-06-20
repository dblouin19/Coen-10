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
int main(){
	int option;
	while(1){
		printf("Option 1 is to Add, Option 2 is to Cancel, Option 3 is to list, Option 4 checks if you have a reservation, Option 5 checks group sizes, and Option 9 is to exit\n");
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
		scanf("%s",tempphon);
		scanf("%d",&tempsize);
		for (i=0;i<5;i++)
			{
			if (strcmp(lessons[i],tempname)==0)
				{
				printf("Already signed up\n");
				return;
				}
			}
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

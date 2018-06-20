#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Joseph Sindelar
int main(){
	char lessons[5][20];
	char name[20];
	int option;
	int time;
	int total;
	int i;
	int array[5];
	int j;
	char letter;
	total=0;
	while(1){
		printf("Option 1 is to Add, Option 2 is to Cancel, Option 3 is to list, Option 4 checks if you have a reservation, Option 9 is to exit\n");
		scanf("%d",&option);
		switch (option){
			case 1:
				//Adds a class
				if (total==5)
					{
					printf("Full\n");
					}
				else
					{
					scanf("%s",lessons[total]);
					total++;
					}
				break;
			case 2:
				//Cancels a class
				printf("What is the name of the reservation?\n");
				if (total!=0){
				scanf("%s",name);
				for (i=0;i<5;i++){
					if (strcmp(lessons[i],name)==0)
					{
						for (j=i;j<total-1;j++)
						{												
							strcpy (lessons[j],lessons[j+1]);
						}
						lessons[total-1][0]='\0';
						total--;
						break;
						}
					}
				}
				else
					printf("Nothing to cancel.\n");
				break;
			case 3:
				//Lists the Reservations
				for (i=0;i<5;i++)
					if(lessons[i][0]=='\0')
						printf("%dpm-free\n",i+1);
					else
						printf("%s has a lesson at %dpm\n",lessons[i],i+1);
				break;
			case 4:
				//Searches for a Reservation
				scanf("%c",&letter);
				for (i=0;i<5;i++){
					if (lessons[i][0]==letter)
						printf("%s has a lesson\n",lessons[i]);
				}
				break;
			case 9:
				//Ends it all
				return 1;
			default:
				printf("Invalid Option\n");
		}
	}	
}

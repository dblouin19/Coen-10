#include <stdio.h>
#include <stdlib.h>
//Joseph Sindelar
int main(){
	int array[5]= {0,0,0,0,0};
	int option;
	int time;
	int total;
	int i;
	total=0;
	while(1){
		printf ("Option 1 is to Add, Option two is to cancel, Option 3 is to list, Option 9 is to exit\n");
		scanf ("%d",&option);
		switch (option){
			case 1:
				if (total==5)
				{
					printf("Full\n");
					break;
				}
				for (i=0;i<5;i++)
					if (array[i]==0){
						array[i]=i+1;
						printf("Your lesson is at %d\n",i+1);
						total ++;
						printf("Confirmed \n");
						break;
					}
				break;
			case 2: 
				printf("What time was your lesson that you want to cancel?\n");
				scanf("%d",&time);
				if (array[time-1]==time)
					{
					array[time-1]=0;
					total--;
					}
				else
					printf("Nothing to cancel\n");
				break;
			case 3:
				for(i=0;i<5;i++)
					if(array[i]==0)
						printf("%dpm-free\n",i+1);
					else
						printf("%dpm-lesson\n",i+1);
				break;
			case 9:
				return 1;
			default:
				printf("Invalid Option\n");
		}
	}
}

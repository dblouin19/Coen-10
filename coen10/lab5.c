#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Joseph Sindelar Thursday 2:15
int main (){
	int i, rand1, rand2, user, counter;
	i=0;
	rand1=0;
	rand2=0;
	user=0;
	counter=0;
	srand((int)time(NULL));
	for(i=0;i<10;i++)
		{	
			rand1=rand()%13;
			rand2=rand()%13;
			printf("%d*%d\n",rand1,rand2);		
			scanf("%d",&user);
				if(rand1*rand2==user)
					counter++;
		}			
	printf("%d\n",counter*10);		
	return 0;
}

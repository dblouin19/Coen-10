#include <stdio.h>
#include <string.h>
#include <ctype.h>
//These are my global variables
char words[10][20];
int length[10];
int total=0;
void output();
void insert();
void reverse();
void convert();
void info();

//This is the main function that runs all of the other functions
int main(){
	insert();
	reverse();
	convert();
	info();
	return 0;
}

//This function prints the words after changes have been made
void output(){
	int i;
	for (i=0;i<total;i++)
		if (words[i][0]!='\0')
			printf("%s\n",words[i]);
printf("\n");
}

//This function reverses the order of the words entered
void reverse(){
	int i;
	char temp[20];
	for(i=0;i<total/2;i++){
		strcpy(temp,words[i]);
		strcpy(words[i],words[total-1-i]);
		strcpy(words[total-1-i],temp);
	}
	output();
}

//This function converts the lower case letters to upper case letters
void convert(){
	char*p;int count;
	int i;
	for (i=0;i<total;i++){	
		p=words[i];count=0;
		while(*p!='\0'){
			if(islower((int)*p))
				*p=toupper((int)*p);
			count++;
			p++;
		}
		length[i]=count;
	}
	printf("After conversion:\n");
	output();
}

//This function adds new words in to the array
void insert(){
	printf("Type some new stuff in here homie\n");
	char new[20];
	int i;
	int j;
	int k;
	for(i=0;i<10;i++){
		if(scanf("%s",new)<1)
			break;
		if(i==0)
			strcpy(words[0],new);
		for (j=0;j<i;j++)
			if (strcasecmp(new,words[j])<0)
				break;
		for (k=i;k>=j;k--){
			strcpy(words[k+1],words[k]);
		}
		strcpy(words[j],new);
	}
	total=i;
	printf("Input\n");
	output();
}

//This function provides information about the words entered
void info(){
	int i;
	char minword[20];strcpy(minword,words[0]);
	char maxword[20];strcpy(maxword,words[0]);
	int max=length[0];
	int min=length[0];
	int sum=0;
	for (i=0;i<total;i++){
		if (length[i]>max){
			max=length[i];
			strcpy(maxword,words[i]);
		}
		if (length[i]<min){
			min=length[i];
			strcpy(minword,words[i]);
		}
		sum+=length[i];
		if (!isalpha(words[i][0]))
		 	printf("%s\n",words[i]);
	}
	printf("%s\n",minword);
	printf("%s\n",maxword);
	printf("%d\n",sum/total);
}
//Yay! We are done with the last lab.

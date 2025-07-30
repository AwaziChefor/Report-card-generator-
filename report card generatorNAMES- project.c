#include<stdio.h>
int i;
int subjectchoice(char Names1[20], char Names2[20])
{
	int j,num,c;
	printf("Enter the number of subjects %s %s offers (MAX number is 11 and MIN is 3): ",Names1,Names2);
	scanf("%d",&num);
	while(num<3 || num>11) {
		printf("Enter a valid number of subjects:");
		scanf("%d",&num);
	}
	return num;
}
float subject_averagechoice(int Sub)
{
	int coef=Sub*5;
	printf("\t\t\t SUB-PROGRAM AVERAGE CALCULATOR \t\t\t\n");
	float marks[Sub],average;
	for(i=0; i<Sub; i++) {
		printf("Enter the marks for subject %d: ",i+1);
		scanf("%f",&marks[i]);
		while(marks[i]<0 || marks[i]>20) {
			printf("%.2f is not a valid mark, Re-enter the mark for subject-%d: ",marks[i],i+1);
			scanf("%f",&marks[i]);
		}
	}
	float sum=0;
	for(i=0; i<Sub; i++) {
		sum+=marks[i]*5;
	}
	average= sum/coef;
	return average;
}
int main()
{
	int n,subjects,Sub;
	printf("Enter the Number of students in this class:");
	scanf("%d",&n);
	char Names1[20],Names2[20],d,grade[1];
	struct Name {
		char Names1[20],Names2[20];
		int ID;
	} Namelist[n];
	struct Name_average {
		char Names1[20],Names2[20];
		int ID;
		float score;
		char grade[1];
	} marklist[n];
	int i,j,b=1;
	for(i=0; i<n; i++) {
		printf(" Student %d:\n",i+1);
		printf("First Name: ");
		scanf("%s",Namelist[i].Names1);
		printf("Second Name: ");
		scanf("%s",Namelist[i].Names2);
		Sub=subjectchoice(Namelist[i].Names1,Namelist[i].Names2);
		marklist[i].score=subject_averagechoice(Sub);
		if(	marklist[i].score>=15 && 	marklist[i].score<=20) {
			marklist[i].grade[1]='A';
		} else if (	marklist[i].score>=13 &&	marklist[i].score<15) {
			marklist[i].grade[1]= 'B';
		} else if(	marklist[i].score>=12 && 	marklist[i].score<13) {
			marklist[i].grade[1]= 'C';
		} else if(	marklist[i].score>=10 && 	marklist[i].score<12) {
			marklist[i].grade[1]='D';
		} else if (	marklist[i].score<=8 && 	marklist[i].score<10) {
			marklist[i].grade[1]= 'E';
		} else {
			marklist[i].grade[1]= 'U';
		}
		Namelist[i].ID=10000;
	Namelist[i].ID+=b;
		b++;
	}
	printf("\n\n\n");
	for(i=0; i<n; i++) {
		for(j=0; j<i; j++) {
			if(marklist[i].score>marklist[j].score) {
				struct Name_average h= marklist[i];
				marklist[i]=marklist[j];
				marklist[j]=h;
			}
		}
	}
	printf("\t\t\t HERE IS THE RANKING OF THESE STUDENTS \t\t\t\n");
		printf("| ID    | STUDENT NAMES  |   AVERAGES   |   GRADES   |  POSITION  |\n");
	for(i=0; i<n; i++) {
		printf("| %d|       %s %s     |     %.2f    |   %c  |    %dth   |\n",Namelist[i].ID,Namelist[i].Names1,Namelist[i].Names2,marklist[i].score,marklist[i].grade[1],i+1);
	}
	return 0;
}

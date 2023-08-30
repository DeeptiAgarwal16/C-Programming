#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	long long int roll;
	char name[30];
	long long int mobile;
	char city[30];
	char email[50];
}student;

typedef struct
{
	int c;
	int ip;
	int maths;
}marks;

void home();
void display3();
void display2();
void display4();
void login();

void title()
{
	system("cls");
	printf("======================================================\n");
	printf("\tSTUDENT RECORD MANAGEMENT SYSTEM\n");
	printf("======================================================\n\n");
}

void newrecord()
{
	student s;
	int i;
	char c,a;
	printf("Enter Details of Student\n\n");
	printf("Roll Number\t :    ");
	scanf("%lld",&s.roll);
	printf("Name\t\t :    ");
	scanf("%*c%[^\n]",s.name);
	for(i=0;s.name[i]!=0;i++)
	{
		if(s.name[i]==' ')
		s.name[i]='_';
	}
	printf("Mobile Number\t :    ");
	scanf("%lld",&s.mobile);
	printf("City\t\t :    ");
	scanf("%*c%[^\n]",s.city);
	printf("Email-ID\t :    ");
	scanf("%*c%[^\n]",s.email);
	FILE * ptr;
	ptr = fopen("details.txt","a+");
	if(ptr==NULL)
	{
		printf("Can't Open File!");
		exit(0);
	}
	else
	{
		fprintf(ptr,"%lld %s %lld %s %s\n",s.roll,s.name,s.mobile,s.city,s.email);
		printf("\n------------------------------------------------------");
		printf("\nRecord Stored Successfully !!\n");
		fclose(ptr);
		printf("\n");
		printf("Enter y to add new record : ");
		scanf("%*c%[^\n]",&a);
		if(a=='y')
		{
			title();
			newrecord();
		}
		else
		{
			title();
			display3();
		}
	}
	
}

void displayrecords()
{
	student s;
	char p;
	int i,j=1;
	FILE * ptr;
	ptr = fopen("details.txt","r");
	if(ptr==NULL)
	{
		printf("Can't Open File!");
		exit(0);
	}
	printf("\n\nS.No.\tRoll Number\tName\t\t\tMobile Number\t\tCity\t\tEmail-ID\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	while(fscanf(ptr,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
	{
		for(i=0;s.name[i]!=0;i++)
		{
			if(s.name[i]=='_')
			s.name[i]=' ';
		}
		printf("%d\t%lld\t%s\t\t%lld\t\t%s\t\t%s\n",j++,s.roll,s.name,s.mobile,s.city,s.email);
	}
	fclose(ptr);
	printf("\n\nEnter b to go back : ");
	scanf("%*c%[^\n]",&p);
	if(p)
	{
		title();
		display3();
	}
}

void modifyrecord()
{
	student s,s1;
	int i,f=0;
	char k;
	long long int r;
	printf("Enter Roll Number : ");
	scanf("%lld",&r);
	FILE * ptr;
	ptr = fopen("details.txt","r");
	if(ptr==NULL)
	{
		printf("Can't Open File!");
		exit(0);
	}
	while(fscanf(ptr,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
	{
		for(i=0;s.name[i]!=0;i++)
		{
			if(s.name[i]=='_')
			s.name[i]=' ';
		}
		if(s.roll==r)
		{
			f=1;
			printf("\n------------------------------------------------------\n");
			printf("Existing Details\n");
			printf("------------------------------------------------------\n\n");
			printf("Name \t\t:    %s\n",s.name);
			printf("Mobile Number \t:    %lld\n",s.mobile);
			printf("City \t\t:    %s\n",s.city);
			printf("Email-ID \t:    %s\n\n",s.email);
			printf("------------------------------------------------------\n");
			printf("Enter New Details\n");
			printf("------------------------------------------------------\n\n");
			printf("Name\t\t :    ");
			scanf("%*c%[^\n]",s1.name);
			for(i=0;s1.name[i]!=0;i++)
			{
				if(s1.name[i]==' ')
				s1.name[i]='_';
			}
			printf("Mobile Number\t :    ");
			scanf("%lld",&s1.mobile);
			printf("City\t\t :    ");
			scanf("%*c%[^\n]",s1.city);
			printf("Email-ID\t :    ");
			scanf("%*c%[^\n]",s1.email);
		}
	}
	fclose(ptr);
	if(f==0)
	{
		printf("\nPlease Enter Correct Roll Number!");
		sleep(3);
		title();
		modifyrecord();
	}
	ptr=fopen("details.txt","r");
	FILE * ptr1;
	ptr1=fopen("temp.txt","w");
	while(fscanf(ptr,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
	{
		if(s.roll!=r)
		{
			fprintf(ptr1,"%lld %s %lld %s %s\n",s.roll,s.name,s.mobile,s.city,s.email);
		}
		else
		{
			fprintf(ptr1,"%lld %s %lld %s %s\n",r,s1.name,s1.mobile,s1.city,s1.email);
			printf("\n------------------------------------------------------\n");
			printf("Record Modified Successfully!\n");
			printf("------------------------------------------------------");
		}
	}	
	fclose(ptr);
	fclose(ptr1);
	remove("details.txt");
	rename("temp.txt","details.txt");
	printf("\n\nEnter y to modify another record : ");
	scanf("%*c%[^\n]",&k);
	if(k=='y')
	{
		title();
		modifyrecord();
	}
	else
	{
		title();
		display3();
	}
	
}

void deleterecord()
{
	student s;
	int i,f=0;
	char c,k;
	long long int r;
	printf("Enter Roll Number : ");
	scanf("%lld",&r);
	FILE * ptr;
	ptr = fopen("details.txt","r");
	if(ptr==NULL)
	{
		printf("Can't Open File!");
		exit(0);
	}
	while(fscanf(ptr,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
	{
		for(i=0;s.name[i]!=0;i++)
		{
			if(s.name[i]=='_')
			s.name[i]=' ';
		}
		if(s.roll==r)
		{
			f=1;
			printf("\n------------------------------------------------------\n");
			printf("Student's Details\n");
			printf("------------------------------------------------------\n\n");
			printf("Name \t\t:    %s\n",s.name);
			printf("Mobile Number \t:    %lld\n",s.mobile);
			printf("City \t\t:    %s\n",s.city);
			printf("Email-ID \t:    %s\n\n",s.email);
			printf("------------------------------------------------------\n");
			printf("Enter y to delete this record : ");
			scanf("%*c%c",&c);
			printf("------------------------------------------------------\n");
		}
	}
	fclose(ptr);
	if(f==0)
	{
		printf("\nPlease enter valid Roll Number!");
		sleep(3);
		title();
		deleterecord();
	}
	ptr=fopen("details.txt","r");
	FILE * ptr1;
	ptr1=fopen("temp.txt","w");
	if(c=='y')
	{
		while(fscanf(ptr,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
		{
			if(s.roll!=r)
			fprintf(ptr1,"%lld %s %lld %s %s\n",s.roll,s.name,s.mobile,s.city,s.email);
		}
		fclose(ptr);
		fclose(ptr1);
		remove("details.txt");
		rename("temp.txt","details.txt");
		printf("Record Deleted Successfully!\n");	
	}
	else
	{
		title();
		display3();
	}
	printf("\nEnter y to Delete another record : ");
	scanf("%*c%[^\n]",&k);
	if(k=='y')
	{
		title();
		deleterecord();
	}
	else
	{
		title();
		display3();
	}
}

void addmarks()
{
	marks m;
	student s;
	char k;
	int i,f=0;
	long long int r;
	printf("Enter Roll Number : ");
	scanf("%lld",&r);
	FILE * ptr1;
	ptr1=fopen("details.txt","r");
	FILE * ptr;
	ptr=fopen("marks.txt","a");
	while(fscanf(ptr1,"%lld %s %lld %s %s",&s.roll,s.name,&s.mobile,s.city,s.email)!=EOF)
		{
			if(s.roll==r)
			{
				f=1;
				for(i=0;s.name[i]!=0;i++)
				{
					if(s.name[i]=='_')
					s.name[i]=' ';
				}
				printf("------------------------------------------------------\n");
				printf("Enter Marks of %s\n",s.name);
				printf("------------------------------------------------------\n\n");
				printf("Computer Programming Using C \t: ");
				scanf("%d",&m.c);
				printf("Internet Programming \t\t: ");
				scanf("%d",&m.ip);
				printf("Engineering Calculus \t\t: ");
				scanf("%d",&m.maths);
				fprintf(ptr,"%lld %d %d %d\n",r,m.c,m.ip,m.maths);
				printf("\n------------------------------------------------------\n");
				printf("Marks Stored Successfully!");
				printf("\n\nEnter y to add another student's marks : ");
				scanf("%*c%[^\n]",&k);
			}
		}
	fclose(ptr);
	fclose(ptr1);
	if(f==0)
	{
		printf("\nPlease Enter Valid Roll Number!");
		sleep(3);
		title();
		addmarks();
	}
	if(k=='y')
	{
		title();
		addmarks();
	}			
	else
	{
		title();
		display3();
	}
}

void viewmarks()
{
	long long int r,r1;
	int f=0;
	char k;
	marks m;
	FILE * ptr;
	ptr=fopen("marks.txt","r");
	printf("Enter Your Roll Number : ");
	scanf("%lld",&r);
	while(fscanf(ptr,"%lld %d %d %d",&r1,&m.c,&m.ip,&m.maths)!=EOF)
	{
		if(r1==r)
		{
			printf("Your Marks\n\n");
			printf("Computer Programming Using C \t: %d\n",m.c);
			printf("Internet Programming \t\t: %d\n",m.ip);
			printf("Engineering Calculus \t\t: %d\n",m.maths);
			f=1;
		}
	}
	if(f==0)
	{
		printf("\nPlease Enter Valid Roll Number!");
		sleep(3);
		title();
		viewmarks();
	}
	printf("\nEnter b to go back : ");
	scanf("%*c%[^\n]",&k);
	if(k)
	{
		title();
		display4();
	}
}

void playquiz()
{
	char a1,a2,a3,a4,a5,k;
	int score=0;
	printf("Q1. Who created C language?\n");
	printf("a. Dennis M. Ritchie\n");
	printf("b. Guido Van Rossum\n");
	printf("c. Michael Widenius\n");
	printf("d. James Gosling\n");
	printf("\nEnter your answer : ");
	scanf("%*c%[^\n]",&a1);
	if(a1=='a')
	score++;
	title();
	printf("Q2. Which of these keyword is an operator also?\n");
	printf("a. struct\n");
	printf("b. break\n");
	printf("c. sizeof\n");
	printf("d. typedef\n");
	printf("\nEnter your answer : ");
	scanf("%*c%[^\n]",&a2);
	if(a2=='c')
	score++;
	title();
	printf("Q3. Which keyword is used to create structures in C?\n");
	printf("a. typedef\n");
	printf("b. struct\n");
	printf("c. union\n");
	printf("d. struct()\n");
	printf("\nEnter your answer : ");
	scanf("%*c%[^\n]",&a3);
	if(a3=='b')
	score++;
	title();
	printf("Q4. Which header file contains exit()?\n");
	printf("a. stdio.h\n");
	printf("b. string.h\n");
	printf("c. stdarg.h\n");
	printf("d. stdlib.h\n");
	printf("\nEnter your answer : ");
	scanf("%*c%[^\n]",&a4);
	if(a4=='d')
	score++;
	title();
	printf("Q5. What is the minimum value of argc parameter of the main() function?\n");
	printf("a. 0\n");
	printf("b. 3\n");
	printf("c. 1\n");
	printf("d. 2\n");
	printf("\nEnter your answer : ");
	scanf("%*c%[^\n]",&a5);
	if(a5=='c')
	score++;
	title();
	printf("Your Score = %d\n\n",score);
	printf("Press y to Play Again : ");
	scanf("%*c%[^\n]",&k);
	if(k=='y')
	{
		title();
		playquiz();
	}
	else
	{
		title();
		display4();
	}
}

void display4()
{
	
	int c;
	
	printf("1. View your Marks\n");
	printf("2. Play a Quiz\n");
	printf("3. Go Back\n\n");
	printf("------------------------------------------------------\n");
	printf("Enter Your Choice : ");
	scanf("%d",&c);
	switch(c)
	{
		case 1: title();
				viewmarks();
				break;
		case 2: title();
				playquiz();
				break;
		case 3: title();
				display2();
				break;
		default:printf("Please Enter valid choice!");
				sleep(3);
				display4();
	}
}

void login()
{
	title();
	int f=0;
	char user[100],pass[100],user1[100],pass1[100];
	printf("Enter Username : ");
	scanf("%s",user);
	printf("Enter Password : ");
	scanf("%s",pass);
	FILE * ptr;
	ptr = fopen("users.txt","r");
	while(fscanf(ptr,"%s %s",user1,pass1)!=EOF)
	{
		if(strcmp(user,user1)==0 && strcmp(pass,pass1)==0)
		{
			f=1;
			title();
			printf("WELCOME @%s!\n\n",user);
			display4();
		}
	}
	if(f==0)
	{
		printf("\nYou are not Registered yet !!");
		sleep(3);
		display2();
	}
	fclose(ptr);
}

void reg()
{
	title();
	FILE * ptr;
	char username[100],password[100];
	printf("Enter Username : ");
	scanf("%s",username);
	printf("Enter Password : ");
	scanf("%s",password);
	ptr = fopen("users.txt","a+");
	if(ptr==NULL)
	{
		printf("Can't Open File!");
		exit(0);
	}
	fprintf(ptr,"%s %s\n",username,password);
	printf("\nYou are Successfully Registered !!");
	fclose(ptr);
	sleep(3);
	display2();
}

void display3()
{
	title();
	int c;
	printf("1. Enter new student's Record\n");
	printf("2. Display all Records\n");
	printf("3. Modify Records\n");
	printf("4. Delete Records\n");
	printf("5. Add students marks\n");
	printf("6. Go Back\n\n");
	printf("------------------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&c);
	printf("------------------------------------------------------\n");
	printf("\n");
	switch(c)
	{
		case 1: title();
				newrecord();
				break;
		case 2: title();
				displayrecords();
				break;
		case 3: title();
				modifyrecord();
				break;
		case 4: title();
				deleterecord();
				break;
		case 5: title();
				addmarks();
				break;
		case 6: home();
				break;
		default:display3();
	}
}

void display1()
{
	title();
	int i;
	char user[100],pass[100];
	printf("Enter Username : ");
	scanf("%s",user);
	printf("Enter Password : ");
	scanf("%s",pass);
	if(strcmp(user,"admin01")==0 && strcmp(pass,"1234")==0)
	{
		printf("\nLogging in");
		for(i=0;i<5;i++)
		{
			printf(".");
			sleep(1);
		}
		display3();
	}
	else
	{
		printf("\nIncorrect Username or Password !!\n");
		sleep(3);
		display1();
	}
}

void display2()
{
	title();
	int c;
	printf("1. Register\n");
	printf("2. Login\n");
	printf("3. Go Back\n\n");
	printf("------------------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&c);
	printf("------------------------------------------------------\n");
	printf("\n");
	if(c==1)
	reg();
	else if(c==2)
	login();
	else if(c==3)
	{
		title();
		home();
	}
	else
	{
		printf("Please Enter Valid Choice!");
		sleep(3);
		display2();
	}
}

void home()
{
	title();
	int c;
	printf("1. Admin Login\n");
	printf("2. Student Login\n");
	printf("3. Exit\n\n");
	printf("------------------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&c);
	printf("------------------------------------------------------\n");
	printf("\n");
	switch(c)
	{
		case 1: display1();
				break;
		case 2: display2();
				break;
		case 3: printf("ThankYou!");
				exit(0);
		default:printf("INVALID CHOICE!!");
				sleep(2);
				home();
	}
}

int main()
{
	home();
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int actop1=0;
int sleepertop1=0;
int generaltop1=0;
int actop2=0;
int sleepertop2=0;
int generaltop2=0;
int actop3=0;
int sleepertop3=0;
int generaltop3=0;
int actop4=0;
int sleepertop4=0;
int generaltop4=0;
int top=-1;
struct node
{
	char station[25];
	int train_number;
	struct node *next;
}*head1,*temp,*head2,*head3,*head4;
struct details
{
	int username;
	char password[25];
}loginstack[100],abc1;
int dtop=-1;
struct passengerdetails
{
	char from[25],to[25],name[25],gender[10],CLASS[25];
	int age,seat,bill;
}stackdetails[100];
void details();
void detailscheck(int);
void searchtrains();
void createdtrain1();
void createdtrain2();
void createdtrain3();
void createdtrain4();
 int billpayments(int);
  void display();
void main()
{
	int opt;
	while(1)
	{
		
		printf("\t\t=================================================\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|        -----------------------------          |\n");
  printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
  printf("\t\t|        -----------------------------          |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|              BROUGHT TO YOU BY                |\n");
  printf("\t\t|              |SVT.org|                        |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t=================================================\n\n\n");
		printf("1)login   2)already have an account   3)break\n");
		scanf("%d",&opt);
		if(opt==1)
	    detailscheck(opt);
		else if(opt==2)
		detailscheck(opt);
		else if(opt==3)
		break;
	}
}
void detailscheck(int opt)
{
	if(opt==1)
	{
		top++;
		printf("enter phone_number or username:\n");
		scanf("%d",&abc1.username);
		printf("enter your password:\n");
		scanf("%s",abc1.password);
		loginstack[top].username=abc1.username;
		strcpy((loginstack[top].password),(abc1.password));
		printf("------->YOUR PAGE IS CREATED__PROCEED TO BOOK YOUR TICKETS<-------\n");
		searchtrains();
	}
	else if(opt==2)
	{ 
	  int i;
		printf("enter phone_number or username:\n");
		scanf("%d",&abc1.username);
		printf("enter your password:\n");
		scanf("%s",abc1.password);
		if(top==-1)
		{
			printf("------>STILL ACCOUNT NOT CREATED<-----------\n");
			return;
		}
		for(i=top;i>=0;i--)
		{
			if(loginstack[i].username==abc1.username && !strcmp(abc1.password,loginstack[i].password))
			{
				printf("---------->YOUR ACCOUNT IS VERIFIED<----------------\n");
				searchtrains();
			}
			else if(loginstack[i].username!=abc1.username || !strcmp(abc1.password,loginstack[i].password))
			{
				printf("wait %d seconds\n",top);
			}
			else if(i==0)
			printf("------->INVALID PASSWORD OR USERNAME<--------\n");
		}
	}
}
void searchtrains()
{ 
    printf("=======AVAILABLE TRAINS ARE==========\n");
    printf("TRAIN NUMBER  TRAIN NAME  TRAIN TYPE  RUN DAYS  DEPARTURE  TIME(HRS) ARRIVAL TIME(HRS)\n");
   printf("enter 1)12267  MUMBAI CENTRAL - AHMEDABAD AC DURONTO EXP  DURONTO  M,T,W,T,F,S,S  23:25  05:55\n");
   printf("enter 2)22206  MADURAI - CHENNAI CENTRAL AC DURONTO EXPRESS  DURONTO  TUE,THU  22:40  07:20\n");
   printf("enter 3)22201  KOLKATA SEALDAH - PURI DURONTO EXPRESS  DURONTO  M,W,F  20:00  04:00\n");
   printf("enter 4)22204  SECUNDERABAD - VISAKHAPATNAM AC DURONTO EXPRESS  DURONTO  M,W,S  20:15  06:35\n");
   int opt1;
   printf("enter your train choice number:\n");
   scanf("%d",&opt1);
   printf("--->THESE STATIONS ARE AVAILABLE<---:\n");
    switch(opt1)
    {
    case 1:
 	createdtrain1();
 	break;
 	case 2:
	createdtrain2();
 	break;
 	case 3:
 	createdtrain3();
 	break;
	case 4:
 	createdtrain4();
 	break;	  
    }
    int n,i;
    printf("\nhow many tickets are booking:\n");
   scanf("%d",&n);
   	int choice;
   for(i=1;i<=n;i++)
   {
   	details();
   	printf("1)AC    2)SLEEPER    3)GENERAL\n");
   	if(opt1==1)
   	{
   		scanf("%d",&choice);
   		if(choice==1)
   		{
   		stackdetails[dtop].seat= ++actop1;
   		strcpy(stackdetails[dtop].CLASS,"AC");
   	   }
   		else if(choice==2)
   		stackdetails[dtop].seat= ++sleepertop1;
   		else if(choice==3)
   		stackdetails[dtop].seat= ++generaltop1;
    }
    else if(opt1==2)
   	{
   		scanf("%d",&choice);
   		if(choice==1)
   		stackdetails[dtop].seat= ++actop2;
   		else if(choice==2)
   		stackdetails[dtop].seat= ++sleepertop2;
   		else if(choice==3)
   		stackdetails[dtop].seat= ++generaltop2;
    }
    else if(opt1==3)
   	{
   		scanf("%d",&choice);
   		if(choice==1)
   		stackdetails[dtop].seat= ++actop3;
   		else if(choice==2)
   		stackdetails[dtop].seat= ++sleepertop3;
   		else if(choice==3)
   		stackdetails[dtop].seat= ++generaltop3;
    }
    else if(opt1==4)
   	{
   		scanf("%d",&choice);
   		if(choice==1)
   		stackdetails[dtop].seat= ++actop4;
   		else if(choice==2)
   		stackdetails[dtop].seat= ++sleepertop4;
   		else if(choice==3)
   		stackdetails[dtop].seat= ++generaltop4;
    }
    int x=billpayments(opt1);
   stackdetails[dtop].bill=x*100;
  display();
   }
}
void createdtrain1()
{
	struct node *station1,*station2,*station3,*station4;
	station1=(struct node*)malloc(sizeof(struct node));
	head1=station1;
	char stations1[25]={'M','U','M','B','A','I','\0'};
	station1->train_number=12267;
	strcpy(station1->station,stations1);
	station2=(struct node*)malloc(sizeof(struct node));
	char stations2[25]={'A','H','M','E','D','A','B','A','D','\0'};
	strcpy(station2->station,stations2);
	station1->next=station2;
	station3=(struct node*)malloc(sizeof(struct node));
	char stations3[25]="SURENDRANAGAR\0";
	strcpy(station3->station,stations3);
	station2->next=station3;
	station4=(struct node*)malloc(sizeof(struct node));
	char stations4[25]="RAJKOT\0";
	strcpy(station4->station,stations4);
	station3->next=station4;
	station4->next=NULL;
	temp=head1;
	while(temp!=NULL)
	{
		printf("%s   ",temp->station);
		temp=temp->next;
	}
}
void createdtrain2()
{
	struct node *station1,*station2,*station3,*station4;
	station1=(struct node*)malloc(sizeof(struct node));
	head2=station1;
	station1->train_number=22206;
	char stations1[25]="MADHURI";
	strcpy(station1->station,stations1);
	station2=(struct node*)malloc(sizeof(struct node));
	char stations2[25]="SALEM";
	strcpy(station2->station,stations2);
	station1->next=station2;
	station3=(struct node*)malloc(sizeof(struct node));
	char stations3[25]="VELLORE";
	strcpy(station3->station,stations3);
	station2->next=station3;
	station4=(struct node*)malloc(sizeof(struct node));
	char stations4[25]="CHENNAI";
	strcpy(station4->station,stations4);
	station3->next=station4;
	station4->next=NULL;
	temp=head2;
	while(temp!=NULL)
	{
		printf("%s ",temp->station);
		temp=temp->next;
	}
}
void createdtrain3()
{
	char station[25];
	struct node *station1,*station2,*station3,*station4;
		station1=(struct node*)malloc(sizeof(struct node));
	head3=station1;
	char stations1[25]="KOLKATTA";
	station1->train_number=22201;
	strcpy(station1->station,station);
	station2=(struct node*)malloc(sizeof(struct node));
	char stations2[25]="KHARAGPUR";
	strcpy(station2->station,stations2);
	station1->next=station2;
	station3=(struct node*)malloc(sizeof(struct node));
	char stations3[25]="BHUBANESHWAR";
	strcpy(station3->station,stations3);
	station2->next=station3;
	station4=(struct node*)malloc(sizeof(struct node));
	char stations4[25]="PURI";
	strcpy(station4->station,stations4);
	station3->next=station4;
	station4->next=NULL;
	temp=head3;
	while(temp!=NULL)
	{
		printf("%s ",temp->station);
		temp=temp->next;
	}
 } 
 void createdtrain4()
{
	char station[25];
	struct node *station1,*station2,*station3,*station4;
	station1=(struct node*)malloc(sizeof(struct node));
	head4=station1;
	char stations1[25]="SECUNDRABAD";
	station1->train_number=22204;
	strcpy(station1->station,stations1);
	station2=(struct node*)malloc(sizeof(struct node));
	char stations2[25]="KAGIPET";
	strcpy(station2->station,stations2);
	station1->next=station2;
	station3=(struct node*)malloc(sizeof(struct node));
	char stations3[25]="MIRYALAGUDA";
	strcpy(station3->station,stations3);
	station2->next=station3;
	station4=(struct node*)malloc(sizeof(struct node));
	char stations4[25]="VISAKHAPATNAM";
	strcpy(station4->station,stations4);
	station3->next=station4;
	station4->next=NULL;
	temp=head4;
	while(temp!=NULL)
	{
		printf("%s ",temp->station);
		temp=temp->next;
	}
} 
 void details()
 {
 	dtop++;
    printf("enter starting point:\n");
    scanf("%s",stackdetails[dtop].from);
    printf("destination:\n");
    scanf("%s",stackdetails[dtop].to);
    printf("enter your name:\n");
    scanf("%s",stackdetails[dtop].name);
    printf("enter your gender:\n");
    scanf("%s",stackdetails[dtop].gender);
    printf("enter your age:\n");
    scanf("%d",&stackdetails[dtop].age);
 }
 void display()
 {
 	int i;
 	for(i=dtop;i>=0;i--)
 	{
 		printf("first name : %s\n",stackdetails[i].name);
 		printf(" seat number : %d \n",stackdetails[i].seat);
 		printf(" class : %s \n",stackdetails[i].CLASS);
 		printf(" pay bill : %d \n",stackdetails[i].bill);
	 }
 }
int billpayments(int opt1)
 {
 	int count=0;
 	if(opt1==1)
 		temp=head1;
 		else if(opt1==2)
 		temp=head2;
 		else if(opt1==3)
 		temp=head3;
 		else if(opt1==4)
 		temp=head4;
 		while(temp!=NULL)
 		{
 			if(!strcmp(stackdetails[dtop].from,temp->station))
 			{
 			while(!strcmp(stackdetails[dtop].from,temp->station) || count >=1)
 			{
 				if(!strcmp(stackdetails[dtop].to,temp->station))
 				 {
 					count++;
 					break;
				 }
				 count++;
				 temp=temp->next;
			 }
			 break;
		    }
		else
			 temp=temp->next;
		 }
		 printf("%d count\n",count-1);
		 		 
		 return count-1;

 }

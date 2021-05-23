#include<stdio.h>
int calculate(int);
void billing(int,char[50],char[12],char[50],int,int);
struct bill
{
int accno;
char name[20];
char phone[15];
char address[20];
int units;
}b[100];
int calculate(int c)
{
int amount=0;
if(c<=0)
{
printf("No units used...... Meter is faulty or dead...\n");
}
else
{
        if(c<=100)
        {
                amount=(c*1);
        }
        else if(c<=200)
        {
                amount=(100*1)+((c-100)*1.5);
        }
        else if(c<=300)
        {
                amount=(100*1)+(100*1.5)+((c-200)*2);
        }
        else if(c>300)
        {
                printf("here");
                amount=(100*1)+(100*1.5)+(100*2)+((c-300)*2.5);
        }
}
return amount;
}
void billing(int mno, char nam[50],char ph[12],char add[50],int un, int am)
{
	FILE *n;
	n=fopen("bills.txt","w+");
	fprintf(n,"\tELECTRICITY BILL\n METER NO.=\t%d\n NAME=\t%s\n PHONE NO.=\t%s\n ADDRESS=\t%s\n UNITS=\t%d\n AMMOUNT=\t%d\n",mno,nam,ph,add,un,am);
	fprintf(n,"\n");
	fprintf(n,"Please Pay The bill within 15 days of Issue\n");
	fprintf(n,"SAVE ELECTRICITY SAVE EARTH\n");
	fprintf(n,"\t..THANK YOU..\t");
	fclose(n);
	
}

int main()
{
int n,i,x[100],temp,ch;
printf("MENU:\n 1.New entery\n 2.Bill\n 3.Information Page\n 4.Complains and coustomer review\n 0.EXIT\n");
printf("Enter the choice");
scanf("%d",&ch);
while(ch!=0)
{
if(ch==1)
{
FILE *f;
f=fopen("a.txt","a+");
printf("enter the number of users in the area");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("enter the meter number");
	scanf("%d",&b[i].accno);
	printf("Name:");
	scanf("%s",b[i].name);
	printf("phone:");
      	scanf("%s",b[i].phone);
	printf("address:");
        scanf("%s",b[i].address);
	printf("enter the number of units");
	scanf("%d",&b[i].units);
}
for(int j=0;j<n;j++)
{
	x[j]=calculate(b[j].units);
}
for(i=0;i<n;i++)
{
	printf("Details:/n");
	printf("Meter Number:%d\n",b[i].accno);
	printf("Name:%s\n",b[i].name);
	printf("Phone Number:%s\n",b[i].phone);
	printf("%Address:%s\n",b[i].address);
	printf("Units:%d\n",b[i].units);
	printf("Amount:%d\n",x[i]);
	fprintf(f,"%d\t%s\t%s\t%s\t%d\t%d\n",b[i].accno,b[i].name,b[i].phone,b[i].address,b[i].units,x[i]);
	printf("Please pay the bill within in 15 days of recieving the bill\n");
	printf("\n");
	
}
fclose(f);
printf("Press 2 IF YOU WANT TO DOWNLOAD A SOFTCOPY OF YOUR BILL AND HELP US IN SAVING PAPER\n");
}
else if(ch==2)
{	
	printf("GENERATING YOUR BILL\n");
	billing(b[i].accno,b[i].name,b[i].phone,b[i].address,b[i].units,x[i]);
	printf("BILL IS DOWNLOADED...PLEASE KINDLY FIND THE ATTACHMENT\n");
	printf("THANK YOU FOR SAVING A SHEET OF PAPER");
}
else if(ch==3)
{
	char info[1000];
	FILE *f;
	f=fopen("info.txt","r");
	while((fgets(info,1000,f))!=NULL)
	{	
		printf("%s",info);
	}
	fclose(f);
}
else if(ch==4)
{
	FILE *fi;
	fi=fopen("complains.txt","a+");
	int c;
	printf("WELCOME TO THE CUSTOMER REVIEW FORUM\n");
	printf("Press:\n 1.To file a complain\n 2.To view the recent complains\n 0.EXIT\n");
	printf("Enter your choice\n");
	scanf("%d",&c);
	while(c!=0)
	{
		if(c==1)
		{
			FILE *f;
			f=fopen("complains.txt","a+");
			int mn;
			char na[20],comp[100];
			printf("Enter your meter number\n");
			scanf("%d",&mn);
			printf("Enter your name");
			scanf("%s",na);
			printf("Enter the complain");
			scanf("%s",comp);
			fprintf(f,"Meter Number:%d\n Name:%s\n Complain:%s\n",mn,na,comp);
			printf("Your Complain is filled\n");
			printf("\n");
			fclose(f);
			printf("Press:\n 1.To file a complain\n 2.To view the recent complains\n 0.EXIT\n");
			printf("Enter your choice\n");
			scanf("%d",&c);
			
			//break;
			
		}
		else if(c==2)
		{
			FILE *f;
			f=fopen("complains.txt","r");
			char get[500];
			while((fgets(get,500,f))!=NULL)
			{
				printf("%s",get);
			}
			fclose(f);
			printf("Press:\n 1.To file a complain\n 2.To view the recent complains\n 0.EXIT\n");
			printf("Enter your choice\n");
			scanf("%d",&c);
			
			//break;
		}
		
	}
	fclose(fi);
}
printf("MENU:\n 1.New entery\n 2.Bill\n 3.Information Page\n 4.Complains and coustomer review\n 0.EXIT\n");
printf("Enter the choice");
scanf("%d",&ch);
}
return 0;
}





















#include<stdio.h>
struct details
{
	int id[100], cash[100];	
	//4 array--->   1st->id  2nd->withdraw or deposit  3rd->amount  4-> balance
	int hisid[100], wds[100], amount[100], balance[100]; int size;
};
struct details d;
//For Saving Details
void historysaver(int id, int wdss, int amt, int bal)
{
	d.hisid[d.size]=id;
	d.wds[d.size]=wdss;
	d.amount[d.size]=amt;
	d.balance[d.size]=bal;
	d.size+=1;
}
int initializer()
{
	int users,i;
	printf("Enter the No. of Users: "); scanf("%d", &users);
	for(i=0;i<users;i++)
	{
		d.id[i]=0+i;
		d.cash[i]=1000;
	}
	d.size=0;
	system("cls");
	return users;
}
void printer()
{
	int size=d.size,i;
	printf("------------------- Cash Flow Receipt -------------------\n\n");
	printf("S.No.\tID\tStatus  \tAmount\tBalance\t\n\n");
	for(i=0;i<size;i++)
	{
		printf("%d.\t%d\t%s\t%d\t%d\n", (i+1), d.hisid[i],((d.wds[i]==0)?"Deposit ":"Withdraw"),d.amount[i],d.balance[i]);
	}
	system("pause");
	system("cls");
}
void showusers(int size)
{
	int i;
	printf("Showing Account Details\n");
	printf("\nID\tAmount\n");
	for(i=0;i<size;i++)
	{
		//d.id, d.cash
		printf("\n%d\t%d", d.id[i], d.cash[i]);
	}
	printf("\n");
	system("pause");
	system("cls");
}
int main()
{
	
	int idinput=0, size, i, option1;
	size=initializer();
	while(1)
	{
		system("cls");
		printf("1. Show Cash Flow Receipt\n2. ATM\n3. Show All Acc.\nEnter the Option: "); scanf("%d", &option1);
		system("cls");
		switch(option1)
		{
			case 1:
				printer(); break;
			case 2:
				printf("Enter ID: "); scanf("%d", &idinput);
		int customerid;
		int flag=0;
		for(i=0;i<size;i++)
		{
			if(d.id[i]==idinput){
				customerid=i;
				flag=1;
			}
		}
			if (flag==0){
				printf("Enter the Valid ID\n");
				continue;
			}
			else
			{
				//flag=0;
				int option, amount; 
				system("cls");
				printf("ID: %d\n", d.id[customerid]);
				printf("1. Deposit Amount\n2. Withdraw Amount\nEnter the Option to Continue...: "); scanf("%d", &option);
				switch(option) 
				{
					case 1:
						printf("Enter the Amount to Deposit: "); scanf("%d", &amount);
						d.cash[customerid]+=amount;
						historysaver(d.id[customerid],0,amount,d.cash[customerid]);
						break;
					case 2:
						printf("Enter the Amount to Withdraw: "); scanf("%d", &amount);
						d.cash[customerid]-=amount;
						historysaver(d.id[customerid],1,amount,d.cash[customerid]);
						break;
					default:
						printf("Enter the Valid Option\n");
						break;
				}
			}
				break;
			case 3: //show all accounts
				showusers(size);
				break;
			default:
				printf("Enter the Proper Option !!\n");
				system("pause");
				system("cls");
		}
		
		
	}
	return 0;
}

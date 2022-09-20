#include<iostream>
#include<cstring>

class cBank_employee
{
	private:
	char ID[11];
	char pass[9];

	public:
		cBank_employee():ID("0123456789"),pass("12345678"){}    //could be assigned if we have more than one emp but i assumd we have only one for purpose of ease tracing
	int acc_check(void)
		{
			int x=0;
			char emp_id[11];
			char emp_pass[9];
			std::cout<<"Enter your emp ID"<<std::endl;
			std::cin.get(emp_id,11);
			std::cin.ignore();
			//std::cout<<"your emp ID is"<<emp_id<<std::endl;
			std::cout<<"Enter your emp pass"<<std::endl;
			std::cin.get(emp_pass,9);
			std::cin.ignore();
			//std::cout<<"your emp pass is"<<emp_pass<<std::endl;
			
				if(strcmp(emp_id,ID)==0 && strcmp(emp_pass,pass)==0)
				x=1;
			
			return x;
		}	
		
};

struct Bank_ID
{
	char ID[11];
	char pass[9];
	int balance;
};

enum status
{
	closed=0,
	restricted=1,
	active=2,
};

class cBank_acc
{
	private:
		char name[30];
		char address[30];
		int  age;
		char national_id[15];
		char G_national_id[15];
		struct Bank_ID id;
		enum status st;
	
	public:
		
		void create_acc(void)
	{	
		
		st=active;
		
		std::cout<<"please enter your name"<<std::endl;
		std::cin.get(name,30);
		
		std::cin.ignore();

		std::cout<<"please enter your address"<<std::endl;
		std::cin.get(address,30);
		std::cin.ignore();

		std::cout<<"please enter your age"<<std::endl;
		std::cin>>age;
		std::cin.ignore();

		if(age<21)
		{
			std::cout<<"please enter your grudian ID"<<std::endl;
			std::cin.get(G_national_id,15);
			std::cin.ignore();
			for(int i=0;i<10;i++)
				{	
				 int j=9-i;
				 id.ID[i]=G_national_id[j];
				 
				 if(i<8)
						id.pass[i]= G_national_id[j];
				
				}
			id.ID[10]='\0';
			id.pass[8]='\0';

	
		}
		else
		{
			std::cout<<"please enter your national ID"<<std::endl;
			std::cin.get(national_id,15);
			std::cin.ignore();
				for(int i=0;i<10;i++)
					{	
					 int j=9-i;
				
					 id.ID[i]=national_id[j];
					 
					 if(i<8)
						
							id.pass[i]= national_id[j];
						
					}
			id.ID[10]='\0';
			id.pass[8]='\0';
		
	
		}

	}

		void Admin(cBank_acc *users)
	{
		
		
		char entered[11];
		char choose;
		int ind;
		char stat;
		int trans;
		int cash;
		int add;
		int found=0;
				std::cout<<"Enter your Bank account ID"<<std::endl;
				std::cin.get(entered,11);
				std::cin.ignore();
					for(int i=0;i<10;i++)
				{
					
					if (strcmp(entered,users[i].id.ID)==0)
					{
						std::cout<<"choose"<<std::endl<<"0:to make a transaction"<<std::endl<<"1:to change account status"<<std::endl<<"2:to get cash"<<std::endl<<"3:to deposit in account"<<std::endl<<"4:to return to main menu"<<std::endl;
						std::cin>>choose;
						std::cin.ignore();
						switch(choose)
						{
							case '0':
								std::cout<<"your balance is "<<users[i].id.balance<<std::endl;
								std::cout<<"Enter amount of money you would transfer"<<std::endl;
								std::cin>>trans;
								std::cin.ignore();	 
								if(trans<=users[i].id.balance && users[i].st==active)
								{
									ind=make_trans(trans,users);
									if(ind != 0)
									{
									users[i].id.balance=users[i].id.balance-trans;
									std::cout<<"balance of "<<users[i].name<<" now is "<<users[i].id.balance<<std::endl;
									}	
								}
								else
									std::cout<<"transaction is failed"<<std::endl;
								break;
							
							case '1':
								std::cout<<"Enter the status you want "<<std::endl<<"0- Set Account to Active State"<<std::endl<<"1- Set Account to Restricted State"<<std::endl<<"2- Set Account to Closed"<<std::endl;
								std::cin>>stat;
								std::cin.ignore();
								switch(stat)
								{
									case '0':
									users[i].st=active;
									break;
									
									case '1':
									users[i].st=restricted;
									break;
									
									case '2':
									users[i].st=closed;
									break;
									
								}
								std::cout<<"your staus now is "<<users[i].st<<std::endl;
								break;
								
							case '2':
								std::cout<<"balance of "<<users[i].name<<" is "<<users[i].id.balance<<std::endl;
								std::cout<<"Enter amount of money you would get"<<std::endl;
								std::cin>>cash;
								std::cin.ignore();	 
								if(cash<=users[i].id.balance)
								{
									users[i].id.balance=users[i].id.balance-cash;
									std::cout<<"balance of "<<users[i].name<<" now is "<<users[i].id.balance<<std::endl;
								}
								break;
						

							case '3':
								std::cout<<"Enter amount of money you would add"<<std::endl;
								std::cin>>add;
								std::cin.ignore();	 
								users[i].id.balance=users[i].id.balance+add;
								std::cout<<"balance of "<<users[i].name<<" now is "<<users[i].id.balance<<std::endl;
								break;
							
							case '4':
								Admin(users);
								break;
						}	
					
						found++;
						break;
					}
					
				
				}
				if (found==0)
				std::cout<<"No match found"<<std::endl;
	}	
	
		int make_trans(int trans,cBank_acc *users)
	{
	char entered[11];
	int ind=0;
	
	std::cout<<"Enter ID of Bank account you want transfer to "<<std::endl;
	std::cin.get(entered,11);
	std::cin.ignore();

	for(int i=0;i<3;i++)
	{
		
		if (strcmp(entered,users[i].id.ID)==0 && users[i].st==active)
		{
			std::cout<<"balance of "<<users[i].name<<" is "<<users[i].id.balance<<std::endl;
			users[i].id.balance=users[i].id.balance+trans;
			std::cout<<"balance of "<<users[i].name<<" now is "<<users[i].id.balance<<std::endl;
			ind++;
			break;
		}
	}
	if (ind==0)
		std::cout<<"transaction is failed"<<std::endl;
	
	return ind;
}

		void Client(cBank_acc *users)
		{
			char E_C_ID[11];
			char E_C_Pass[9];
			char choosen;
			int trans;
			int ind;
			char new_pass[9];
			int cash;
			int add;
			int found=0;
			
			std::cout<<"Enter your Bank account ID"<<std::endl;
			std::cin.get(E_C_ID,11);
			std::cin.ignore();
			for(int i=0;i<10;i++)
			{
			
				if(strcmp(E_C_ID,users[i].id.ID)==0 )
				{
					std::cout<<"Enter your Bank account password"<<std::endl;
					std::cin.get(E_C_Pass,9);
					std::cin.ignore();
					
					if(strcmp(E_C_Pass,users[i].id.pass)==0)
					{
						
						std::cout<<"choose"<<std::endl<<"0:to make a transaction"<<std::endl<<"1:to change account password"<<std::endl<<"2:to get cash"<<std::endl<<"3:to deposit in account"<<std::endl<<"4:to return to main menu"<<std::endl;
						std::cin>>choosen;
						std::cin.ignore();
						switch(choosen)
						{
							case '0':
								std::cout<<"your balance is "<<users[i].id.balance<<std::endl;
								std::cout<<"Enter amount of money you would transfer"<<std::endl;
								std::cin>>trans;
								std::cin.ignore();	 
								if(trans <= users[i].id.balance && users[i].st==active)
								{
									ind=make_trans(trans,users);
									if(ind != 0)
									{
									users[i].id.balance=users[i].id.balance-trans;
									std::cout<<" balance of "<<users[i].name<<" now is "<<users[i].id.balance<<std::endl;
									}	
								}
								else
									std::cout<<"transaction is failed"<<std::endl;
								break;
							
							
							case '1':
								std::cout<<"Enter the new password"<<std::endl;
								std::cin.get(new_pass,9);
								std::cin.ignore();
								
								strcpy(users[i].id.pass,new_pass);
								std::cout<<"the new password of "<<users[i].name<<" is "<<users[i].id.pass<<std::endl;
								break;	
							
							case '2':
								std::cout<<"Enter amount of money you would get"<<std::endl;
								std::cin>>cash;
								std::cin.ignore();	 
								if(cash<=users[i].id.balance)
								{
									users[i].id.balance=users[i].id.balance-cash;
									std::cout<<"balance now of "<<users[i].name<<" is "<<users[i].id.balance<<std::endl;
									
								}
								break;
						

							case '3':
								std::cout<<"Enter amount of money you would add"<<std::endl;
								std::cin>>add;
								std::cin.ignore();	 
								users[i].id.balance=users[i].id.balance+add;
								std::cout<<"balance now of "<<users[i].name<<" is "<<users[i].id.balance<<std::endl;
								break;
								
							case '4':
								Client(users);
						}
					}	
					found++;
					break;
					
				}
			
			}
			if (found==0)
				std::cout<<"No match found"<<std::endl;
		}	
	
	void print()
	{

std::cout<<"Bank ID of "<<name<<" is "<<id.ID<<std::endl;	
std::cout<<"Bank PASSWORD is "<<id.pass<<"			for purpose of tracing "<<std::endl;	


	}
	
};



	int main()
{
	int c;
	char feature;
	char action;
	cBank_acc users[10];
	cBank_employee emp1;
	while (1)
	{
		std::cout<<"choose the feature you want"<<std::endl<<"1-admin window"<<std::endl<<"2-client window"<<std::endl<<"3-Exit"<<std::endl;
		std::cin>>feature;
		std::cin.ignore();
		switch(feature)
		{
			case '1':
				if(emp1.acc_check()==1)
				{
					std::cout<<"choose the action you want"<<std::endl<<"1-creat account"<<std::endl<<"2-open account"<<std::endl;
					std::cin>>action;
					std::cin.ignore();
					switch(action)
					{
							case '1':
								std::cout<<"Enter number of accounts to be created"<<std::endl;
								std::cin>>c;
								std::cin.ignore();
								for(int i=0;i<c;i++)
									{
									users[i].create_acc();
									users[i].print();
									}
								break;
							
							case '2':
								users[1].Admin(users);
								break;
					}
				}
				else
					std::cout<<"Wrong EMP ID or PASSWORD"<<std::endl;
			break;
			
			case '2':
				users[1].Client(users);
				break;
			
			case '3':
				break;

		}
		if(feature=='3')
			break;
	} 
}

#include <vector>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<ctime>
using namespace std;
bool uniqueName(vector<string> user,string x)
{ 
  for(int i=0;i<user.size();i++)
  if(user[i].find(x)!=-1) return 0;
  return 1;
}
bool uniqueCardnum(vector<int> card,int x)
{ 

  for(int i=0;i<card.size();i++)
  if(x==card[i]) return 0;
  return 1;

}

void Admin( vector<string> &v_user,vector<int> &v_balance, vector<int> &v_card_num, vector<int> &v_PIN  )
{
int x,choice,balance,card_num,PIN;
char name[81];
string pass1="1234",pass2;
cout<<"Enter your password"<<endl;
cin>>pass2;
while(pass1!=pass2)
{
	cout<<"Invalid password"<<endl;
	cin>>pass2;
}
while(true)
{
	srand(0);
	cout<<"For Add Client Press 1 "<<endl;
	cout<<"For View All Records Press 2 "<<endl;
	cout<<"For Exit Press 3 "<<endl;
	cin>>choice;
	if(choice==1)
	{
		cout<<"Enter his Name"<<endl;
		cin>>name;
		while(!uniqueName(v_user,name))
		{
	       cout<<"this name is already exist"<<endl;
	       cin>>name;
		}
		v_user.push_back(name);
		cout<<"enter his balance"<<endl;
		cin>>balance;
		v_balance.push_back(balance);
	  card_num=rand()%1001+10000;
	  while(!uniqueCardnum(v_card_num,card_num))
	  {
			card_num=rand()%1001+10000;
	  }
		v_card_num.push_back(card_num);
	  PIN=rand()%1001+10000;
	  v_PIN.push_back(PIN);
	  cout<<"the client card number is "<<card_num<<endl;
	  cout<<"the client PIN is "<<PIN<<endl;
	  fstream info("Clients.txt",ios::out);
	   for(int i=0;i<v_user.size();i++)
	   {
			info<<v_user[i]<<"\t";
			info<<v_card_num[i]<<"\t";
			info<<v_balance[i]<<"\t";
			info<<v_PIN[i]<<"\t";
	   }
	   info.close();
	}
	else if(choice==2)
	{
		string myname;
		cout<<"\n\n\n";
 cout<<setw(18)<<"Name"<<setw(18)<<"Card #"<<setw(18)<<"Balance"<<endl;
 cout<<"----------------------------------------------------------------------------\n";
 fstream show("Clients.txt",ios::in);
     while(!show.eof())
     {
			show>>myname;
			show>>balance;
			show>>card_num;
			show>>PIN;
		    cout<<setw(15)<<myname<<"\t";
			cout<<setw(15)<<balance<<"\t";
			cout<<setw(15)<<card_num<<"\t";
			cout<<setw(15)<<PIN<<endl;
			
	 }
	 show.close();
	}
	else if(choice==3)
	break;
}
}

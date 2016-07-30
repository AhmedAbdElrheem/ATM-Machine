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
bool search(vector<string> user,string name){
	for(int i=0;i<user.size();i++){
		if(name==user[i]){
			return i;
		}
		else
		return 0;
	}
}
void client(vector<string> &v_user,string name){
	int location;
	while(!search(v_user,name)){
		cout<<"Invalid user name"<<endl;
		cin>>name;
    }
    location=search(v_user, name);
    cout<<v_user[location]<<endl;
    cout<<info<<v_card_num[location]<<"\t";
	cout<<v_balance[location]<<"\t";
	cout<<v_PIN[i]<<"\t";	  
}

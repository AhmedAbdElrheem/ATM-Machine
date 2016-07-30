#include <iostream>
#include<vector>
#include<string>
#include <cstdlib>

#include<fstream>
#include<windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Admin(vector<string> &v_user,vector<int> &v_balance, vector<int>&v_card_num, vector<int>&v_PIN  );
int main(int argc, char *argv[]) {
	vector<string> v_user;
	vector<int> v_balance;
	vector<int>v_card_num;
	vector<int>v_PIN;
	ifstream fill;
fill.open("Clients.txt");

string y;
while(fill>>y)
{int x;

v_user.push_back(y);

fill>>x;
v_balance.push_back(x);

fill>>x;
v_card_num.push_back(x);

fill>>x;
v_PIN.push_back(x);
}

fill.close();
	 Admin(v_user,v_balance,v_card_num,v_PIN  );
	return 0;
}

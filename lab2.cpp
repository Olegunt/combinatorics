#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

using namespace std;

string romnum = "CLXVI";
vector <string> rep;

//================================================

void sdvig(int order)
{
	char first_elem = romnum[0];
	romnum[0] = romnum [order - 1];

	for(int i = order - 2; i >= 1; --i)
	{
		romnum[i+1] = romnum[i];
	}
	romnum[1] = first_elem;
}

//================================================

void color_str_output(string str)
{
    cout << "\033[1;32m" << str << "\033[0m";
	return;
}

//================================================

void color_sym_output(char sym)
{
    cout << "\033[1;31m" << sym << "\033[0m";
	return;
}

//================================================

void output(int flag, int ord)
{
	char l_max;
	int n;
	if(flag == 1)
	{
		n = romnum.find("C");
		if(n > 0)
			l_max = romnum[n-1];

		if(n == 0)
		{
			color_sym_output(romnum[0]);
			cout << romnum.substr(1) << " >> ";
			return;
		}

		if(n == 1)
		{
			color_sym_output(l_max);
			cout << romnum.substr(1) << " >> ";
			return;
		}

		if (n > 1)
		{
			cout << romnum.substr(0, n - 1);
			color_sym_output(l_max);
    		cout << romnum.substr(n) << " >> ";
    		return;
		}
    }
    
    if(flag == 2)
    {
        color_str_output(romnum.substr(0,ord-1));
		cout << romnum.substr(ord - 1) << " >> ";
		return;
    }
    
	cout << romnum << " >> ";
	return;
}

//================================================

int find_repeat(int cn)
{
	int i = 0;
	if(cn == 1)
		return 0;
	while(i < cn-1 && romnum.compare(rep[i]))
	{
		++i;
	}
	return i == cn - 1 ? 0 : 1;
}

//================================================

int main()
{
	int amount = romnum.size();
	int order = 2;
	int circle_num = 0;
	int res = 1;
	int flag = 1;
	rep.push_back(romnum);

	while(order > 1)
	{
	    circle_num++;
		order = amount;
		if(circle_num < 10)
		    cout << " (" << circle_num << "):  ";
		else
		    cout << "(" << circle_num << "):  ";

		// печать amount уникальных перестановок

		for(int i = 0; i < amount; ++i)
		{
			output(flag, order);
			sdvig(order);
		}
		cout << "| ";

		//дальше идет обработка повторов
        
        flag = 2;
		while(res == 1 && order > 1)
		{
			output(flag, order);
			--order;
			if(order > 1)
				sdvig(order);
			res = find_repeat(circle_num);
			if(!res)
			{
				rep.push_back(romnum);
				cout << "..."<< endl;
			}
		}

		res = 1;
		flag = 1;
	}
}
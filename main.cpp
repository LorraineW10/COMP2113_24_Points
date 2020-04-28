#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
void welcome(string &name, bool &keeprecord)
{
	cout<<"Welcome to 24 points!"<<endl;
	cout<<"Player's name: "<<endl;
	cin>>name;
	cout<<"Hello "<<name<<"!"<<endl;
	cout<<"Do you want to keep the score of this trial, "<<name
	<<"? "<<"[yes/no]"<<endl;
	string ans;
	cin>>ans;
	if(ans=="yes")
	{
		keeprecord=true;
		cout<<"We will count your score and store it in Player record"<<endl;
	}
	else
	{
		keeprecord=false;
		cout<<"only your name will be recorded while your score hidden"<<endl;
	}
	cout<<name<<", now please enjoy the game!"<<endl;
}

void generatenumber(int &n1,int &n2,int &n3,int &n4)
{
	srand(time(NULL));
	n1=rand()%9+1;
	n2=rand()%9+1;
	n3=rand()%9+1;
	n4=rand()%9+1;
	cout<<"The first number is "<<n1<<endl;
	cout<<"The second number is "<<n2<<endl;
	cout<<"The third number is "<<n3<<endl;
	cout<<"The fourth number is "<<n4<<endl;
}

double factorial(double n)
{
	double product=1;
	for(int i=2;i<=n;++i)
	{
		product*=i;
	}
	return product;
}

double permutation(double n, double r)
{
	if(n<r)
	{
		cout<<"This cannot be done!"
		<<" You may consider to switch their position."<<endl;
		return 0;
	}
	else
	{
		return factorial(n)/factorial(n-r);
	}
}

double combination(double n, double r)
{
	if(n<r)
	{
		cout<<"This cannot be done!"
		<<" You may consider to switch their position."<<endl;
		return 0;
	}
	else
	{
		return factorial(n)/factorial(r)/factorial(n-r);
	}
}

int rounding(double n)
{
	return round(n);
}

void playgame(int &n1, int &n2, int &n3, int &n4)
{
	bool changepos=false;
	cout<<"Do you want to switch their positions?"
	<<" [yes/no]"<<endl;
	string ans;
	cin>>ans;
	if(ans=="yes")
	{
		cout<<"Please input the two positions that"
		<<" you want to change" << endl;
		int c1,c2;
		cin>>c1>>c2;
		if(c1==c2)
		{
			cout<<"Invaild. Please input again." <<endl;
			cin>>c1>>c2;
		}
		else if(c1==1&&c2==2)
		{
			int temp=n1;
			n1=n2;
			n2=temp;
		}
		else if(c1==1&&c2==3)
		{
			int temp=n1;
			n1=n3;
			n3=temp;
		}
		else if(c1==1&&c2==4)
		{
			int temp=n1;
			n1=n4;
			n4=temp;
		}
		else if(c1==2&&c2==1)
		{
			int temp=n2;
			n2=n1;
			n1=temp;
		}
		else if(c1==2&&c2==3)
		{
			int temp=n2;
			n2=n3;
			n3=temp;
		}
		else if(c1==2&&c2==4)
		{
			int temp=n2;
			n2=n4;
			n4=temp;
		}
		else if(c1==3&&c2==1)
		{
			int temp=n1;
			n1=n3;
			n3=temp;
		}
		else if(c1==3&&c2==2)
		{
			int temp=n3;
			n3=n2;
			n2=temp;
		}
		else if(c1==3&&c2==4)
		{
			int temp=n3;
			n3=n4;
			n4=temp;
		}
		else if(c1==4&&c2==1)
		{
			int temp=n4;
			n4=n1;
			n1=temp;
		}
		else if(c1==4&&c2==2)
		{
			int temp=n4;
			n4=n2;
			n2=temp;
		}
		else if(c1==4&&c2==3)
		{
			int temp=n4;
			n4=n3;
			n3=temp;
		}
	}
}

int main()
{
	string playername;
	bool keeprecord;
	int n1,n2,n3,n4;
	welcome(playername, keeprecord);
	generatenumber(n1,n2,n3,n4);
	return 0;
} 

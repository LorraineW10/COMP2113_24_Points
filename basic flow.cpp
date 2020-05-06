#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// for recording player's scores
struct Record{
	string name;
	int info;
	Record * next;
};

// (这部分还需要吗……？
Record * find_prev( Record * head, int num )
void head_insert(Record * & head, string name, int num)
void insert( Record * after, string name, int num )
int factorial(int n);
int permutation(int n, int r);
int combination(int n, int r);
int subtract(int a, int b);
int bigger(int a, int b);
int smaller(int a, int b);


// find the last one in the list that is smaller than num
Record * find_prev( Record * head, int num )
{
	if (head == NULL || head->info >= num )
		return NULL;

	// at least one node in the list now
	Record * current = head;

	while (current->next != NULL) {
		if (current->next->info >= num)
			return current;
		else
			current = current->next;
	}

	return current;
}

// insert the record when it is the highest so far
void head_insert(Record * & head, string name, int num)
{
	Record * p = new Record;
	p->name = name;
	p->info = num;
	p->next = head;
	head = p;
}

// insert the record in other circumstances
void insert( Record * after, string name, int num )
{
	Record * p = new Record;
	p->name = name;
	p->info = num;
	p->next= after->next;
	after->next = p;
}

// other functions for calculation
int factorial(int n)
{
	int product=1;
	for(int i=2;i<=n;++i)
	{
		product*=i;
	}
	return product;
}

int permutation(int n, int r)
{
	return factorial(n)/factorial(n-r);
}

int combination(int n, int r)
{
	return factorial(n)/factorial(r)/factorial(n-r);
}

int subtract(int a, int b)
{
	if(a==b)
	{
		return 0;
	}
	else
	{
		if(a>b)
		{
			return (a-b);
		}
		else
		{
			return (b-a);
		}
	}
}

int bigger(int a, int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int smaller(int a, int b)
{
	if(a<=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	// GREETINGS
	cout<<"Welcome to 24 points!"<<endl;
	// For the linked list of score record
	Record * head = NULL, * tail = NULL;
	
	// Start the competition
	while (true){
		
		// To record a player's name
		cout<<"Player's name: "<<endl;
		string Player_name;
		cin>>Player_name;
		cout<<"Hello "<<Player_name<<"!"<<endl;

		// Whether to keep the record
		cout<<"Do you want to keep the score of this trial, "<<Player_name
		<<"? "<<"[yes/no]"<<endl;
		string keep_trial_ans;
		cin>>keep_trial_ans;
		bool keeprecord;

		if(keep_trial_ans=="yes")
		{
			keeprecord=true;
			cout<<"We will count your score and store it in Player record"<<endl;
		}
		else
		{
			keeprecord=false;
			cout<<"Only your name will be recorded while your score hidden"<<endl;
		}
		cout<<Player_name<<", now please enjoy the game!"<<endl;

		// Generate for random numbers
		int n1,n2,n3,n4;
		srand(time(NULL));
		n1=rand()%9+1;
		n2=rand()%9+1;
		n3=rand()%9+1;
		n4=rand()%9+1;
		cout<<"The first number is "<<n1<<endl;
		cout<<"The second number is "<<n2<<endl;
		cout<<"The third number is "<<n3<<endl;
		cout<<"The fourth number is "<<n4<<endl;

		// START THE GAME
		int Player_score=0;
		cout<<Player_name<<", please choose which operation you want to do:"<<endl;
		cout<<"[1] On "<<n1<<endl;
		cout<<"[2] Between "<<n1<<" and "<<n2<<endl;
		int Player_1_oper_choice;
		cin>>Player_1_oper_choice;
		if(Player_1_oper_choice==1)
		{
			cout<<Player_name<<", please choose which operation you want to do on "<< n1<<endl;
			cout<<"[1] square root"<<endl;
			cout<<"[2] factorial"<<endl;
			int Player_2_oper_choice;
			cin>>Player_2_oper_choice;
			if(Player_2_oper_choice==1)
			{
				n1=round(sqrt(n1));
				cout<<"Now the first number is "<<n1<<endl;
				Player_score+=3;
			}
			else if(Player_2_oper_choice==2)
			{
				n1=factorial(n1);
				cout<<"Now the first number is "<<n1<<endl;
				Player_score+=3;
			}
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n1<<" and "<<n2<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_3_oper_choice;
			cin>>Player_3_oper_choice;
			if(Player_3_oper_choice==1)
			{
				n2=n1+n2;
				Player_score+=1;
			}
			else if(Player_3_oper_choice==2)
			{
				n2=subtract(n1,n2);
				Player_score+=1;
			}
			else if(Player_3_oper_choice==3)
			{
				n2=n1*n2;
				Player_score+=1;
			}
			else if(Player_3_oper_choice==4)
			{
				n2=round(n1/n2);
				Player_score+=1;
			}
			else if(Player_3_oper_choice==5)
			{
				n2=permutation(bigger(n1,n2),smaller(n1,n2));
				Player_score+=3;
			}
			else if(Player_3_oper_choice==6)
			{
				n2=combination(bigger(n1,n2),smaller(n1,n2));
				Player_score+=3;
			}
			n1=0;
		}
		else if(Player_1_oper_choice==2)
		{
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n1<<" and "<<n2<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_4_oper_choice;
			cin>>Player_4_oper_choice;
			if(Player_4_oper_choice==1)
			{
				n2=n1+n2;
				Player_score+=1;
			}
			else if(Player_4_oper_choice==2)
			{
				n2=subtract(n1,n2);
				Player_score+=1;
			}
			else if(Player_4_oper_choice==3)
			{
				n2=n1*n2;
				Player_score+=1;
			}
			else if(Player_4_oper_choice==4)
			{
				n2=round(n1/n2);
				Player_score+=1;
			}
			else if(Player_4_oper_choice==5)
			{
				n2=permutation(bigger(n1,n2),smaller(n1,n2));
				Player_score+=3;
			}
			else if(Player_4_oper_choice==6)
			{
				n2=combination(bigger(n1,n2),smaller(n1,n2));
				Player_score+=3;
			}
			n1=0;
		}


		cout<<"Now we have three numbers remaining."<<endl;
		cout<<"The second number is "<<n2<<endl;
		cout<<"The third number is "<<n3<<endl;
		cout<<"The fourth number is "<<n4<<endl;
		cout<<Player_name<<", please choose which operation you want to do next:"<<endl;
		cout<<"[1] On "<<n2<<endl;
		cout<<"[2] Between "<<n2<<" and "<<n3<<endl;
		int Player_5_oper_choice;
		cin>>Player_5_oper_choice;
		if(Player_5_oper_choice==1)
		{
			cout<<Player_name<<", please choose which operation you want to do on "<<n2<<endl;
			cout<<"[1] square root"<<endl;
			cout<<"[2] factorial"<<endl;
			int Player_6_oper_choice;
			cin>>Player_6_oper_choice;
			if(Player_6_oper_choice==1)
			{
				n2=round(sqrt(n2));
				cout<<"Now the second number is "<<n2<<endl;
				Player_score+=3;
			}
			else if(Player_6_oper_choice==2)
			{
				n2=factorial(n2);
				cout<<"Now the second number is "<<n2<<endl;
				Player_score+=3;
			}
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n2<<" and "<<n3<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_7_oper_choice;
			cin>>Player_7_oper_choice;
			if(Player_7_oper_choice==1)
			{
				n3=n2+n3;
				Player_score+=1;
			}
			else if(Player_7_oper_choice==2)
			{
				n3=subtract(n2,n3);
				Player_score+=1;
			}
			else if(Player_7_oper_choice==3)
			{
				n3=n2*n3;
				Player_score+=1;
			}
			else if(Player_7_oper_choice==4)
			{
				n3=round(n2/n3);
				Player_score+=1;
			}
			else if(Player_7_oper_choice==5)
			{
				n3=permutation(bigger(n2,n3),smaller(n2,n3));
				Player_score+=3;
			}
			else if(Player_7_oper_choice==6)
			{
				n3=combination(bigger(n2,n3),smaller(n2,n3));
				Player_score+=3;
			}
			n2=0;
		}
		else if(Player_5_oper_choice==2)
		{
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n2<<" and "<<n3<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_8_oper_choice;
			cin>>Player_8_oper_choice;
			if(Player_8_oper_choice==1)
			{
				n3=n2+n3;
				Player_score+=1;
			}
			else if(Player_8_oper_choice==2)
			{
				n3=subtract(n2,n3);
				Player_score+=1;
			}
			else if(Player_8_oper_choice==3)
			{
				n3=n2*n3;
				Player_score+=1;
			}
			else if(Player_8_oper_choice==4)
			{
				n3=round(n2/n3);
				Player_score+=1;
			}
			else if(Player_8_oper_choice==5)
			{
				n3=permutation(bigger(n2,n3),smaller(n2,n3));
				Player_score+=3;
			}
			else if(Player_8_oper_choice==6)
			{
				n3=combination(bigger(n2,n3),smaller(n2,n3));
				Player_score+=3;
			}
			n2=0;
		}


		cout<<"Now we have two numbers remaining."<<endl;
		cout<<"The third number is "<<n3<<endl;
		cout<<"The fourth number is "<<n4<<endl;
		cout<<Player_name<<", please choose which operation you want to do next:"<<endl;
		cout<<"[1] On "<<n3<<endl;
		cout<<"[2] Between "<<n3<<" and "<<n4<<endl;
		int Player_9_oper_choice;
		cin>>Player_9_oper_choice;
		if(Player_9_oper_choice==1)
		{
			cout<<Player_name<<", please choose which operation you want to do on "<<n3<<endl;
			cout<<"[1] square root"<<endl;
			cout<<"[2] factorial"<<endl;
			int Player_10_oper_choice;
			cin>>Player_10_oper_choice;
			if(Player_10_oper_choice==1)
			{
				n3=round(sqrt(n3));
				cout<<"Now the third number is "<<n3<<endl;
				Player_score+=3;
			}
			else if(Player_10_oper_choice==2)
			{
				n3=factorial(n3);
				cout<<"Now the third number is "<<n3<<endl;
				Player_score+=3;
			}
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n3<<" and "<<n4<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_11_oper_choice;
			cin>>Player_11_oper_choice;
			if(Player_11_oper_choice==1)
			{
				n4=n3+n4;
				Player_score+=1;
			}
			else if(Player_11_oper_choice==2)
			{
				n4=subtract(n3,n4);
				Player_score+=1;
			}
			else if(Player_11_oper_choice==3)
			{
				n4=n3*n4;
				Player_score+=1;
			}
			else if(Player_11_oper_choice==4)
			{
				n4=round(n3/n4);
				Player_score+=1;
			}
			else if(Player_11_oper_choice==5)
			{
				n4=permutation(bigger(n3,n4),smaller(n3,n4));
				Player_score+=3;
			}
			else if(Player_11_oper_choice==6)
			{
				n4=combination(bigger(n3,n4),smaller(n3,n4));
				Player_score+=3;
			}
			n3=0;
		}
		else if(Player_9_oper_choice==2)
		{
			cout<<Player_name<<", please choose which operation you want to do on "
			<<n3<<" and "<<n4<<endl;
			cout<<"[1] add"<<endl;
			cout<<"[2] subtract"<<endl;
			cout<<"[3] multiple"<<endl;
			cout<<"[4] divide"<<endl;
			cout<<"[5] permutation"<<endl;
			cout<<"[6] combination"<<endl;
			int Player_12_oper_choice;
			cin>>Player_12_oper_choice;
			if(Player_12_oper_choice==1)
			{
				n4=n3+n4;
				Player_score+=1;
			}
			else if(Player_12_oper_choice==2)
			{
				n4=subtract(n3,n4);
				Player_score+=1;
			}
			else if(Player_12_oper_choice==3)
			{
				n4=n3*n4;
				Player_score+=1;
			}
			else if(Player_12_oper_choice==4)
			{
				n4=round(n3/n4);
				Player_score+=1;
			}
			else if(Player_12_oper_choice==5)
			{
				n4=permutation(bigger(n3,n4),smaller(n3,n4));
				Player_score+=3;
			}
			else if(Player_12_oper_choice==6)
			{
				n4=combination(bigger(n3,n4),smaller(n3,n4));
				Player_score+=3;
			}
			n3=0;
		}
		if(n4==24)
		{
			cout<<"YOU WIN, "<<Player_name<<"!"<<endl;
			Player_score+=10;
			cout << "Your score is " << Player_score << "." << endl;
		}
		else
		{
			cout<<"Sorry you lose this trial, "<<Player_name<<endl;
			Player_score-=5;
			cout << "Your score is " << Player_score << "." << endl;
		}

		// To build the linked list of the record
		if(keeprecord)
		{
			Record * after_this;
	    after_this = find_prev(head, Player_score);

			if (after_this == NULL)
				head_insert(head, Player_name, Player_score);
			else
				insert(after_this, Player_name, Player_score);

		}
		
		// Whether to end the loop and output the results
		cout << "Is there another player? (yes/no)" << endl;
		string continue_ans;
		cin >> continue_ans;
		if (continue_ans == "no"){
			cout << "OK, bye!" << endl;
			break;
		}
	}
	// To output the record into a file.
	ofstream fout;
	string filename="Players_record.txt";
	fout.open(filename.c_str());
	if(fout.fail())
	{
		cout<<"Error! Cannot check record."<<endl;
	}
	fout << "Player name Score\n";
	Record * current = head;
	while (current != NULL)
	{
		fout << current->name << " " << current->info << endl;
		current = current->next;
	}

}

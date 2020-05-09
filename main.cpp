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

// for recording players who chose to hide their scores
struct Hidden_Record{
	string name;
	Hidden_Record * next;
};

void hidden_record_tail_insert(Hidden_Record * & head, Hidden_Record * & tail, string name);
Record * find_prev( Record * head, int num );
void head_insert(Record * & head, string name, int num);
void insert( Record * after, string name, int num );
int factorial(int n);
int permutation(int n, int r);
int combination(int n, int r);
int subtract(int a, int b);
int bigger(int a, int b);
int smaller(int a, int b);

// for appending a new peson who hid their score
void hidden_record_tail_insert(Hidden_Record * & h_head, Hidden_Record * & h_tail, string name)
{
	Hidden_Record * p = new Hidden_Record;
	p->name = name;
	p->next = NULL;

	if (h_head == NULL) {
		h_head = p;
		h_tail = p;
	}
	else {
		h_tail->next = p;
		h_tail = p;
	}
}

// find the last one in the list that is smaller than num
Record * find_prev( Record * head, int num )
{
	if (head == NULL || head->info <= num )
		return NULL;

	// at least one node in the list now
	Record * current = head;

	while (current->next != NULL) {
		if (current->next->info <= num)
			return current;
		else
			current = current->next;
	}

	return current;
}

// insert the record when it is the lowest so far
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


int main()
{
	// GREETINGS
	cout<<"Welcome to 24 points!"<<endl;
	bool delta=1;
	// Building the list for recording players' scores
	Record * head = NULL, * tail = NULL;
	Hidden_Record * h_head = NULL, * h_tail = NULL;

	ofstream fout_record;
	fout_record.open("All_Possible_Results.txt");
	fout_record.close();

	// to record the four numbers;
	int num[4];

	while (true){
		cout<<"Player's name: "<<endl;
		string Player_name;
		cin>>Player_name;
		cout<<"Hello "<<Player_name<<"!"<<endl;

		// to choose whether to keep score
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

		// generate four random numbers
		int x,n1,n2,n3,n4;
		cout << "Please input a number" << endl;
		cin >> x;
	  srand(x);
		n1=rand()%9+1;
		n2=rand()%9+1;
		n3=rand()%9+1;
		n4=rand()%9+1;
		cout<<"The first number is "<<n1<<endl;
		cout<<"The second number is "<<n2<<endl;
		cout<<"The third number is "<<n3<<endl;
		cout<<"The fourth number is "<<n4<<endl;
		num[0]=n1;
		num[1]=n2;
		num[2]=n3;
		num[3]=n4;


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
			cout << "* We would not compute factorial of numbers larger than 9. It will return -999." << endl;
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
			cout << "* We would not compute factorial of numbers larger than 9. It will return -999." << endl;
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

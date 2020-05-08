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

// (这部分还需要吗……？
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

// other math functions needed
int factorial(int n)
{
	int product=1;
	if(n>9)
	{
		return -999;
	}
	for(int i=2;i<=n;++i)
	{
		product*=i;
	}
	return product;
}

int permutation(int n, int r)
{
	if((n-r>9)||(n-r==0))
	{
		return -999;
	}
	else
	{
		return factorial(n)/factorial(n-r);
	}
}

int combination(int n, int r)
{
	if((n-r>9)||(r>9)||(r==0)||(n-r==0))
	{
		return -999;
	}
	else
	{
		return factorial(n)/factorial(r)/factorial(n-r);
	}
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
			cout << "* We would not compute factorial of numbers larger than 9. It will return -999." << endl;
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

		// To build the linked lists of the record
		if(keeprecord)
		{
			Record * after_this;
	    after_this = find_prev(head, Player_score);

			if (after_this == NULL)
				head_insert(head, Player_name, Player_score);
			else
				insert(after_this, Player_name, Player_score);

		}
		else {
			hidden_record_tail_insert(h_head, h_tail, Player_name);
		}


		ofstream fout;
		string filename="All_Possible_Results.txt";
		fout.open(filename,ios::app);
		if(fout.fail())
		{
			cout<<"Error! Cannot output all possible results."<<endl;
		}

		bool result=false;
		int result1[2],result2[2],result3[2];
		fout << Player_name << "'s game have following possible results:" << endl;

		for (int i=0;i<3;i++){
			if (i==0) result1[0]=factorial(num[0]);
			else if (i==1) result1[0]=round(sqrt(num[0]));
			else if (i==2) result1[0]=num[0];

			for (int j=0;j<6;j++){
				result1[1]=result1[0];
				if (j==0) result1[1]+=num[1];
				else if (j==1) result1[1]=subtract(result1[1],num[1]);
				else if (j==2) result1[1]*=num[1];
				else if (j==3) result1[1]=round(result1[1]/num[1]);
				else if (j==4) result1[1]=permutation(bigger(num[1],result1[1]),smaller(num[1],result1[1]));
				else if (j==5) result1[1]=combination(bigger(num[1],result1[1]),smaller(num[1],result1[1]));

				if(result1[1]==-999) break;

				for ( int k=0;k<3;k++){
					if (k==0) result2[0]=factorial(result1[1]);
					else if (k==1) result2[0]=round(sqrt(result1[1]));
					else if (k==2) result2[0]=result1[1];

					for ( int l=0;l<6;l++){
						result2[1]=result2[0];
						if (l==0) result2[1]=num[2]+result2[1];
						else if (l==1) result2[1]=subtract(num[2],result2[1]);
						else if (l==2) result2[1]=num[2]*result2[1];
						else if (l==3) result2[1]=round(result2[1]/num[2]);
						else if (l==4) result2[1]=permutation(bigger(num[2],result2[1]),smaller(num[2],result2[1]));
						else if (l==5) result2[1]=combination(bigger(num[2],result2[1]),smaller(num[2],result2[1]));

						if(result2[1]==-999) break;

						for ( int x=0;x<3;x++){
							if (x==0) result3[0]=factorial(result2[1]);
							else if (x==1) result3[0]=round(sqrt(result2[1]));
							else if (x==2) result3[0]=result2[1];

							for ( int y=0;y<6;y++){
								result3[1]=result3[0];
								if (y==0) result3[1]=num[3]+result3[1];
								else if (y==1) result3[1]=subtract(result3[1],num[3]);
								else if (y==2) result3[1]=num[3]*result3[1];
								else if (y==3) result3[1]=round(result3[1]/num[3]);
								else if (y==4) result3[1]=permutation(bigger(num[3],result3[1]),smaller(num[3],result3[1]));
								else if (y==5) result3[1]=combination(bigger(num[3],result3[1]),smaller(num[3],result3[1]));

								if (result3[1]==24){
									result = true;
									fout << num[0] ;
									if (i==0) fout << " factorial,";
									if (i==1) fout << " squared,";

									if (j==0) fout << " plus " << num[1];
									if (j==1) fout << " subtract " << num[1] << "(absolute value)";
									if (j==2) fout << " multiple " << num[1];
									if (j==3) fout << " divided by " << num[1] << "(round)";
									if (j==4) fout << " permutation with " << num[1];
									if (j==5) fout << " combination with " << num[1];


									fout << " then";
									if (k==0) fout << " factorial,";
									if (k==1) fout << " squared,";

									if (l==0) fout << " plus " << num[2];
									if (l==1) fout << " subtract " << num[2] << "(absolute value)";
									if (l==2) fout << " multiply by " << num[2];
									if (l==3) fout << " divided by " << num[2] << "(round)";
									if (l==4) fout << " permutation with " << num[2];
									if (l==5) fout << " combination with " << num[2];

									fout << " then";
									if (x==0) fout << " factorial,";
									if (x==1) fout << " squared,";

									if (y==0) fout << " plus " << num[3];
									if (y==1) fout << " subtract " << num[3] << "(absolute value)";
									if (y==2) fout << " multiple " << num[3];
									if (y==3) fout << " divided by " << num[3] << "(round)";
									if (y==4) fout << " permutation with " << num[3];
									if (y==5) fout << " combination with " << num[3];


									fout << endl;
									
								}
							}
						}
					}
				}
			}
		}

		if (result==false){
			fout << "Sorry. No possible results." << endl;
		}

		fout << endl;
		fout.close();

    // Whether to end the loop and output the results
		cout << "Is there another player? (yes/no)" << endl;
		string continue_ans;
		cin >> continue_ans;
		if (continue_ans == "no"){
			cout << "OK, bye!" << endl;
			break;
		}

		// output all possible results;

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
	Hidden_Record * h_current = h_head;
	while (h_current != NULL)
	{
		fout << h_current ->name << " has hidden his/her score." << endl;
		h_current = h_current->next;
	}
	fout.close();





	return 0;
}

#include <iostream.h>
#include <string.h>
#include <process.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
struct taxi
{
	char place[50];
	float distance;
	void getdata()
	{
		cout<<"Enter place:";
		gets(place);
		cout<<"Enter distance from origin:";
		cin>>distance;
	}
	void putdata()
	{ 
		int len=strlen(place);
		cout<<"\n"; cout.write(place,len); cout<<"\t"; cout<<distance; cout<<"kms";
	}
}t1;
struct fares
{
	float dd1,dd2,dd3;
	void getata()
	{
		cout<<"Enter Minimum fare:";
		cin>>dd1;
		cout<<"Enter distance for which Minimum fare is applicable:";
		cin>>dd2;
		cout<<"Enter fare per km after minimum fare:";
		cin>>dd3;
	}
	void putata()
	{
		cout<<"\nMinimum fare of Rs."<<dd1<<" is applicable for a distance of "<<dd2<<"kms and thereafter there is a fixed charge of Rs."<<dd3<<" per km";
	}
}p1;
void func1()
{
	remove("Taxi.dat");
	ofstream fo("Taxi.dat",ios::out);
	char ans='y';
	while(ans=='y')
	{
		t1.getdata();
		fo.write((char*)&t1,sizeof(t1));
		cout<<"\nRecord added to file";
		cout<<"\nWant to enter more records(y,n):";
		cin>>ans;
	}
	fo.close();
}
void func2()
{
	ifstream fi("Taxi.dat",ios::in);
	while(!fi.eof())
	{
		fi.read((char*)&t1,sizeof(t1));
		t1.putdata();
	}
	fi.close();
}
void func3()
{
	ofstream fo;
	fo.open("Taxi.dat",ios::app);
	char ans='y';
	while(ans=='y')
	{
		t1.getdata();
		fo.write((char*)&t1,sizeof(t1));
		cout<<"\nRecord added to file";
		cout<<"\nWant to enter more records(y,n):";
		cin>>ans;
	}
	fo.close();
}
void func4()
{
	remove("fare.dat");
	ofstream fof("fare.dat",ios::out);
	p1.getata();
	fof.write((char*)&p1,sizeof(p1));
	cout<<"\nRecord added to file";
	fof.close();
}
void func5()
{
	ifstream fif("fare.dat",ios::in);
	while(!fif.eof())
	{
		fif.read((char*)&p1,sizeof(p1));
		p1.putata();
	}
	fif.close();
}
void func6()
{
	char pi[30];
	cout<<"\nEnter your name:";
	gets(pi);
	for(int i=0;pi[i]!='\0';i++)
		pi[i]=toupper(pi[i]);
	strcat(pi,".txt");
	ofstream fo(pi,ios::nocreate|ios::out|ios::trunc);
	cout<<"\nYour ticket is successfully cancelled!!";
	fo<<"                    $$ Welcome to Taxi Management  System $$                   "<<endl;
	fo<<"              $$______By-Ankit Prasad & Sumit Mukherjee_______$$                   "<<endl;
	fo<<"                $$______www.computersciencearticle.in_______$$                   "<<endl;
	fo<<"\nYour ticket is successfully cancelled!!";
	fo<<"\nThanks for choosing us";
	fo.close();
}
float distance(char place1[50],char place2[50])
{
	float Distance1=100,Distance2=100,Distance;
	ifstream fi("Taxi.dat",ios::in);
	while(!fi.eof())
	{
		fi.read((char*)&t1,sizeof(t1));
		if((strcmp(t1.place,place1))==0)
			Distance1=t1.distance;
		if((strcmp(t1.place,place2))==0)
			Distance2=t1.distance;
	}
	fi.close();
	if(Distance1==100||Distance2==100)
	{
		cout<<"\nNo such place exists in the list";
		exit(0);
	}
	Distance=Distance2-Distance1;
	if(Distance<0)
		Distance=-1*Distance;
	return Distance;
}
float taxifare(float dist)
{
	float R;
	ifstream fif("fare.dat",ios::in);
	while(!fif.eof())
	{
		fif.read((char*)&p1,sizeof(p1));
		if(dist<=p1.dd2)
			R=p1.dd1;
		else
			R=p1.dd1+(dist-p1.dd2)*p1.dd3;
	}
	fif.close();
	return R;
}
void book(float distan,float fared,char place0[],char place00[])
{
	char h[5],f[30],p[30],u[5],yo[14],m[50];
	int no,mo;
	float amount;
	double b;
	cout<<"                    $$ Welcome to Taxi Management  System $$                   "<<endl;
	cout<<"              $$______By-Ankit Prasad & Sumit Mukherjee_______$$                   "<<endl;
	cout<<"                $$______www.computersciencearticle.in_______$$                   "<<endl;
	cout<<"\nEnter your email address:";
	cin>>m;
	cout<<"\nEnter Date for the tour(d-m-y):";
	cin>>yo;
	cout<<"\nEnter Time for the tour(h:m):";
	cin>>h;
	cout<<"\nEnter am/pm:";
	cin>>u;
	cout<<"\nEnter Your name:";
	gets(f);
	strcpy(p,f);
	for(int i=0;p[i]!='\0';i++)
		p[i]=toupper(p[i]);
	strcat(p,".txt");
	cout<<"\nNOTE:Maximum 5 person per taxi,although multiple taxis can be booked!!";
	cout<<"\nEnter total no. of passengers:";
	cin>>no;
	cout<<"\nThankyou..";
	cout<<"\nYour ticket is confirmed and the detail is sent to you along with the confirmation code which you will be asked to show at the ticket counter";
	srand ( time(NULL) );
	b=100000 + (rand() % 999999);
	mo=no/5;
	if(no%5>0)
		++mo;
	if(mo>3)
		amount=0.75*mo*fared;
	else
		amount=mo*fared;
	ofstream fo(p,ios::noreplace|ios::out);
	fo<<"                    $$ Welcome to Taxi Management  System $$                   "<<endl;
	fo<<"              $$______By-Ankit Prasad & Sumit Mukherjee_______$$                   "<<endl;
	fo<<"                $$______www.computersciencearticle.in_______$$                   "<<endl;
	fo<<m<<"\n";
	fo<<f<<"\n";
	fo<<"Your confirmation code:"<<b;
	fo<<"\nArriving Date:"<<yo<<"\n";
	fo<<"Arriving Time:"<<h<<u<<"\n";
	fo<<"No.of passengers:"<<no;
	fo<<"\nNo. of taxis booked:"<<mo;
	fo<<"\nArrival point:"<<place0<<"\nDestination point:"<<place00<<"\nDistance:"<<distan<<"kms"<<"\nfare:RS."<<amount;
	fo<<"\n25% discount on fares,after 15 passengers";
	fo<<"\nYou can get your ticket from the nearest taxi-stand ticket counter and pay your amount there";
	fo<<"\nfor ticket cancellation or any other enquiry please call 63636363";
	fo.close();
}
void user()
{
	char place11[50],place22[50],ch;
	float d,fare;
	cout<<"\nEnter the originating place:\n";
	gets(place11);
	cout<<"\nEnter the destination place:\n";
	gets(place22);
	for(int i=0;place11[i]!='\0';i++)
		place11[i]=tolower(place11[i]);
	for(int j=0;place22[j]!='\0';j++)
		place22[j]=tolower(place22[j]);
	d=distance(place11,place22);
	fare=taxifare(d);
	cout<<"\nDISTANCE="<<d;
	cout<<"\nFARE="<<fare;
	cout<<"\nWant to book taxi with this detail:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		book(d,fare,place11,place22);
}
int main()
{
	clrscr();
	char ch,opt;
	do
	{
		cout<<"\nMENU:";
		cout<<"\na.USER MENU:";
		cout<<"\nb.PROGRAMMER MENU";
		cout<<"\nc.EXIT FROM MENU:";
		cout<<"\nEnter your choice:";
		cin>>opt;
		opt=tolower(opt);
		switch (opt)
		{
			case 'a':
				cout<<"\n1.VIEW DATA";
				cout<<"\n2.TAXI FAROMETER/BOOKING";
				cout<<"\n3.TICKET CANCELLATION";
				cout<<"\nEnter your choice:";
				cin>>ch;
				if(ch=='1') 
				{
					cout<<"\n1.VIEW DISTANCE CHART";
					cout<<"\n2.VIEW FARE CHART";
					cout<<"\nEnter your choice:";
					cin>>ch;
					if(ch=='1')
						func2();
					else if(ch=='2') 
						func5();
					else 
						cout<<"\nWrong choice";
				}
				else if(ch=='2') 
					user();
				else if(ch=='3') 
					func6();
				else 
					cout<<"\nWrong choice";
			break;
			case 'b':
				cout<<"\n1.DISTANCE CHART";
				cout<<"\n2.FARE CHART";
				cout<<"\nEnter your choice:";
				cin>>ch;
				if(ch=='1')
				{
					cout<<"\n1.VIEW DATA";
					cout<<"\n2.ADD DATA";
					cout<<"\n3.RESET DATA";
					cout<<"\nEnter your choice:";
					cin>>ch;
					if(ch=='1') 
						func2();
					else if(ch=='2') 
						func3();
					else if(ch=='3') 
						func1();
					else 
						cout<<"\nWrong choice";
				}
				else if(ch=='2') 
				{
					cout<<"\n1.VIEW DATA";
					cout<<"\n2.RESET DATA";
					cout<<"\nEnter your choice:";
					cin>>ch;
					if(ch=='1') 
						func5();
					else if(ch=='2') 
						func4();
					else 
						cout<<"\nWrong choice";
				}
			break;
			case 'c':exit(0);
		}
	}while(opt!='c');
return 0;
}


#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
class data
{
	int roll;
	char name[20];
	int m1 , m2 , m3 , m4 , m5;
	char grade[3];
	int tot;
	int perc;
	public:
	void getdata()
	{
		cout<<"\n Enter Roll No. of the student: ";
		cin>>roll;
		cout<<"\n Enter name of the student: ";
		gets(name);
		cout<<"\n\n Enter marks of the 5 subjects out of 100 ";
		cout<<"\n Enter marks in English: ";
		cin>>m1;
		cout<<"\n Enter marks in Maths: ";
		cin>>m2;
		cout<<"\n Enter marks in Physics: ";
		cin>>m3;
		cout<<"\n Enter marks in Chemistry: ";
		cin>>m4;
		cout<<"\n Enter marks in Computer: ";
		cin>>m5;
		tot=m1+m2+m3+m4+m5;
		perc=float(tot)/5;
		calc_grade();
	}
	void showdata()
	{
		cout<<"\n\n Roll No. - "<<roll;
		cout<<"\n Name - "<<name;
		cout<<"\n Marks in -";
		cout<<"\n 1. English "<<m1;
		cout<<"\n 2. Maths "<<m2;
		cout<<"\n 3. Physics "<<m3;
		cout<<"\n 4. Chemistry "<<m4;
		cout<<"\n 5. Computer "<<m5;
		cout<<"\n Total - "<<tot;
		cout<<"\n Percentage - "<<perc;
		cout<<"\n Grade - "<<grade;
	}
	void showreport()
	{
		clrscr();
		gotoxy(25,4);
		cout<<"DELHI PUBLIC SCHOOL VASANT KUNJ";
		gotoxy(35,5);
		cout<<"Report Card";
		cout<<"\n\n\n\t\tRoll Number: "<<roll;
		cout<<"\n\t\tName: "; puts(name);
		cout<<"\n\t\tSubject\t\tMarks";
		cout<<"\n\t\tEnglish\t\t\b "<<m1;
		cout<<"\n\t\tMathematics\t"<<m2;
		cout<<"\n\t\tPhysics\t\t"<<m3;
		cout<<"\n\t\tChemistry\t\b "<<m4;
		cout<<"\n\t\tComputer\t\b "<<m5;
		cout<<"\n\t\t\t\t----";
		cout<<"\n\t\tTotal\t\t"<<tot;
		cout<<"\n\n\t\tPercentege: "<<perc;
		cout<<"\n\t\tGrade: ";puts(grade);
	}
	void calc_grade()
	{
	  if(perc>=91)
		strcpy(grade,"A1");
	  if(perc>=81 && perc<91)
		strcpy(grade,"A2");
	  if(perc>=71 && perc<81)
		strcpy(grade,"B1");
	  if(perc>=61 && perc<71)
		strcpy(grade,"B2");
	  if(perc>=51 && perc<61)
		strcpy(grade,"C");
	  if(perc>=41 && perc<51)
		strcpy(grade,"D");
	  else if(perc<41)
		strcpy(grade,"E");
	}
	char* retname()
	{ return name;
	}
	int retroll()
	{ return roll;
	}
	int retperc()
	{ return perc;
	}
}d,temp;

fstream g,f;
int i,n;
void write()
{
	char ans;
	g.open("new.dat",ios::binary|ios::out);
	do
	{ d.getdata();
	  g.write((char*)& d, sizeof(d));
	  cout<<"Do you want to add another record? (Y/N)";
	  ans=getche();
	} while(ans=='y' || ans=='Y');
	g.close();
	}
	void add()
	{
	g.open("new.dat",ios::binary|ios::app);
	cout<<"\nEnter details of new record: ";
	d.getdata();
	g.write((char *)& d, sizeof(d));
	g.close();
}
void deletroll()
{
	int num,r=0;
	cout<<"Enter student roll no to be deleted: ";
	cin>>num;
	g.open("new.dat",ios::binary|ios::in);
	f.open("temp.dat",ios::binary|ios::out);
	g.seekg(0);
	while(g.read((char*)&d,sizeof(d)))
	{
	if(d.retroll()==num)
	{
	 r=1;
	 cout<<"\n Record deleted";
	}
	else
	{
	 f.write((char*)&d,sizeof(d));
	}
	}
	g.close();
	f.close();
	remove("new.dat");
	rename("temp.dat","new.dat");
	if(r==0)
	{
	cout<<"\n\n Sorry record not found ";
	}
}
void deletname()
{
	char chdelete[20];
	int r=0;
	cout<<"Enter student name to be deleted: ";
	gets(chdelete);
	g.open("new.dat",ios::binary|ios::in);
	f.open("temp.dat",ios::binary|ios::out);
	g.seekg(0);
	while(g.read((char*)&d,sizeof(d)))
	{
	if(strcmpi(d.retname(),chdelete)==0)
	{ r=1;
	  cout<<"\n Record deleted";
	}
	else
	 f.write((char*)&d,sizeof(d));
	}
	f.close();
	g.close();
	remove("new.dat");
	rename("temp.dat","new.dat");
	if(r==0)
	{
	cout<<"\n\n Sorry record not found ";
	}
}
void searchname()
{
	char ch[20];
	int f=0;
	cout<<"\n Enter the name to be searched :";
	gets(ch);
	g.open("new.dat",ios::binary|ios::in);
	while(g.read((char*)&d,sizeof(d)))
	{if(strcmpi(ch,d.retname())==0)
	 {
	  f=1;
	  d.showreport();
	 }

	}
	if (f==0)
	{
	cout<<"\n Sorry, the name does not exist";
	}
	g.close();
}
void searchroll()
{
	int f=0 , chroll;
	cout<<"\n Enter the roll no. to be searched :";
	cin>>chroll;
	g.open("new.dat",ios::binary|ios::in);
	while(g.read((char*)&d,sizeof(d)))
	{if(d.retroll()==chroll)
	 {
	  f=1;
	  d.showreport();
	 }
	}
	if (f==0)
	{
	cout<<"\n Sorry, the Roll Number does not exist";
	}
	g.close();
}
int scholar()
{
	int cnt=0;
	g.open("new.dat",ios::binary|ios::in);
	while(g.read((char*)&d,sizeof(d)))
	{ if(d.retperc()>=80)
	    cnt++;
	}
	g.close();
	return cnt;
}
int failure()
{
	int cntt=0;
	g.open("new.dat",ios::binary|ios::in);
	while(g.read((char*)&d,sizeof(d)))
	{ if(d.retperc()<40)
	    cntt++;
	}
	g.close();
	return cntt;
}
void editroll()
{
	int r,t=0;
	g.open("new.dat",ios::binary|ios::in);
	f.open("temp.dat",ios::binary|ios::out);
	cout<<"\nEnter roll no to be edited: ";
	cin>>r;
	while(g.read((char*)&d,sizeof(d)))
	{ if(d.retroll()==r)
	  { cout<<"\nEnter new details: ";
	    temp.getdata();
	    f.write((char*)&temp,sizeof(temp));
	    t=1;
	  }
	  else
	   f.write((char*)&d,sizeof(d));
}
f.close();
g.close();
remove("new.dat");
rename("temp.dat","new.dat");
if(t==0)
 cout<<"\nSoory, the Roll Number does not exist";
}
void editname()
{
	char chname[20];
	int t=0;
	g.open("new.dat",ios::binary|ios::in);
	f.open("temp.dat",ios::binary|ios::out);
	cout<<"\nEnter name to be edited: ";
	gets(chname);
	while(g.read((char*)&d,sizeof(d)))
	{ if(strcmpi(d.retname(),chname)==0)
	  { cout<<"\nEnter new details: ";
	    temp.getdata();
	    f.write((char*)&temp,sizeof(temp));
	    t=1;
	  }
	  else
	   f.write((char*)&d,sizeof(d));
	}
	f.close();
	g.close();
	remove("new.dat");
	rename("temp.dat","new.dat");
	if(t==0)
	 cout<<"\nSorry, the name does not exist";
}
void show()
{
g.open("new.dat",ios::binary|ios::in);
while(g.read((char*)&d,sizeof(d)))
{ d.showdata();
}
g.close();
}
void main()
{
	clrscr();
	char temp;
	gotoxy(27,3);
	cout<<" Computer Science Project";
	gotoxy(29,5);
	cout<<"  Report Card Making";
	gotoxy(6,13);
	cout<<"Made by:- Mayan Agarwal         AND          Abhinav Kaushal Keshari";
	gotoxy(6,15);
	cout<<"School :- Delhi Public School Vasant Kunj ";
	gotoxy(50,24);
	cout<<"Press any button to continue ";
	temp=getch();
	int ch;
	char choice;
	do
	{
		clrscr();
		cout<<"\n Menu: ";
		cout<<"\n 1.Make Report Card";
		cout<<"\n 2.Add Names";
		cout<<"\n 3.Delete a record";
		cout<<"\n 4.Search and display his/her report card";
		cout<<"\n 5.Edit a record ";
		cout<<"\n 6.Count number of scholar students (Percentage>=80)";
		cout<<"\n 7.Count number of students failing (Percentage<40)";
		cout<<"\n 8.Show all records";
		cout<<"\n 10.Exit";
		cout<<"\n\n Enter your choice ";
		cin>>ch;
		switch(ch)
		{
		case 1:  write();
			  break;
		case 2:  add();
			  break;
		case 3:  clrscr();
			  int c3;
			  cout<<"\n\n 1.Delete a record by Roll no. ";
			  cout<<"\n 2.Delete a record by Name ";
			  cin>>c3;
			  if(c3==1)
			   deletroll();
			  else if (c3==2)
			   deletname();
			  break;
		case 4:  clrscr();
			  int c4 ;
			  cout<<"\n\n 1.Search a record by Roll no. ";
			  cout<<"\n 2.Search a record by Name ";
			  cin>>c4;
			  if(c4==1)
			   searchroll();
			  else if (c4==2)
			   searchname();
			  break;
		case 5:  clrscr();
			  int c5 ;
			  cout<<"\n\n 1.Edit a record by Roll no. ";
			  cout<<"\n 2.Edit a record by Name ";
			  cin>>c5;
			  if(c5==1)
			  editroll();
			  else if (c5==2)
			  editname();
			  break;
		case 6:  cout<<"\nTotal number of scholar students: "<<scholar();
			  break;
		case 7:  cout<<"\nNumber of students failing: "<<failure();
			  break;
		case 8:  show();
			  break;
		case 10: exit(0);
		default:
			clrscr();
			cout<<"\n Wrong choice ";
		}
		cout<<"\n\n Do you want to continue (Y/N) ";
		choice=getche();
	}while(choice=='y' || choice=='Y');
	getch();
}









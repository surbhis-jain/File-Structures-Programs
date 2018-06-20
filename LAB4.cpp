#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#define LEN 45

using namespace std;

class student
{
	char usn[11], name[15], dept[15], sem[4], buffer[45];
	public:
			void read();
			void pack();
			void write();
			void search();
};

void student::read()
{	
	cout<<"Enter the usn :"<<endl;
	cin>>usn;
	cout<<"Enter the name :"<<endl;
	cin>>name;
	cout<<"Enter the department :"<<endl;
	cin>>dept;
	cout<<"Enter the semester :"<<endl;
	cin>>sem;
}
void student:: pack()
{
	strcpy(buffer,usn);
	strcat(buffer,"|");
	strcat(buffer,name);
    strcat(buffer,"|");
    strcat(buffer,dept);
    strcat(buffer,"|");
    strcat(buffer,sem);
	for(int i=strlen(buffer);i<LEN;i++)
	{
        strcat(buffer,"#");
	}
}

void student :: write()
{
    ofstream fout;
	fout.open("student.txt",ios::app);
	fout<<buffer;
	fout.close();
    cout<<"\nStudent Record Added\n";
}

void student::search()
{
	int rrn;
	ifstream fin;
	fin.open("student.txt",ios::in);
	cout<<"Enter the rrn number of the record to be searched"<<endl;
	cin>>rrn;
	rrn=rrn-1;
	int num=rrn*45;
	fin.seekg(num,ios::beg);
	fin.getline(usn,11,'|');
	if(fin == NULL)
	{
		cout<<"Record not found with the rrn : "<<rrn+1<<endl;
		return;
	}
	fin.getline(name,15,'|');
	fin.getline(dept,15,'|');
	fin.getline(sem,4,'#');
	cout<<"\nRecord is found with RRN number : "<<rrn+1<<endl;
	cout<<"USN : "<<usn<<"\n"<<"NAME : "<<name<<"\n"<<"DEPT : "<<dept<<"\n"<<"SEM : "<<sem;
	fin.close();
}

int main()
{
	int ch;
	student s;
	while(1)
	{
		cout<<"\n\nEnter the choice "<<endl;
		cout<<"1.Insert Record\t 2.Search Record by rrn number\t 3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: s.read();
					s.pack();
					s.write();
					break;
			case 2: s.search();
					break;
			case 3: exit(0);
		}
	}
}
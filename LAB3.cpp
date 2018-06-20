/*3. Write a C++ program to read and write student objects with variable-length
records and the fields delimited by “|” and records delimited by “#”.
 Implement modify ( ), display () and search ( ) methods by performing pack and unpack operations. */
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;

class student
{
	char name[15],usn[11],sem[4],dept[10],buf[40];
	public:
	void display();
	void pack();
	void unpack();
	void search();
	void read();
	void modify();
	void write();
};

void student :: pack()
{
	strcpy(buf,usn);
	strcat(buf,"|");
	strcat(buf,name);
	strcat(buf,"|");
    strcat(buf,dept);
	strcat(buf,"|");
    strcat(buf,sem);
	strcat(buf,"#");
	strcat(buf,"\n");
}

void student :: unpack()
{
	strcpy(usn,strtok(buf,"|"));
	strcpy(name,strtok(NULL,"|"));
	strcpy(dept,strtok(NULL,"|"));
	strcpy(sem,strtok(NULL,"#"));
}

void student :: read()
{
	cout<<"Enter the USN: ";
	cin>>usn;
	cout<<"Enter the NAME : ";
	cin>>name;
	cout<<"Enter the DEPT : ";
	cin>>dept;
    cout<<"Enter the SEM: ";
	cin>>sem;
}

void student::write()
{
    ofstream fout;
	fout.open("Student.txt",ios::app);
	fout<<buf;
	fout.close();
	cout<<"Student Record Added\n ";
}

void student :: display()
{
	ifstream fin;
	fin.open("Student.txt");
	while(fin>>buf)
	{
		unpack();
        cout<<"\nStudent Found : "<<"\nUSN     : "<<usn<<"\nNAME    : "<<name<<"\nDEPT    : "<<dept<<"\nSEMESTER: "<<sem<<endl;
	}
	fin.close();
}

void student :: search()
{
	ifstream fin;
	fin.open("Student.txt");
	char key[11];
	cout<<"Enter the key : ";
	cin>>key;
	int found = 0;
	while(fin>>buf)
	{	
		unpack();
		if(!strcmp(usn,key)) // strcmp returns 0 if the strings are equal
		{
			cout<<"\nStudent Found : "<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nDEPT : "<<dept<<"\nSEMESTER: "<<sem<<endl;
			found = 1;
		}
	}
	if(found==0)
	cout<<"Student Not found!!\n";
	fin.close();
	return;
}
void student :: modify()
{
	fstream f;
	f.open("Student.txt",ios::in|ios::out);
	char key[11];
	cout<<"Enter the key : ";
	cin>>key;
	int size;
	while(f>>buf)
	{
		size = strlen(buf);
		unpack();
		if(!strcmp(usn,key))
		{
			cout<<"\nStudent Found \nEnter the Name";
			cin>>name;
			cout<<"Enter the new DEPT";
			cin>>dept;
			cout<<"Enter the new SEM";
			cin>>sem;
			pack();
			f.seekp((int)f.tellg()-size,ios::beg);
			f<<buf;
			f.close();
			return;
		}
    }
    cout<<"Student Not found \n";
    f.close();
	
}
int main()
{
	student s;
	int ch;
	while(1)
	{
        cout<<"Enter Your Choice for Variable Length Record\n";
        cout<<"1.Insert a record\n2.Search\n3.Modify\n4.Display\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:s.read();
                s.pack();
                s.write();
                break;
            case 2:s.search();
                break;
            case 3:s.modify();
                break;
            case 4: s.display();
                break;
            case 5: exit(0);
                break;
            default: cout<<"Invalid choice\n";
        }
	}
}

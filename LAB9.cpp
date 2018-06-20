/*Write a C++ program to implement secondary index on primary key for a file of Student objects.
Implement add(), search(), delete() using the index.*/
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
char space[20]="****";
using namespace std;
int n=0,index1=0;
class student
{
    public:
    char name[20],usn[20],branch[20];
    int sem;
    void insert(fstream &f1,fstream &f2)
    {
        char temp[50];
        char usn1[20];
        int flag;
        cout<<"\nEnter Name: ";
        cin>>name;
        cout<<"Enter USN: ";
        cin>>usn;
        cout<<"Enter Sem: ";
        cin>>sem;
        cout<<"Enter Branch: ";
        cin>>branch;
        while(!f2.eof())
        {
            f2.getline(temp,50,'\n');
            sscanf(temp,"%s ",usn1);
            if(strcmp(usn,usn1)==0)
            {
                flag=1;
                break;
            }
        }
        f2.close();
        if(flag==1)
            cout<<"\nPrimary key constraint violation,record not inserted";
        else
        {
            write(f1,f2);
        }
    }
    void insert1(fstream &f1,fstream &f2)
    {
        for(int i=0; i<20; i++)
        {
            name[i]=space[i];
            usn[i]=space[i];
            branch[i]=space[i];
        }
        sem=-1;
    }
    void write(fstream &f1,fstream &f2)
    {
        f1<<++index1<<"\t"<<name<<"\n";
        f2<<usn<<"\t"<<name<<"\t"<<sem<<"\t"<<branch<<"\n";
    }
    void display(fstream &f2)
    {
        f2>>name>>usn>>sem>>branch;
        if(strcmp(name,space)!=0)
            cout<<usn<<"\t"<<name<<"\t"<<sem<<"\t"<<branch<<"\n";
    }
    void search(fstream &f1,fstream &f2,char key[20])
    {
        int i,x,record=0;
        for(i=1; i<=n; i++)
        {
            f2>>name>>usn>>sem>>branch;
            f1>>x>>name;
            if(strcmp(name,key)==0)
            {
                record++;
                cout<<"Record "<<x<<" found & Details are\n";
                cout<<"Name="<<name<<"\n"<<"USN="<<usn<<"\n";
                cout<<"Sem="<<sem<<"\n"<<"Branch="<<branch<<"\n\n";
            }
        }
        if(record==0)
            cout<<"Record not found\n";
    }
    void remove(fstream &f1,fstream &f2,char key[20]);
};
student s[20],p;
void student::remove(fstream &f11,fstream &f22,char key[20])
{
    int start=0,x,record=0;
    char usn1[20];
    for(int i=1; i<=n; i++)
    {
        f22>>name>>usn>>sem>>branch;
        f11>>x>>name;
        if(strcmp(name,key)==0)
        {
            record=1;
            if(start==0)
            {
                start=1;
                cout<<"Enter the usn to delete : ";
                cin>>usn1;
            }
            if(strcmp(usn,usn1)==0)
                s[x].insert1(f11,f22);
            else record=0;
        }
    }
    fstream f1,f2;

    f1.open("secondary.txt",ios::out);
    f2.open("record.txt",ios::out);
    index1=0;
    for(int i=1; i<=n; i++)
        s[i].write(f1,f2);
    f1.close();
    f2.close();

    if(record==0)
        cout<<"Record not found\n\n";
    else cout<<"Deletion successful\n\n";
}
void sortsec()
{
    fstream f1,f2;
    f1.open("secondary.txt",ios::in);
    f2.open("record.txt",ios::in);
    index1=0;
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(strcmp(s[i].name,s[j].name)>0)
            {
                p=s[i];
                s[i]=s[j];
                s[j]=p;
            }
        }
    f1.close();
    f2.close();
}
int main()
{
    fstream f1,f2;
    int ch,k=0,i;

    string line;
    f1.open("secondary.txt",ios::in);
    while(getline(f1,line))
        n++;
    index1=n;
    f1.close();
    while(1)
    {
        cout<<"Enter\n1.Insert \n2.Display\n3.Search \n4.Delete\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            f1.open("secondary.txt",ios::app|ios::out);
            f2.open("record.txt",ios::app|ios::out);
            cout<<"Enter no. of students: ";
            cin>>k;
            for(int i=n+1; i<=n+k; i++)
                s[i].insert(f1,f2);
            n=n+k;
            f1.close();
            f2.close();
            sortsec();
            f1.open("secondary.txt",ios::out);
            f2.open("record.txt",ios::out);
            for(int i=1; i<=n; i++)
                s[i].write(f1,f2);
            f1.close();
            f2.close();
            break;
        case 2:
            f2.open("record.txt",ios::in);
            for(i=1; i<=n; i++)
                s[i].display(f2);
            f2.close();
            break;
        case 3:
            char name[20];
            cout<<"Enter name to search: ";
            cin>>name;
            f1.open("secondary.txt",ios::in);
            f2.open("record.txt",ios::in);
            int j;
            p.search(f1,f2,name);
            f1.close();
            f2.close();
            break;
        case 4:
            f1.open("secondary.txt",ios::in|ios::out);
            f2.open("record.txt",ios::in|ios::out);
            cout<<"Enter name to delete: ";
            cin>>name;
            p.remove(f1,f2,name);
            f1.close();
            f2.close();
            break;
        case 5:exit(0);
        default: cout<<"Invalid Option\n";
        }
    }
}

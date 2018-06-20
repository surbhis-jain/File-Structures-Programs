//Write a C++ program to reclaim the free space resulting from the deletion of records using linked lists.
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;
class node
{
	public:
        char name[15], usn[15];
		node * link;
};
node * first=NULL;
void writefile()
{
	node * p;
	char buffer[100];
	fstream out;
	out.open("student.txt",ios::app);
	p=first;
	while(p!=NULL)
	{
		strcpy(buffer,p->name);
		strcat(buffer,"|");
		strcat(buffer,p->usn);
		strcat(buffer,"\n");
		out<<buffer;
		p=p->link;
	}
}

void display()
{
	node * p;
	if(first==NULL)
	{
		cout<<"The list is empty.";
		return;
	}
	p=first;
	while(p!=NULL)
	{
		cout<<"|"<<p->name<<" "<<p->usn<<"|"<<"->";
		p=p->link;
	}
}

void insert()
{
	char name[20];
	char usn[15];
	node *p;
	node *q;

	cout<<"\nEnter name\n";
	cin>>name;
	cout<<"\nEnter USN\n";
	cin>>usn;
	cout<<"\n";
	
	p=new node;
	strcpy(p->name,name);
	strcpy(p->usn,usn);
	p->link=NULL;

	if(first==NULL)
	{
		first=p;
		writefile();
		display();
		return;
	}
	for(q=first;q->link!=NULL;q=q->link)
	{
		;
	}
	q->link=p;
	writefile();
	display();
}

void del()
{
	char usn[15];
	node * curr;
	node * prev;
	node * del;
	if(first==NULL)
	{
		printf("Deletion not possible. The list is empty.");
		return;
	}
    cout<<"Enter the USN to be deleted :";
	cin>>usn;
	if(strcmp(first->usn,usn)==0)
	{
		cout<<"Record deleted.\n";
		del=first;
		delete(del);
		first=first->link;
		writefile();
       display();
		return;
	}
	prev=NULL;
	curr=first;
	while((strcmp(curr->usn,usn)!=0) && curr!=NULL)
	{
		prev=curr;
		curr=curr->link;
	}
	if(curr==NULL)
	{
		cout<<"The student with USN"<<usn<<"is not present.";
		return;
	}
	prev->link=curr->link;
	writefile();
	display();
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1 : Insert \n2 : Delete using USN \n3 : Exit \n\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insert();
                    break;
			case 2:	del();
                    break;

			case 3:	exit(0);
            default: cout<<"invalid option";
                exit(0);
		}
	}
	return 0;
}	

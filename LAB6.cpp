//LABSET 6
//Write a C++ program to read two lists of names and then merge the names of two lists to a single list by
//performing Co-sequential Match() operation and display the contents of all the lists.

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

class coseq
{
	public:
		string list1[100],list2[100];
		int count1, count2;
		void read_lists();
		void sort_lists();
		void match_lists();
};


int main()
{
	coseq c;
	c.read_lists();
	c.sort_lists();
    cout<<"\n\nCommon Names in Both Lists Are : \n";
	c.match_lists();
	return 0;
}

void coseq::read_lists()
{
	fstream fp;
	string name;
    int n,j;
	count1 = 0;		// Initially 0 names in arrays
    fp.open("list11.txt",ios::out);
    cout<<"Enter the number of name you want to enter in LIST 1  \n";
    cin>>n;
    cout<<"Enter "<<n<<" names:\n";
    for(j=0;j<n;j++)
    {
        cin>>name;
        fp<<name<<endl;
    }
    fp.close();
    fp.open("list11.txt",ios::in);
	while(getline(fp,name))
	{
		list1[count1++]=name;		//store in array
	}
	fp.close();
    count2 = 0;  //Now same thing for the next file.
    fp.open("list22.txt",ios::out);
    cout<<"Enter the number of name you want to enter in LIST 2 "<< ": \n";
    cin>>n;
    cout<<"Enter "<<n<<" names:\n";
    for(j=0;j<n;j++)
    {
        cin>>name;
        fp<<name<<endl;
    }
    fp.close();
       fp.open("list22.txt",ios::in);
	while(getline(fp,name))
	{
		list2[count2++]=name;
	}
	fp.close();
}
void coseq::sort_lists()
{
	int i,j;

	for(i=0;i<count1;i++)
	{
		for(j=i+1;j<count1;j++)
		{
			if(list1[i]>list1[j])
			{
                swap(list1[i],list1[j]);
			}
		}
	}
    
    cout<<"\nThe Sorted Contents of List 1 : \n";
    for(i=0;i<count1;i++)
        cout<<list1[i]<<"\n";

	for(i=0;i<count2;i++)           //Now same thing for the second list.
	{
		for(j=i+1;j<count2;j++)
		{
			if(list2[i]>list2[j])
			{
                swap(list2[i],list2[j]);
			}
		}
	}

    cout<<"\nThe Sorted Contents of List 2 : \n";
    for(i=0;i<count2;i++)
        cout<<list2[i]<<"\n";
}

void coseq::match_lists()
{
	int i=0,j=0;
    fstream fp;
    fp.open("output1.txt",ios::out);
	while(i<=count1 && j<=count2)
	{
		if(list1[i]==list2[j])
		{
			cout<<list1[i]<<endl;
			fp<<list1[i]<<endl;
			i++;
			j++;
		}
		if(list1[i]<list2[j])i++;
		if(list1[i]>list2[j])j++;
	}
    fp.close();
}

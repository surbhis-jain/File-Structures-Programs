// LABSET 7
//Write a C++ program to read K Lists of names and merge operation using K-way merge algorithm with K = 4.
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;
int n,j;
char name[20];
class coseq
{
	public:
		string list[4][50];
		string outlist[200];
		int count1[4],count2[4];
		void read_file(int i);
		void sort_list(int i);
		void kwaymerge();
};
int main()
{
	coseq c;
	for(int i=0; i<4; i++)
	{
		c.count1[i] = 0;
		c.read_file(i);
		c.sort_list(i);
	}
	c.kwaymerge();
	return 0;
}

void coseq::read_file(int i)
{
	fstream fp;
	string name;
	switch(i)
	{
		case 0:fp.open("list1.txt",ios::out);
            cout<<"Enter the number of name you want to enter in LIST "<<i+1<< ": \n";
            cin>>n;
            cout<<"Enter "<<n<<" names:\n";
            for(j=0;j<n;j++)
            {
                cin>>name;
                fp<<name<<endl;
            }
            fp.close();
            fp.open("list1.txt",ios::in);break;
		case 1:
            fp.open("list2.txt",ios::out);
            cout<<"Enter the number of name you want to enter in LIST "<<i+1<< ": \n";
            cin>>n;
            cout<<"Enter "<<n<<" names:\n";
            for(j=0;j<n;j++)
            {
                cin>>name;
                fp<<name<<endl;
            }
            fp.close();
            fp.open("list2.txt",ios::in);break;
		case 2:
            fp.open("list3.txt",ios::out);
            cout<<"Enter the number of name you want to enter in LIST "<<i+1<< ": \n";
            cin>>n;
            cout<<"Enter "<<n<<" names:\n";
            for(j=0;j<n;j++)
            {
                cin>>name;
                fp<<name<<endl;
            }
            fp.close();
            fp.open("list3.txt",ios::in);break;
		case 3:
            fp.open("list4.txt",ios::out);
            cout<<"Enter the number of name you want to enter in LIST "<<i+1<< ": \n";
            cin>>n;
            cout<<"Enter "<<n<<" names:\n";
            for(j=0;j<n;j++)
            {
                cin>>name;
                fp<<name<<endl;
            }
            fp.close();
            fp.open("list4.txt",ios::in);
            break;
	}
	while(getline(fp,name))
	{
        list[i][count1[i]++]=name;
	}
	fp.close();
}

void coseq::sort_list(int k)
{
	int i,j;
	for(i=0;i<count1[k];i++)
	{
		for(j=i+1;j<count1[k];j++)
		{
			if(list[k][i]>list[k][j])
            {
                swap(list[k][i],list[k][j]);
			}
		}
	}
}

void coseq::kwaymerge()
{
    fstream fp1;
	string sml;
	int s_list,count3=0,start=0,avail_list=4,avail[4],i;
	for(i=0;i<4;i++)
	{
		avail[i]=1;
		count2[i]=0;
	}
	while(avail_list>1)
	{
		if(!avail[start])
		{
			start++;
			continue;
		}
		s_list=start;
		sml=list[start][count2[start]];
		for(i=start+1;i<4;i++)
		{
			if(!avail[i])
				continue;
			if(list[i][count2[i]]<sml)
			{
				sml=list[i][count2[i]];
				s_list=i; 
			}
		}
		count2[s_list]++;
		if(count2[s_list]==count1[s_list])
		{
			avail[s_list]=0;
			avail_list--;
		}
		outlist[count3++]=sml;	
	}
	for(i=0;i<4;i++)
		if(avail[i])
		{
			for(int j=count2[i];j<count1[i];j++)
				outlist[count3++]=list[i][j];
		}
	fp1.open("output.txt",ios::out);
	cout<<"\nMerged list:\n";
	for(i=0;i<count3;i++)
	{	
		if(outlist[i]==outlist[i+1])continue;
        fp1<<outlist[i]<<endl;
			cout<<outlist[i]<<endl;
	}    
}

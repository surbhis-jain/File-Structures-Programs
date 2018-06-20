//LABSET 5
 /* Write a C++ Program to read two lists of names and then merge the names of two lists to a
 single list by performing Co-Sequential merge() operation and display the contents of all the lists*/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std; 
void sortnames(char names[][100],int n)
{
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {
           if(strcmp(names[i],names[j])>0) // if(strcasecmp(names[i],names[j])>0)
           {
              swap(names[i],names[j]);
           }
        }
     }
}
int main()
{
    fstream f1,f2,fout;
    char list1[100][100],list2[100][100],list3[100][100];
    int n,m;
    cout<<"\n Enter the number of names for list1:\n";
    cin>>n;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<n;i++)
    cin>>list1[i];
    cout<<"\n Enter the number of names for list2:\n";
    cin>>m;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<m;i++)
    cin>>list2[i];
    cout<<"\n The sorted contents of list1:\n";
    sortnames(list1,n);
    f1.open("list1.txt",ios::out);
    for(int i=0;i<n;i++)
    {
      cout<<list1[i]<<endl;
      f1<<list1[i]<<endl;
    }
    f1.close();
    cout<<"\n The sorted contents of list2:\n";
    sortnames(list2,m);
    f2.open("list2.txt",ios::out);
    for(int i=0;i<m;i++)
    {
      cout<<list2[i]<<endl;
      f2<<list2[i]<<endl;
    }
    f2.close();
    f1.open("list1.txt",ios::in);
    f2.open("list2.txt",ios::in);
    string name;
    int i=0;
    while(getline(f1,name))
    {
       strcpy(list3[i],name.c_str());
       i++;
    }
    while(getline(f2,name))
    {
       strcpy(list3[i],name.c_str());
       i++;
    }
    int n1=i;
    for(int i=0;i<n1;i++)
    {
      for(int j=i+1;j<n1; )
      {
        if(strcmp(list3[i],list3[j])==0)
        {
           for(int k=j;k<n1;k++)
           {
              strcpy(list3[j],list3[j+1]);
              n1--;
           }
        }
        else
         j++;
      }
   }
   sortnames(list3,n1);
   cout<<"\n The merging of two lists are:\n";
   fout.open("output.txt",ios::out);
   for(int i=0;i<n1;i++)
   {
     cout<<list3[i]<<"\n";
     fout<<list3[i]<<endl;
   }
   fout.close();
   return 0;
}

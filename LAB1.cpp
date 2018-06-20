
/*LABSET 1 Write a C++ program to read series of names, one per line, from standard input and write these names spelled in reverse order to the standard output using I/O redirection and pipes.
Repeat the exercise using an input file specified by the user instead of the
standard input and using an output file specified by the user instead of the standard output*/

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class names{
    public:char name[50];
  };
void reverse(ofstream &out,char name[])
{
    char *rev;
    rev=name+strlen(name)-1;
    while(rev>=name){
            cout<<*rev;
            out<<*rev;
            rev--;
    }
    cout<<endl;
    out<<"\n";
}
int main(){
    names n[10];
    ofstream out,fout;
  	out.open("outputfile.txt",ios::out);
  	fout.open("inputfile.txt",ios::out);
    int m;
    cout<<"enter the no. of names to be entered\n";
    cin>>m;
    for(int i=0;i<m;i++){
        cout<<"Enter name: ";
            cin>>n[i].name;
            fout<<n[i].name<<endl;
        cout<<"The name in reverse order: ";
            reverse(out,n[i].name);
    }
    out.close();
    fout.close();
    ifstream in,fin;
    string name;
    in.open("inputfile.txt",ios::in);
    cout<<"Names from file\n";
    while(in>>name)
    {
    	cout<<name<<endl;
    }
    in.close();
  
    fin.open("outputfile.txt",ios::in);
    cout<<"Reverse order from file\n";
    while(fin>>name)
    {
        cout<<name<<endl;
    }
    fin.close();
    return 0;
}

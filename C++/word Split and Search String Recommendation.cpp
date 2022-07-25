#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//Problem Statement: 
//Accept a sentence consisting of words as input 
//Split the sentence into individual words using Recursion alone
//For an input search string, generate string matching recommendations

//Solution Assumptions:
//Assumption for the input string to terminate with a Space 
//Assumption for the words in the sentence to be delimited by space 

//Using only Recursion

vector<std::string> s;
int von(std::string a, int i, std::string &g){
	if((int)a.at(i)==32){
		g+='\0';
		return (i+1);
	}
	else{
		g=g+a.at(i);
		i++;
		int p=von(a,i,g);
		return p;
	}
}
void substr(std::string a,int i){
	if(a.at(i)=='\0'){
		return ;
	}
	else{
		std::string g;
		int k=von(a,i,g);
		s.push_back(g);
		substr(a,k);
	}
}
void search(std::string a,int i){
	if(i==s.size())
	return ;
	else{
		if(a.size()<=s.at(i).size()&&s.at(i).substr(0,a.size())==a)
			cout<<s.at(i)<<"\t";
			i++;
			search(a,i);
		
	}
}

int main(){
	cout<<"\nEnter a String : ";
	std::string p,t;
	getline(cin,p,'\n');
	p+='\0';
	int i=0;
	substr(p,i);
    cout<<endl<<"Search String : ";
    cin>>t;
    search(t,i);
    //Alternative to getch()
	int x;
	cin>>x;
	
}

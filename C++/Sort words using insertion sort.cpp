#include<iostream>
using namespace std;
//To input the strings and sort the same using Insertion sort 
//Not to use any of the CPP Datastructures,
//Must to use double pointers wherever string object is necessary 


char ** allocmem(int x,int y){
	char **a=new char*[x];
	for(int i=0;i<x;i++){
		a[i]=new char[y];
	}
	return a;
}
void swap(char **a,char **b){
	char *c=*a;
	*a=*b;
	*b=c;
}

//Basic Logic of Insertion sort 
void insertion_sort_word(char* a[],int n){
//Start comparing the ith letter with the i+1th letter 
for(int i=0;i<n-1;i++){
	if(a[i][0]>=a[i+1][0]){
		int p=0,k=i;//p to manage looping , k to point to the preceeding words in case of a swap
		do{ //do while loop is used as the comparison is guaranteed to satisfy >= criteria given as i clauses inside the loop
		int j=0;
		while(1){
			if(a[k][j]==a[k+1][j])
			j++;
			else if(a[k][j]<a[k+1][j]){
			p=0;
			break;
		    }
			else if(a[k][j]>a[k+1][j]){
				swap(a[k],a[k+1]);
				k--;
				p=1;
				break;
			}
			if(a[k][j]=='\0'||a[k+1][j]=='\0'){
				if(a[k+1][j]=='\0'){
				swap(&a[k],&a[k+1]);
				k--;
				p=1;	
				break;
				}
				else
				p=0;
			}	
		}
		
	}while(p&&k!=-1); //terminate looping either if the first word has been compared in backtracking or the present word is less than the successive word
}
}
}
int main(){
	int i,j;
	cout<<"\nEnter the number of words : ";
	cin>>i;
	//Default length of each word is set to 30
	j=30;
	
	char **b=allocmem(i,30);
	for(int k=0;k<i;k++){ //for loop to input the set of words 
		char *a=new char[30];
		cin>>a;
		b[k]=a;
	}
	insertion_sort_word(b,i);
	cout<<endl<<"Printing the sorted words . . ."<<endl;
	for(int k=0;k<i;k++)
	cout<<b[k]<<"\t";
	cout<<endl;
	
}

/* Pattern 
   * 
  * * 
 * * * 
* * * * 
 * * * 
  * * 
   * 
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0)
    n=n+1;
    for(int i=0;i<n;i++){
        cout<<endl;
        if(i<=n/2){
            for(int j=0;j<n/2-i;j++)
            cout<<' ';
            for(int k=0;k<i+1;k++){
                cout<<"* ";}}
        else{
            int j;
            for(j=0;j<i-n/2;j++)
                cout<<' ';
            for(int k=0;k<n-i;k++)
                cout<<"* ";
                
            }
            
        }
}

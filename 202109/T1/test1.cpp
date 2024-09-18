#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;cin>>n;
  vector<int>b(n+1,0);
  int max=0;
  int min=0;
  for(int i=1;i<=n;i++){
    cin>>b[i];
    if(b[i]>b[i-1]){
      max+=b[i];
      min+=b[i];
    }
    else{
      max+=b[i];
      min+=0;
    }
  }
  cout<<max<<endl;
  cout<<min;
  return 0;
}
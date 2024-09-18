#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m,L;
  cin>>n>>m>>L;
  map<int,int>mp;
  for(int i=0;i<L;i++){
    mp[i]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int t;cin>>t;
      mp[t]++;
    }
  }
  for(auto it:mp){
    cout<<it.second<<" ";
  }
  return 0;
}
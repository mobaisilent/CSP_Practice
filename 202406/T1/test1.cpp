#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m,p,q;
  cin>>n>>m>>p>>q;
  vector<int>mv1;
  vector<vector<int>>mv2(p,vector<int>(q,0));
  for(int i=0;i<n*m;i++){
    int t;cin>>t;
    mv1.push_back(t);
  }
  int cnt=0;
  for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
      mv2[i][j]=mv1[cnt++];
    }
  }
  for(auto it:mv2){
    for(auto itt:it){
      cout<<itt<<" ";
    }
    cout<<endl;
  }
  return 0;
}
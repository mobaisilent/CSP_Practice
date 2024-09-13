#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>mv(m+1,vector<int>(3))
  for(int i=1;i<=m;i++){
    int t1,t2;
    cin>>t1>>t2;
    mv[i][1]=t1;
    mv[i][2]=t2;
  }

  return 0;
}
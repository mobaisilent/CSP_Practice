#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,L,r,t;
  cin>>n>>L>>r>>t;
  vector<vector<int>>mv(n+1,vector<int>(n+1,0));
  vector<vector<int>>sum(n+1,vector<int>(n+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>mv[i][j];
    }
  }
  // for(auto it:mv){
  //   for(auto itt:it){
  //     cout<<itt<<" ";
  //   }
  //   cout<<endl;
  // }
  sum[1][1]=mv[1][1];
  for(int j=2;j<=n;j++){
    sum[1][j]=sum[1][j-1]+mv[1][j];
    sum[j][1]=sum[j-1][1]+mv[j][1];
  }
  for(int i=2;i<=n;i++){
    for(int j=2;j<=n;j++){
      sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mv[i][j];
    }
  }
  // for(auto it:sum){
  //   for(auto itt:it){
  //     cout<<itt<<" ";
  //   }
  //   cout<<endl;
  // }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int lx=i-r<1?1:i-r;
      int ly=j-r<1?1:j-r;
      int rx=i+r>n?n:i+r;
      int ry=j+r>n?n :j+r;
      // cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry;
      // cout<<endl;
      int tmp=sum[rx][ry]-sum[lx-1][ry]-sum[rx][ly-1]+sum[lx-1][ly-1];
      int cnt=(rx-lx+1)*(ry-ly+1);
      // cout<<"tmp="<<tmp<<" cnt="<<cnt<<endl;
      if((double)tmp/cnt<=(double)t){
        // cout<<"-------------- here i="<<i<<" j="<<j<<endl;
        ans++;
      }
    }
  }
  cout<<ans;
  return 0;
}
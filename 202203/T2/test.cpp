#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m,k;
  cin>>n>>m>>k; // 分别表示出行计划数目、查询个数以及等待核酸检测结果所需时间
  vector<vector<int>>mv(n+1,vector<int>(3,0));
  for(int i=1;i<=n;i++){
    cin>>mv[i][1];
    cin>>mv[i][2];
  }
  for(int i=1;i<=m;i++){
    int q;cin>>q;
    int end=q+k;
    int ans=0;
    // 这个循环需要优化呢
    for(int j=1;j<=n;j++){
      if(mv[j][1]<end) continue;
      if(mv[j][1]<=(end+(mv[j][2]-1))) ans++;
      // end<mv[j][1]<=end+mv[j][2]-1
    }
    cout<<ans<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int check[105]={0};
bool test[105]={false};
// 犯了一个错误就是数组的初始化这里应该是一个确定的数字 比如 bool check[m]={flase}; 这就是错的

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>mv(m+1,vector<int>(3));
  vector<vector<int>>ans(m+1,vector<int>(3,0));
  for(int i=1;i<=m;i++){
    int t;
    cin>>t;
    mv[i][1]=t;
  }

  for(int i=1;i<=m;i++){
    int t;
    cin>>t;
    mv[i][2]=t;
  }
  for(int i=1;i<=m;i++){
    int tmp=i;
    int cnt=0;
    if(mv[i][1]!=0){
      while(mv[tmp][1]!=0){
        tmp=mv[tmp][1];
        cnt+=mv[tmp][2];
      }
    }
    ans[i][1]=cnt+1;
  }
  int flag=1;
  for(int i=1;i<=m;i++){
    cout<<ans[i][1]<<" ";
    // 反向赋值即可
    int j=m+1-i;
    if(ans[j][2]==0){
      int have=n-(ans[j][1]+mv[j][2]-1);
      if(have<0) flag=0;
      // 计算得到冗余时间（天数  冗余多少天那么最后的时间就是加上多少天，冗余0天就是加上0天，那么就是最晚开始时间就是最早开始时间
      // cout<<"here check have="<<have<<endl;
      int ttt=j;
      if(mv[ttt][1]!=0){
        while(mv[j][1]!=0){
          // cout<<"here check j="<<j<<endl;
          check[j]=1;  
          ans[j][2]=ans[j][1]+have;
          j=mv[j][1];
        }
        // 这是只考虑到了有前置节点的情况
          check[j]=1;  
          ans[j][2]=ans[j][1]+have;
          j=mv[j][1];
      }
      else {
        if(check[ttt]==0)
        ans[ttt][2]=n+1-(ans[ttt][1]+mv[ttt][2]-1);
      }
    }
  }
  if(flag==1){
    cout<<endl;
    for(int i=1;i<=m;i++){
      cout<<ans[i][2]<<" ";
    }
  }
  return 0;
}
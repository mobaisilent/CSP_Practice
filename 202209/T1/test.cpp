#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>a(n+1,0);
  for(int i=1;i<=n;i++){
    int t;cin>>t;
    a[i]=t;
  }
  // 获取基础a数组
  vector<long long int>c(n+1,1);
  for(int i=1;i<=n;i++){
    if(i==1) c[i]*=a[i];
    else c[i]*=(c[i-1]*a[i]);
  }

  // 根据累乘式子直接获取b的值即可
  vector<long long int>d(n+1,1);
  for(int i=1;i<=n;i++){
    d[i]=m%c[i];
  }
  vector<long long int>e(n+1,1);
  for(int i=1;i<=n;i++){
    if(i==1) e[i]=d[i];
    else e[i]=d[i]-d[i-1];
  }
  vector<long long int>ans(n+1,0);
  for(int i=1;i<=n;i++){
    ans[i]=e[i]/c[i-1];
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}
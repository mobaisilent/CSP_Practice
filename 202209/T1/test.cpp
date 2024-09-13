#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  vector<int>a(n+1,0);
  for(int i=1;i<=n;i++){
    int t;cin>>t;
    a[i]=t;
  }
  // 获取基础a数组
  vector<int>c(n+1,1);
  for(int i=1;i<=n;i++){
    if(i==1) c[i]*=a[i];
    else c[i]*=(c[i-1]*a[i]);
  }
  // 获取a的乘积c数组
  
  return 0;
}
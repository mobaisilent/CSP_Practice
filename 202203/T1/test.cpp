#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;  // 变量的数量和赋值语句的条数
  cin>>n>>k;
  map<int,int>cnt;
  int ans=0;
  for(int i=1;i<=k;i++){
    int t1,t2;  // 左/右
    cin>>t1>>t2;
    if(cnt.find(t2)==cnt.end()&&t2!=0) ans++;
    if(cnt.find(t1)==cnt.end()) cnt[t1]=i;
  }
  cout<<ans;
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;cin>>n;
  vector<int>mv(n+2,0);
  set<int>ms; ms.insert(1);
  int t=0;
  for(int i=1;i<=n;i++){
    cin>>mv[i];
    t+=mv[i];
    ms.insert(mv[i]);
  }
  vector<int>check(n+2,0);
  int ans=0;
  for(auto it:ms){
    check=mv;
    if(it==0)continue;
    for(int i=1;i<=n;i++){
      if(check[i]<=it) check[i]=0;
      else check[i]=1;
    }
    int tmp=0;
    for(int i=0;i<=n+1;i++){
      if(check[i]>0){
        tmp++;
        while(check[i]>0){
          i++;
          if(i>=n+2) break;
        }
      }
    }
    ans=max(ans,tmp);
  }
  if(t==0) cout<<0;
  else cout<<ans;
  return 0;
}
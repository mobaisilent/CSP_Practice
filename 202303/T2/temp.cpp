#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  long long int m;
  cin>>n>>m>>k;
  vector<vector<int>> mv(n+1,vector<int>(3));
  map<int,int>flag;
  int max=0;
  for(int i=1;i<=n;i++){
    cin>>mv[i][1]>>mv[i][2];  // 从下标1开始
    if(max<mv[i][1]) max=mv[i][1];
    flag[mv[i][1]]+=mv[i][2];
  }
  for(int i=max;i>=1;i--){
    if(max==k) break;
    if(m>=flag[i]){
      m-=flag[i];
      max--;
      if(i>1){
        flag[i-1]+=flag[i];
      }
    }  
    else break;
  }
  cout<<max;
  return 0;
}
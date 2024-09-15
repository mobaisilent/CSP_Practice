#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,l,s;
  int ans=0;
  cin>>n>>l>>s;
  vector<vector<int>>ldots(2005,vector<int>(2005,0));
  // 先考虑拿70分
  for(int i=1;i<=n;i++){
    int x,y;
    cin>>x>>y;
    ldots[x][y]=1;
  }
  vector<vector<int>>sdots(55,vector<int>(55,0));
  for(int i=s;i>=0;i--){
    for(int j=0;j<=s;j++){
      cin>>sdots[i][j];
    }
  }
  for(int i=0;i<=l-s;i++){
    for(int j=0;j<=l-s;j++){
      int t1=i+s,t2=l+s;
      // 界定终点
      int flag=1;
      for(int l=i,ll=0;ll<=s;l++,ll++){
        for(int k=j,kk=0;kk<=s;k++,kk++){
          if(ldots[l][k]!=sdots[ll][kk]) flag=0;
        }
        if(flag==0)break;
      }
      if(flag) ans++;
    }
  }
  cout<<ans;
  return 0;
}
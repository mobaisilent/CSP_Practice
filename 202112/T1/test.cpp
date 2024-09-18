#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,N;
  cin>>n>>N;
  vector<int>mv(n+1,0);
  int sum=0;
  for(int i=1;i<=n;i++){
    cin>>mv[i];
  }
  // 先获取基础数组
  // 选好flag然后直接按照规律计算即可
  int i=0;
  int flag=0;
  for(i=0;i<=n;){
    if(mv[i]>N){
      i--;break;
    }
    else{
      i++;
      if(i==n+1){  // 已经开始溢出了
        i--;
        break;
      }
    }
  }
  // i表示最高可以买到的商品序号  // 那么按照两件商品直接的差值直接计算即可
  for(int j=0;j<n;j++){
    int k=j+1;
    int tmp=(mv[k]-mv[j])*j;
    sum+=(mv[k]-mv[j])*j;
    if(k==i) break;
  }
  sum+=(N-mv[i])*i;
  cout<<sum;
  return 0;
}
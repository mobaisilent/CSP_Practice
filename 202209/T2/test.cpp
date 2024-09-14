#include<bits/stdc++.h>

using namespace std;

void getSub(const vector<int>cart,vector<int>&subcart,int start,int k,map<int,int>&mp){
  if(subcart.size()==k){
    int sum=0;
    for(auto it:subcart){
      sum+=it;
    }
    mp[sum]++;
    return;
  }

  for(int i=start;i<=cart.size()-1;i++){
    subcart.push_back(cart[i]);
    getSub(cart,subcart,i+1,k,mp);
    subcart.pop_back();
  }
}

int main(){
  int n,x;
  cin>>n>>x;
  vector<int>cart(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>cart[i];
  }
  sort(cart.begin(),cart.end());
  // 然后在这个数组里面选取最小的几个数字接近x
  vector<int>subcart;
  map<int,int>mp;
  for(int i=1;i<=n;i++){ // i表示当前需要获取的子数组长度
    getSub(cart,subcart,1,i,mp);
  }
  for(auto it:mp){
    if(it.first>=x){
      cout<<it.first;
      break;
    }
  }
  return 0;
}
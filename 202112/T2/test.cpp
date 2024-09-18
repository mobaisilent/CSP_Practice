#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,N;
  cin>>n>>N;
  vector<int>mv(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>mv[i];
  }
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
  int r=N/(n+1);
  double ret=0;
  int tt=0;
  for(int j=0;j<n;j++){
    int k=j+1;
    int tmp=mv[j];if(tmp==0) tmp++;
    while(tmp<=mv[k]-1){
      if(tmp%r==0){
        cout<<"here in while1 if tmp="<<tmp<<endl;
        // 计算tmp及其后面一个r区间
        int t1=j*r;
        int t2=(tmp/r)*r;  // emm写着写着发现区间和就是前面那个数字
        ret+=abs(t1-t2);
        tmp+=r;
        if(tmp>=mv[i]-1){
          cout<<"here"<<endl;
          t1=(tmp-(mv[i]-1))*i;
          t2=(tmp-(mv[i]-1))*r;
          ret+=abs(t1-t2);
        }
      }
      else{
        cout<<"here in while1 else tmp="<<tmp<<endl;
        // 计算tmp单个节点值
        int tmp1=j;
        int tmp2=tmp/r;
        ret+=abs(tmp1-tmp2);
        tmp++;
      }
      tt=tmp;
    }
    if(k==i) break;
  }
  cout<<"here ret="<<ret<<endl;
  cout<<"here begin outer while tt="<<tt<<endl;

  while(tt<=N-1){
    if(tt%r==0){
      cout<<"here in while2 if tt="<<tt<<endl;
      // 计算tmp及其后面一个r区间
      int t1=i*r;
      int t2=(tt/r)*r;  // emm写着写着发现区间和就是前面那个数字
      ret+=abs(t1-t2);
      tt+=r;
      // 最后这里加到溢出了:下面是处理溢出
      if(tt>=N-1){
        t1=(tt-(N-1))*i;
        t2=(tt-(N-1))*r;
        ret+=abs(t1-t2);
      }
    }
    else{
      cout<<"here in while2 else tt="<<tt<<endl;
      // 计算tmp单个节点值
      int tmp1=i;
      int tmp2=tt/r;
      ret+=abs(tmp1-tmp2);
      cout<<"Here"<<endl;
      tt++;
    }
  }
  cout<<ret;
  return 0;
}
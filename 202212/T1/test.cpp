#include<iostream>
#include<math.h>

using namespace std;

double solve(double i,int k){
  double t=1+i;
  t=1/(t);
  double ret=1;
  while(k--){
    ret*=t;
  }
  // cout<<ret<<endl;
  return ret;
}

int main(){
  double n;double k;
  cin>>n>>k;
  double sum=0;
  double ori;
  cin>>ori;
  for(int i=1;i<=n;i++){
    double x;
    cin>>x;
    sum+=(x*solve(k,i));
  }
  // cout<<sum<<endl;
  if((ori*(-1))>sum){
    cout<<"-"<<ori*(-1)-sum;
  }else{
    cout<<sum-((-1)*ori);
  }
  return 0;
}
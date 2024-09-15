#include<bits/stdc++.h>

using namespace std;

double getD(vector<int>arr,double a,int n){
  double ret=0;
  for(int i=1;i<=n;i++){
    ret+=((arr[i]-a)*(arr[i]-a));
  }
  return (double)ret/(n*1.0);
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n+1,0);
  int sum=0;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  double a=(double)sum/n;
  // cout<<"a="<<a<<endl;
  double d=getD(arr,a,n);
  // cout<<"d="<<d<<endl;
  double temp=sqrt(d);
  // cout<<"temp="<<temp<<endl;
  for(int i=1;i<=n;i++){
    double tt=(double)(arr[i]-a)/sqrt(d);
    printf("%f\n",tt);
  }
  return 0;
}
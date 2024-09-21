#include<bits/stdc++.h>

using namespace std;

// 单独处理转置操作
void getM(vector<int>&ori,int n,int m){
  // n和m是新行新列
  // 那么原先就是m行n列
  vector<vector<int>>mv1(m,vector<int>(n,0));
  int cnt=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      mv1[i][j]=ori[cnt++];
    }
  }
  cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      ori[cnt++]=mv1[j][i];
    }
  }
}

int main(){
  int n,m,t;
  cin>>n>>m>>t;  // 总是记录当前行和当前列
  vector<int>ori(n*m,0);
  for(int i=0;i<n*m;i++){
    cin>>ori[i];
  }
  for(int i=0;i<t;i++){
    // for(auto it:ori){
    //   cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<"n="<<n<<" m="<<m<<endl;
    int t1,t2,t3;
    cin>>t1>>t2>>t3;
    if(t1==1){
      n=t2;m=t3;
    }
    else if(t1==2){
      swap(n,m);
      getM(ori,n,m);
    }
    else if(t1==3){
      // t1和t2是查询的行和列 n和m是矩阵存储的行和列
      // cout<<"here n="<<n<<" m="<<m<<endl;
      // for(auto it:ori){
      //   cout<<it<<" ";
      // }
      // cout<<endl;
      int k=t2*m+t3;
      // cout<<"k="<<k<<endl;
      cout<<ori[k]<<endl;
    }
  }
    return 0;
}
// 如果每次都得全部操作一遍显然超时，只能拿到80分
// 如果只是置换的话每个元素的位置都不变，但是思考转置之后的元素变化，或者说我就没次转置的时候改变一次数组？
// 别想太多好吧，也没什么难的，稍微优化下选数据就行了
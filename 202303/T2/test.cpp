#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;  // n块田地，最少时间
  long long int m;  
  map<int, int> tim, res, flag;
  cin >> n >> m >> k;
  int max = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tim[i] >> res[i];
    max = max > tim[i] ? max : tim[i];  // 最大天数
    flag[tim[i]] += res[i];
    // 把耗时相同的作为一组
  }
  // 那么现在就是有组，有消耗，有资源
  for (int i = max; i > 0; i--) {
    if (max == k) break;
    if (m > flag[i]) {
      m -= flag[i];
      flag[i - 1] += flag[i];  // 高天的组减去一天就并归到低天的组
      max--;  // 最大天数减一天
    } else
      break;
  }
  cout << max;
  // cout<<endl<<flag[100]<<endl;  // 即使flag[100]不存在但是这样操作之后就开了一个空间
  // cout<<flag.size()<<endl;  // size为8，前面的max遍历加上上面这个新开的空间
  return 0;
}
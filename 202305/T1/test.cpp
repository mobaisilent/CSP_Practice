#include <bits/stdc++.h>

using namespace std;

// 将8行矩阵作为一个字符串处理即可
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  getchar();
  // 向这里数字转字符务必使用getchar()，否则会出现错误
  string a[n];
  map<int, int> mp;
  int cnt = 0;
  int tmp = n;
  while (n--) {
    string s;
    for (int i = 0; i < 8; i++) {
      string t;
      getline(cin, t);
      s += t;
    }
    a[cnt++] = s;
  }
  for (int i = tmp-1; i >= 0; i--) {
    mp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] == a[j]) {
        mp[i]++;
      }
    }
  }
  for (auto i : mp) {
    cout << i.second << endl;
  }
  return 0;
}
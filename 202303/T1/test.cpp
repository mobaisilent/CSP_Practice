#include <bits/stdc++.h>

using namespace std;

int getArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  int a1 = min(max(x1, x2), max(x3, x4));
  int a2 = min(max(y1, y2), max(y3, y4));
  int b1 = max(min(x1, x2), min(x3, x4));
  int b2 = max(min(y1, y2), min(y3, y4));
  if (a1 > b1 && a2 > b2) {
    return (a1 - b1) * (a2 - b2);
  }
  return 0;
}

int main() {
  int n, x1, y1;
  cin >> n >> x1 >> y1;
  int ret = 0;
  while (n--) {
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ret += getArea(0, 0, x1, y1, x3, y3, x4, y4);
  }
  cout << ret << endl;
  return 0;
}
/*
#include<math.h>
#include<stdio.h>

#include<iostream>
using namespace std;

int main()
{
        double a1x,a1y,a2x,a2y;
        double b1x,b1y,b2x,b2y;
        cin>>a1x>>a1y>>a2x>>a2y>>b1x>>b1y>>b2x>>b2y;
        double a1,a2,b1,b2;
        a1=min(max(a1x,a2x),max(b1x,b2x));
        a2=min(max(a1y,a2y),max(b1y,b2y));
        b1=max(min(a1x,a2x),min(b1x,b2x));
        b2=max(min(a1y,a2y),min(b1y,b2y));

        double s;
        if((a1>b1)&&(a2>b2))
                s=(a1-b1)*(a2-b2);
        else
                s=0;
        printf("%.2f",s);
}
*/
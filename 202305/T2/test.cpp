#include <iostream>
#include <vector>

using namespace std;

void getMatrix(vector<vector<long long int>> &matrix, int n, int d) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= d; j++) {
      cin >> matrix[i][j];
    }
  }
}

void getTMatrix(vector<vector<long long int>> &from,
                vector<vector<long long int>> &to, int n, int d) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= d; j++) {
      to[j][i] = from[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, d;
  cin >> n >> d;
  vector<vector<long long int>> Q(n + 1, vector<long long int>(d + 1));
  vector<vector<long long int>> K(n + 1, vector<long long int>(d + 1));
  vector<vector<long long int>> V(n + 1, vector<long long int>(d + 1));
  getMatrix(Q, n, d);
  getMatrix(K, n, d);
  getMatrix(V, n, d);

  vector<vector<long long int>> KT(d + 1, vector<long long int>(n + 1));
  getTMatrix(K, KT, n, d);

  vector<int> M(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> M[i];
  }

  vector<vector<long long int>> QKT(n + 1, vector<long long int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= d; k++) {
        QKT[i][j] += Q[i][k] * KT[k][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      QKT[i][j] = QKT[i][j] * M[i];
    }
  }

  // 计算 QKT 和 V 的乘积
  vector<vector<long long int>> QKTV(n + 1, vector<long long int>(d + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= d; j++) {
      for (int k = 1; k <= n; k++) {
        QKTV[i][j] += QKT[i][k] * V[k][j];
      }
      cout << QKTV[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
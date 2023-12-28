#include "bits/stdc++.h"
using namespace std;

int max_spanning_forest_prim(vector<vector<int>>& adj, vector<int>& nodes) {
    int result = 0;
    vector<int> max_e(nodes.size(), 0);
    vector<bool> lookup(nodes.size(), false);

    for (size_t i = 0; i < nodes.size(); ++i) {
        int u = -1;
        for (size_t v = 0; v < nodes.size(); ++v) {
            if (lookup[v]) continue;
            if (u == -1 || max_e[v] > max_e[u]) u = v;
        }
        lookup[u] = true;
        result += max_e[u];
        for (size_t v = 0; v < nodes.size(); ++v) {
            if (adj[nodes[u]][nodes[v]] > max_e[v]) {
                max_e[v] = adj[nodes[u]][nodes[v]];
            }
        }
    }
    return result;
}

int checksum() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));
    vector<int> R(N), C(N);

    int total = 0;
    vector<vector<int>> adj(2 * N, vector<int>(2 * N));
    set<int> nodes;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> B[i][j];
            if (A[i][j] != -1) continue;
            adj[i][j + N] = adj[N + j][i] = B[i][j];
            nodes.insert(i);
            nodes.insert(j + N);
            total += B[i][j];
        }
    }
    for (int i = 0; i < N; ++i){
      cin >> R[i];
    } 
    for (int i = 0; i < N; ++i){
      cin >> C[i];
    } 
    vector<int> nodes_vec(nodes.begin(), nodes.end());
    return total - max_spanning_forest_prim(adj, nodes_vec);
}

int main() {
    int T;
    cin >> T;

    vector<int> answer;
    for (int case_num = 0; case_num < T; ++case_num) {
        answer.push_back(checksum());
    }

    cout << "Answers" << endl;
    for (int ans : answer) {
        cout << ans << endl;
    }

    return 0;
}

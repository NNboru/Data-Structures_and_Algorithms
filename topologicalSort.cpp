
int n; // number of vertices
vector<int> nbr[100001];
bool visited[100001];
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : nbr[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

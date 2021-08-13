
int n; // number of vertices
vector<int> nbr[100001];
bool vis[100001];
vector<int> ans;

void dfs(int v) {
	if (vis[i]) return;
    vis[v] = true;
    for (int u : nbr[v]) {
        if (!vis[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    ans.clear();
    for (int i = 1; i <= n; ++i)
		dfs(i);
    reverse(ans.begin(), ans.end());
}

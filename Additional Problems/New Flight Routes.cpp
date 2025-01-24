#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void dfs(int st, vector<vector<int>> &v, vector<int> &odw, int C, vector<int> &col) {
	odw[st] = -1;
	for (auto x : v[st]) {
		if (odw[x] == 0) {
			dfs(x, v, odw, C, col);
		}
	}
	odw[st] = C;
	col.push_back(st);
}

pair<vector<int>, int> scc(int n, vector<vector<int>> &v, vector<vector<int>> &vr) {
	vector<int> odw(n + 1);
	vector<int> odw2(n + 1);
	vector<int> col, tmp;
	int C = 1;
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0)
			dfs(i, v, odw, C, col);
	}
	reverse(col.begin(), col.end());
	for (auto x : col) {
		if (odw2[x] == 0) {
			dfs(x, vr, odw2, C, tmp);
			C++;
		}
	}
	return {odw2, C};
}

int search(int x, vector<bool> &marked, vector<bool> &sinks, vector<vector<int>> &w) {
	if (marked[x] == false) {
		marked[x] = true;
		if (sinks[x]) {
			return x;
		}
		for (auto y : w[x]) {
			auto res = search(y, marked, sinks, w);
			if (res != -1) {
				return res;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>());
	vector<vector<int>> vr(n + 1, vector<int>());
	vector<vector<int>> w(n + 1, vector<int>());
	vector<int> mapping(n + 1);
	vector<int> indegree(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		vr[b].push_back(a);
	}
	auto [odw, C] = scc(n, v, vr);
	if (C == 2) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (mapping[odw[i]] == 0) {
			mapping[odw[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto x : v[i]) {
			if (odw[i] != odw[x]) {
				w[mapping[odw[i]]].push_back(mapping[odw[x]]);
				indegree[mapping[odw[x]]]++;
			}
		}
	}

	vector<pair<int, int>> res;
	vector<bool> sink(n + 1);
	for (int i = 1; i < C; i++) {
		if (w[mapping[i]].size() == 0) {
			sink[mapping[i]] = true;
		}
	}
	vector<bool> marked(n + 1);
	vector<int> matching_sources, matching_sinks, not_matching_sources, not_matching_sinks;
	for (int x = 1; x < C; x++) {
		if (indegree[mapping[x]] == 0) {
			auto res = search(mapping[x], marked, sink, w);
			if (res == -1) {
				not_matching_sources.push_back(mapping[x]);
			} else {
				matching_sinks.push_back(res);
				matching_sources.push_back(mapping[x]);
			}
		}
	}
	for (int i = 1; i < C; i++) {
		if (marked[mapping[i]] == false && w[mapping[i]].size() == 0) {
			not_matching_sinks.push_back(mapping[i]);
			marked[mapping[i]] = true;
		}
	}
	vector<int> sources = matching_sources;
	sources.insert(sources.end(), not_matching_sources.begin(), not_matching_sources.end());
	vector<int> sinks = matching_sinks;
	sinks.insert(sinks.end(), not_matching_sinks.begin(), not_matching_sinks.end());

	int P = matching_sources.size();
	int N = sources.size();
	int M = sinks.size();
	int K = min(N, M);

	if (P > 0)
		res.emplace_back(0, P - 1);
	for (int i = 1; i < P; i++) {
		res.emplace_back(i, i - 1);
	}
	for (int i = P; i < K; i++) {
		res.emplace_back(i, i);
	}
	for (int i = K; i < N; i++) {
		res.emplace_back(0, i);
	}
	for (int i = K; i < M; i++) {
		res.emplace_back(i, 0);
	}

	cout << res.size() << "\n";
	for (auto [a, b] : res) {
		cout << sinks[a] << " " << sources[b] << "\n";
	}
	return 0;
}

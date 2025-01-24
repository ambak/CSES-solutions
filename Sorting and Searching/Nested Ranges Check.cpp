#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200009;

int d[N];
vector<tuple<int, int, int> > v;
int res[N], res2[N];

void insert(int x, int v) {
	for (; x < N; x += x & -x) {
		d[x] += v;
	}
}

int query(int x) {
	int res = 0;
	for (; x > 0; x -= x & -x) {
		res += d[x];
	}
	return res;
}

bool cmp(tuple<int, int, int> &l, tuple<int, int, int> &r) {
	return get<1>(l) < get<1>(r);
}
bool cmp2(tuple<int, int, int> &l, tuple<int, int, int> &r) {
	if (get<0>(l) == get<0>(r)) {
		return get<1>(l) > get<1>(r);
	}
	return get<0>(l) < get<0>(r);
}
bool cmp3(tuple<int, int, int> &l, tuple<int, int, int> &r) {
	if (get<0>(l) == get<0>(r)) {
		return get<1>(l) < get<1>(r);
	}
	return get<0>(l) > get<0>(r);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_tuple(a, b, i));
	}

	sort(v.begin(), v.end(), cmp);
	int act = get<1>(v[0]);
	int count = 1;
	get<1>(v[0]) = count;
	for (int i = 1; i < n; i++) {
		if (get<1>(v[i]) > act) {
			act = get<1>(v[i]);
			count++;
		}
		get<1>(v[i]) = count;
	}

	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < n; i++) {
		insert(get<1>(v[i]), 1);
	}
	for (int i = 0; i < n; i++) {
		insert(get<1>(v[i]), -1);
		res[get<2>(v[i])] = query(get<1>(v[i]));
	}

	sort(v.begin(), v.end(), cmp3);
	for (int i = 0; i < n; i++) {
		insert(get<1>(v[i]), 1);
	}
	for (int i = 0; i < n; i++) {
		insert(get<1>(v[i]), -1);
		res2[get<2>(v[i])] = query(N - 1) - query(get<1>(v[i]) - 1);
	}

	for (int i = 0; i < n; i++) {
		cout << (res[i] > 0 ? 1 : 0) << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << (res2[i] > 0 ? 1 : 0) << " ";
	}

	return 0;
}

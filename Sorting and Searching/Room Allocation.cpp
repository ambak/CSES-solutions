#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<tuple<int, int, int, int> > v;

struct cmp_set {
	bool operator()(const tuple<int, int, int, int> &l, const tuple<int, int, int, int> &r) const {
		if (get<1>(l) == get<1>(r)) {
			return get<2>(l) < get<2>(r);
		}
		return get<1>(l) < get<1>(r);
	}
};
set<tuple<int, int, int, int>, cmp_set> s;
set<int> rooms;

bool cmp(tuple<int, int, int, int> &l, tuple<int, int, int, int> &r) {
	if (get<0>(l) == get<0>(r)) {
		return get<1>(l) > get<1>(r);
	}
	return get<0>(l) < get<0>(r);
}
bool cmp2(tuple<int, int, int, int> &l, tuple<int, int, int, int> &r) {
	return get<2>(l) < get<2>(r);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_tuple(a, b, i, 0));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 2; i <= n; i++) {
		rooms.insert(i);
	}
	int maxroom = 1;
	get<3>(v[0]) = 1;
	s.insert(v[0]);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && get<1>(*s.begin()) < get<0>(v[i])) {
			rooms.insert(get<3>(*s.begin()));
			s.erase(s.begin());
		}
		int room = *rooms.begin();
		maxroom = max(room, maxroom);
		rooms.erase(rooms.begin());
		get<3>(v[i]) = room;
		s.insert(v[i]);
	}
	sort(v.begin(), v.end(), cmp2);
	cout << maxroom << "\n";
	for (auto r : v) {
		cout << get<3>(r) << " ";
	}

	return 0;
}

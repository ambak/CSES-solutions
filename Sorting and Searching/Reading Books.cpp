#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multiset<LL, std::greater<LL> > s;
multiset<LL, std::greater<LL> > sfirst;
multiset<LL, std::greater<LL> > ssecond;

void read(LL &time, LL &act, bool &done, multiset<LL, std::greater<LL> > &S) {
	if (!s.empty()) {
		time += *s.begin();
		act = *s.begin();
		s.erase(s.begin());
	} else if (!S.empty()) {
		time += *S.begin();
		act = -(*S.begin());
		S.erase(S.begin());
	} else {
		done = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		s.insert(a);
	}
	LL time = 0, time1 = 0, time2 = 0;
	LL act1 = -1, act2 = -1;
	bool done1 = false, done2 = false;
	while (!s.empty() || !sfirst.empty() || !ssecond.empty()) {
		if (time == time1) {
			read(time1, act1, done1, sfirst);
		}
		if (time == time2) {
			read(time2, act2, done2, ssecond);
		}
		if (done1 || done2) {
			time1 = max(time1, time2);
			time2 = max(time1, time2);
		}
		if (time < time1 && time < time2) {
			time = min(time1, time2);
			if (time == time1 && done1 == false) {
				if (act1 > 0) {
					ssecond.insert(act1);
				}
			}
			if (time == time2 && done2 == false) {
				if (act2 > 0) {
					sfirst.insert(act2);
				}
			}
		}
		done1 = false;
		done2 = false;
	}
	cout << max(time1, time2) << "\n";

	return 0;
}

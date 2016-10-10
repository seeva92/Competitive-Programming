#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long N, Q, t, f;
long long val[1000007];
vector<pair<pair<long long, long long>, long long>> queries;
long long actual[1000007];
map<long long, long long> freq, idx, freqelem;
void compute() {
	for (int i = 0; i < Q; i++) {
		cin >> t >> f;
		queries.push_back({{f, t}, i});
	}

	sort(queries.begin(), queries.end());
	// for (auto i : queries) {
	// 	cout << i.first.first << " " << i.first.second << " " << i.second << '\n';
	// }
	long long j = 0;
	long long len = queries.size();
	for (long long i = 0; i < N; i++) {
		long long temp = freq[val[i]];
		for (; j < len && queries[j].first.first <= temp; j++) {
			if (queries[j].first.second == 0) actual[queries[j].second] = val[i];
			else if (freqelem.count(queries[j].first.first) > 0) {
				actual[queries[j].second] = val[freqelem[queries[j].first.first]];
			} else actual[queries[j].second] = 0;
		}
	}

	for (; j < len; j++) actual[queries[j].second] = 0;

	for (long long i = 0; i < len; i++)
		cout << actual[i] << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> val[i];
		freq[val[i]]++;
		if (idx.count(val[i]) == 0) idx[val[i]] = i;
	}

	for (auto i : freq) {

		long long & re = freqelem[i.second];
		if (re == 0) re = idx[i.first];
		else re = min(re, idx[i.first]);
	}
	cin >> Q;
	compute();
}

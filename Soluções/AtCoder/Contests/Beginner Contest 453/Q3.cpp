#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Caso clássico de guloso que na verdade era DP por conta de casos safadissimos.

bool cz(ll o, ll d) {
	return (o < 0 && d > 0) || (o > 0 && d < 0);
}

int main() {
	int q, r = 0;
    cin >> q;

    unordered_map<ll, int> a{{1, 0}}, b;

    while (q--) {
        ll t;
        cin >> t;
        ll p = 2 * t;

        b.clear();
        for (auto [x, c] : a) {
            for (ll y : {x - p, x + p}) {
                int nc = c + cz(x, y);
                auto it = b.find(y);
                if (it == b.end() || it->second < nc) b[y] = nc;
            }
        }
        a.swap(b);
    }

    for (auto [_, c] : a) { r = max(r, c); }

    cout << r << endl;
}
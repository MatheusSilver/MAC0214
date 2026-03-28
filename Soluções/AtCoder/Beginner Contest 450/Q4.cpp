#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, K, dist = 0;
	cin >> N >> K;
    
    if (N == 1) {
        cout << 0 << endl; //Matemáticos são tão engraçadinhos...
        return 0;
    }
    
    vector<long long> A(N);

	for (long long i = 0; i < N; i++) cin >> A[i], A[i] %= K;
    
	sort(A.begin(), A.end());

    for (long long i = 0; i + 1 < N; i++)
        dist = max(dist, A[i + 1] - A[i]);

    dist = max(dist, A[0] + K - A[N-1]);

	cout << K - dist << endl;

	return 0;
}
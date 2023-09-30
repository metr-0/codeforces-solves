#include "bits/stdc++.h"

#define S 1000005
#define M 900000000

using namespace std;

typedef long long l;
typedef pair<l, l> ll;

typedef vector<l> vl;
typedef vector<vl> vvl;

typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef queue<l> ql;
typedef queue<ll> qll;

typedef stack<l> sl;
typedef stack<ll> sll;

typedef priority_queue<l> pql;
typedef priority_queue<ll> pqll;

vl get_primes(l limit, vl& min_prime_divs) {
	vl f(limit, 0);
	vl res;
	
	for (l i = 2; i < limit; i++) {
		if (f[i]) continue;
		f[i] = true; res.push_back(i);
		
		for (l j = i * i; j < limit; j += i)
			f[j] = true;
	}
	
	return res;
}

vl get_primes_with_min_divs(l limit, vl& min_prime_divs) {
	min_prime_divs = vl(limit, -1);
	min_prime_divs[0] = min_prime_divs[1] = -1;
	vl res;
	
	for (l i = 2; i < limit; i++) {
		if (min_prime_divs[i] != -1) continue;
		res.push_back(i);
		
		for (l j = i; j < limit; j += i) if (min_prime_divs[j] == -1)
			min_prime_divs[j] = res.size() - 1;
	}
	
	return res;
}

vl get_prime_divs(l n, vl &primes) {
	vl res(primes.size(), 0);
	
	for (l i = 0; i < primes.size(); i++) {
		if (primes[i] > n) continue;
		
		while (n % primes[i]) {
			n /= primes[i];
			res[i]++;
		}
	}
	
	return res;
}

vl get_prime_divs_by_min(l n, vl &primes, vl &min_prime_divs) {
	vl res(primes.size(), 0);
	
	while (min_prime_divs[n] != -1) {
		res[min_prime_divs[n]]++;
		n /= primes[min_prime_divs[n]];
	}
	
	return res;
}

vl primes, min_prime_divs;

void solve() {
	l n, q; scanf("%lld %lld", &n, &q);
	vl xs;
	vl init_n_divs = get_prime_divs_by_min(n, primes, min_prime_divs);
	vl n_divs = init_n_divs;
	
	l n_divs_count = 0;
	for (l p = 0; p < n_divs.size(); p++)
		n_divs_count = n_divs_count * (n_divs[p] + 1) + n_divs[p];
	n_divs_count += 1; l init_n_divs_count = n_divs_count;
	
	for (l i = 0; i < q; i++) {
		l t; scanf("%lld", &t);
		if (t == 2) {
			xs = vl();
			n_divs = init_n_divs;
			n_divs_count = init_n_divs_count;
			continue;
		}
		
		l x; scanf("%lld", &x);
		xs.push_back(x);
		vl x_divs = get_prime_divs_by_min(x, primes, min_prime_divs);
		
		n_divs_count--;
		for (l p = 0; p < n_divs.size(); p++) {
			if (x_divs[p] == 0) continue;
			
			n_divs_count = (n_divs_count - n_divs[p]) / (n_divs[p] + 1) * (n_divs[p] + x_divs[p] + 1) + n_divs[p] + x_divs[p];
			n_divs[p] += x_divs[p];
		}
		n_divs_count++;
		
		l test = n % n_divs_count;
		for (l xx : xs)
			test = (test * xx) % n_divs_count;
		
		if (test == 0) printf("yes\n");
		else printf("no\n");
	}
}

int main() {
	primes = get_primes_with_min_divs(S, min_prime_divs);
	
	l tc; scanf("%lld", &tc);
	while (tc--) {
		solve();
		if (tc) printf("\n");
	}
}

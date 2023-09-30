#include "bits/stdc++.h"

#define S 200005
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

class STree {
private:
	l n, *A, *st;
	
	l left(l p) {
		return p << 1;
	}
	l right(l p) {
		return (p << 1) + 1;
	}
	
	void build(l p, l SL, l SR) {
		if (SL == SR) {
			st[p] = A[SL];
			return;
		}
		
		l l_child = left(p), r_child = right(p);
		build(l_child, SL, (SL + SR) / 2);
		build(r_child, (SL + SR) / 2 + 1, SR);
		
		l p1 = st[l_child], p2 = st[r_child];
		
		st[p] = p1 & p2;
	}
	l land(l p, l SL, l SR, l le, l r) {
		if (r < SL || SR < le) return -1;
		if (le <= SL && SR <= r) return st[p];
		
		l l_child = left(p), r_child = right(p), mid = (SL + SR) / 2,
			p1 = land(l_child, SL, mid, le, r),
			p2 = land(r_child, mid + 1, SR, le, r);
		
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		
		return p1 & p2;
	}
public:
	STree(l *_A, l _n) {
		A = _A;
		n = _n;
		st = new l[n * 4];
		build(1, 1, n);
	}
	
	l land(l le, l r) {
		return land(1, 1, n, le, r);
	}
};

l a[S];

void solve() {
	l n; scanf("%lld", &n);
	
	for (l i = 0; i < n; i++)
		scanf("%lld", &a[i + 1]);
	
	STree mland(a, n);
	
	l q; scanf("%lld", &q);
	while (q--) {
		l lel, k; scanf("%lld %lld", &lel, &k);
		l le = lel, r = n, mid;
		
		if (mland.land(lel, lel) < k) {
			printf("-1");
		} else {
			while (le != r) {
				mid = (le + r + 1) / 2;
				if (mland.land(lel, mid) < k) r = mid - 1;
				else le = mid;
			}
			printf("%lld", le);
		}
		
		if (q) printf(" ");
	}
	printf("\n");
}

int main() {
	l tc; scanf("%lld", &tc);
	while (tc--) solve();
}

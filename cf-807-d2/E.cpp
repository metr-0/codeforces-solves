#include <cstdio>
#include <cstring>

typedef long long ll;

class Bitset {
private:
	ll a[4005];
	int block_size = 50;

	void add(int block_idx, ll v) {
		a[block_idx] += v;
		if (a[block_idx] >= ((ll)1 << block_size)) {
			add(block_idx + 1, a[block_idx] >> block_size);
			a[block_idx] %= (ll)1 << block_size;
		}
	}
	void rem(int block_idx, ll v) {
		if (v > a[block_idx]) {
			rem(block_idx + 1, 1);
			a[block_idx] += (ll)1 << block_size;
		}
		a[block_idx] -= v;
	}
public:
	void add_bit(int idx) {
		int block_idx = idx / block_size,
			pos = idx % block_size;
		add(block_idx, (ll)1 << pos);
	}
	void rem_bit(int idx) {
		int block_idx = idx / block_size,
			pos = idx % block_size;
		rem(block_idx, (ll)1 << pos);
	}
	int get_max_bit_idx() {
		int block_idx = 4005 - 1;
		while (!a[block_idx]) block_idx--;
		
		int msb = -1;
		for (int i = 1; i <= a[block_idx]; i <<= 1)
			msb++;
		
		return block_size * block_idx + msb;
	}
	Bitset(int *nums, int n) {
		memset(a, 0, sizeof a);
		for (int i = 0; i * block_size < n; i++)
			for (int j = 0; j < block_size && i * block_size + j < n; j++)
				add(i, nums[i * block_size + j] << j);
	}
};

int main() {
	int n, q; scanf("%d %d", &n, &q);
	
	int arr[200005], count[200005];
	memset(count, 0, sizeof count);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}
	
	Bitset bs(count + 1, 200004);
	
	for (int i = 0; i < q; i++) {
		int k, l; scanf("%d %d", &k, &l); k--;
		bs.rem_bit(arr[k] - 1);
		arr[k] = l;
		bs.add_bit(l - 1);
		
		printf("%d\n", bs.get_max_bit_idx() + 1);
	}
}

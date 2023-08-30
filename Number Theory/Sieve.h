/**
 * Description: Tests primality up to $SZ$. Runs faster if only
 	* odd indices are stored.
 * Time: O(SZ\log\log SZ) or O(SZ)
 * Source: KACTL 
 * Verification: https://open.kattis.com/problems/primesieve
 */
template<int SZ> struct Sieve {
	bitset<SZ> is_prime;vector<int> primes;
	Sieve() {
		is_prime.set(); is_prime[0] = is_prime[1] = 0;
		for (int i = 4; i < SZ; i += 2) is_prime[i] = 0;
		for (int i = 3; i*i < SZ; i += 2) if (is_prime[i])
				for (int j = i*i; j < SZ; j += i*2) is_prime[j] = 0;
		for(int j = 0 ; j < SZ ; j ++) if (is_prime[j]) primes.push_back(j);
	}
};
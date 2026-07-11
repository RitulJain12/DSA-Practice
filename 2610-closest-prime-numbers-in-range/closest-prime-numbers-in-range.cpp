class Solution {
public:
    vector<int> primes(int N) {

        vector<bool> isPrime(N + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> ans;

        for (int i = 2; i <= N; i++)
            if (isPrime[i])
                ans.push_back(i);

        return ans;
    }

    vector<int> closestPrimes(int left, int right) {

        vector<int> p = primes(right);

        int l = lower_bound(p.begin(), p.end(), left) - p.begin();
        int r = upper_bound(p.begin(), p.end(), right) - p.begin();

        if (r - l < 2)
            return {-1, -1};

        int best = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = l + 1; i < r; i++) {

            if (p[i] - p[i - 1] < best) {

                best = p[i] - p[i - 1];
                ans = {p[i - 1], p[i]};
            }
        }

        return ans;
    }
};
class Solution {
public:
    typedef long long ll;

    ll countSmaller(vector<int>& coins, ll mid) {
        ll count = 0;
        int n = coins.size();

        // Generate all subsets
        for (int expression = 1; expression < (1 << n); expression++) {

            ll lcm = 1;
            int order = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (expression & (1 << i)) {
                    order++;

                    ll g = gcd(lcm, (ll)coins[i]);
                    lcm = lcm / g * coins[i];

                    // Avoid overflow / unnecessary calculation
                    if (lcm > mid) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            if (order % 2 == 1) {
                count += mid / lcm;
            } else {
                count -= mid / lcm;
            }
        }

        return count;
    }

    ll findKthSmallest(vector<int>& coins, int k) {

        ll result = -1;

        ll l = 1;
        ll r = (ll)(*max_element(coins.begin(), coins.end())) * k;

        while (l <= r) {

            ll mid = l + (r - l) / 2;

            if (countSmaller(coins, mid) >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
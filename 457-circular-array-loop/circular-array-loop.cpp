
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = i;

            bool forward = nums[i] > 0;

            while (true) {
                // Slow moves one step
                int nextSlow = (slow + nums[slow] % n + n) % n;

                // Direction must remain the same
                if (nums[nextSlow] * nums[slow] < 0)
                    break;

                // Fast moves one step
                int nextFast = (fast + nums[fast] % n + n) % n;

                if (nums[nextFast] * nums[fast] < 0)
                    break;

                // Fast moves a second step
                int nextFast2 = (nextFast + nums[nextFast] % n + n) % n;

                if (nums[nextFast2] * nums[nextFast] < 0)
                    break;

                slow = nextSlow;
                fast = nextFast2;

                // A cycle is found
                if (slow == fast) {
                    if (slow == (slow + nums[slow] % n + n) % n)
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};

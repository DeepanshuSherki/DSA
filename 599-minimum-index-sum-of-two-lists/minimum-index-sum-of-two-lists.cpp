
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;

        // List1 ke har restaurant ka index map mein store karo
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        vector<string> ans;
        int minSum = INT_MAX;

        // List2 ke restaurants check karo
        for (int j = 0; j < list2.size(); j++) {

            // Agar restaurant List1 mein bhi present hai
            if (mp.find(list2[j]) != mp.end()) {

                // Dono lists ke indices ka sum nikalo
                int sum = mp[list2[j]] + j;

                // Agar naya minimum index sum mila
                if (sum < minSum) {
                    minSum = sum;
                    ans.clear();  // Purane answers hata do
                    ans.push_back(list2[j]);
                }
                // Agar same minimum sum hai, toh dono answers rakho
                else if (sum == minSum) {
                    ans.push_back(list2[j]);
                }
            }
        }

        return ans;
    }
};

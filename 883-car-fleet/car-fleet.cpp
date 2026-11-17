class Solution {
public:
    int carFleet(int target, vector<int>& position,
                 vector<int>& speed) {

        int n = position.size();

        // Position aur speed ko pair mein store karo
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Cars ko destination ke nearest se farthest order mein sort karo
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for (auto car : cars) {

            int pos = car.first;
            int spd = car.second;

            // Destination tak pahunchne ka time calculate karo
            double time = (double)(target - pos) / spd;

            // Agar time previous fleet se zyada hai,
            // toh ek nayi fleet banegi
            if (st.empty() || time > st.top()) {
                st.push(time);
            }

            // Otherwise, current car previous fleet mein merge ho jayegi
        }

        return st.size();
    }
};
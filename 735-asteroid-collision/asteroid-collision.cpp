class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int asteroid : asteroids) {

            bool alive = true;

            // Collision tabhi possible hai jab:
            // Stack ka top positive ho aur current asteroid negative ho
            while (!st.empty() && st.back() > 0 && asteroid < 0) {

                // Stack ka last asteroid current asteroid se chhota hai
                if (st.back() < -asteroid) {
                    st.pop_back();  // Previous asteroid destroy
                }

                // Dono asteroids ka size equal hai
                else if (st.back() == -asteroid) {
                    st.pop_back();  // Previous asteroid destroy
                    alive = false;  // Current asteroid bhi destroy
                    break;
                }

                // Previous asteroid bigger hai
                else {
                    alive = false;  // Current asteroid destroy
                    break;
                }
            }

            // Agar current asteroid survive karta hai
            if (alive) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};
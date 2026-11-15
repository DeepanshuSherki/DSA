class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        stringstream ss(path);
        string dir;

        // Path ko '/' ke basis par split karo
        while (getline(ss, dir, '/')) {

            // Empty directory ya current directory ko ignore karo
            if (dir == "" || dir == ".") {
                continue;
            }

            // Parent directory: previous directory remove karo
            else if (dir == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            // Normal directory ko stack mein add karo
            else {
                st.push(dir);
            }
        }

        // Stack se final canonical path banao
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // Agar stack empty hai toh root directory return karo
        if (ans == "") {
            return "/";
        }

        return ans;
    }
};
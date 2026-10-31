
class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        // Constructor: dono stacks initially empty hain.
    }

    void push(int val) {
        // Normal stack mein value push karo.
        st.push(val);

        // Agar minSt empty hai ya new value current minimum se chhoti/equal hai,
        // toh usko bhi minSt mein push karo.
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        // Jo element remove ho raha hai, agar woh minimum bhi hai,
        // toh minSt se bhi remove karna padega.
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        // Main stack ka top element remove karo.
        st.pop();
    }

    int top() {
        // Main stack ka top element return karo.
        return st.top();
    }

    int getMin() {
        // minSt ke top par current minimum element available hai.
        return minSt.top();
    }
};

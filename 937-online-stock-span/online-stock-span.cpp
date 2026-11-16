class StockSpanner {
public:
    // Price aur uska span store karne ke liye stack
    stack<pair<int, int>> st;

    StockSpanner() {

    }

    int next(int price) {

        // Har naye day ka minimum span 1 hota hai
        int span = 1;

        // Jab tak previous price current price se chhoti ya equal hai
        while (!st.empty() && st.top().first <= price) {

            // Previous days ka span current span mein add karo
            span += st.top().second;

            // Previous price ko remove karo
            st.pop();
        }

        // Current price aur calculated span store karo
        st.push({price, span});

        return span;
    }
};
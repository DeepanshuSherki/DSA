class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int alreadySatisfy = 0;
        int window = 0;
        int maxWindow = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(grumpy[i] == 0){
                alreadySatisfy += customers[i];
            }
            if(i < minutes && grumpy[i] == 1){
                window += customers[i];
            }
        }
        maxWindow = window;
        for(int i = minutes ; i < n ; i++){
            if(grumpy[i] == 1){
                window += customers[i];
            }
            if(grumpy[i - minutes] == 1){
                window -= customers[i - minutes];
            }
            maxWindow = max(maxWindow, window);
        }
        return alreadySatisfy + maxWindow;
    }
};
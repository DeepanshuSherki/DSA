class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int maxSum = 0;

        for(int i = n-k; i < n ; i++){
            sum += cardPoints[i]; 
        }
        maxSum = sum;

        for(int i = 0; i < k ;i++){
                sum -= cardPoints[n-k+i];
                sum += cardPoints[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
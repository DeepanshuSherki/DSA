class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;// size is 1-5 but inde start from 0 to 4 so -1 ,

        while (left < right){
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};
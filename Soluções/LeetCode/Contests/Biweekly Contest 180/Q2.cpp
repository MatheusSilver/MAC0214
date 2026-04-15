class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int counter = 0;
        int curNumber;
        char digitChar = '0' + digit;
        for (int i = 0; i < nums.size(); i++){
            curNumber = nums[i];
            std::string str = std::to_string(curNumber);
            for (int j = 0; j< str.size(); j++){
                counter += (str[j] == digitChar);
            }
        }
        return counter;
    }
};
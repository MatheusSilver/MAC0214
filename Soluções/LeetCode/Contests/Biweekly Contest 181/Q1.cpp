class Solution {
public:
    bool validDigit(int n, int x) {
        string num = to_string(n);
        char digit = '0' + x;
        if (num[0] == digit) return false;
        
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == digit) return true; 
        }
        return false;
    }
};
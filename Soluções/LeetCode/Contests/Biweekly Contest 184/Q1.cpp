class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary = bitset<32>(n).to_string();
        
        bool foundOne = false;
        
        for (int i = 1; i < binary.size(); i++){
            if (binary[i-1] == binary[i] && binary[i] == '1'){
                if (foundOne == true)
                    return false;
                else{
                    foundOne = true;
                }
            }
        }

        return foundOne;
    }
};
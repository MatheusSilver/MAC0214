class Solution {
public:
    // Lembramos do Kenji, esse problema é np e co np.
    bool primo(int x){
        if (x < 2) return false;
        else if (x % 2 == 0) return x == 2;
        else if (x % 3 == 0) return x == 3;
        else if (x % 5 == 0) return x == 5;
        else{
            for (int i = 7; i * i <= x; i+=2){
                if (x%i == 0) return false;
            }
        }
        return true;
    }

    int proxPrimo(int x){
        if (x <= 2) return 2;
        if (x % 2 == 0) x++;
        while (!primo(x)) x+=2;
        return x;
    }
    
    int minOperations(vector<int>& nums) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if (i%2 == 0){
                int curNumber = proxPrimo(x);
                counter += curNumber - x;
            }else if(primo(x)){
                counter += 1;
                counter += (x == 2);
            }
        }
        return counter;
    }
};
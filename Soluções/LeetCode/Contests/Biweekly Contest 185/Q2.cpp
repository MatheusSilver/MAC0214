class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> pos(n, 0);

        for (int j = 0; j < n; j++){
            if (lights[j] == 0) continue;
            
            int left = max(0, j - lights[j]);
            int right = min(n - 1, j + lights[j]);
            
            pos[left] = max(pos[left], right + 1);
        }

        int numBulbs = 0;
        int curPos = 0;
        int greedy = 0;
        while (curPos < n){
            greedy = max(greedy, pos[curPos]);
            
            if (curPos >= greedy) {
                numBulbs++;
                greedy = curPos + 3;
            }

            curPos++;
        }

        return numBulbs;
    }
};
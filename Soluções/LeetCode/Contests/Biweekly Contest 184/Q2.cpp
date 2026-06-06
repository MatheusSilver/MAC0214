class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long onTime = 0;

        sort(intervals.begin(), intervals.end());

        long long l0 = intervals[0][0];
        long long r0 = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++){
            long long l1 = intervals[i][0];
            long long r1 = intervals[i][1];

            if (l1 <= r0+1){
                r0 = max(r0, r1);
            }else{
                onTime += r0 -l0 +1;
                l0 = l1;
                r0 = r1;
            }
        }

        onTime += r0-l0+1;

        return (brightness + 2) / 3 * onTime;
    }
};
class Solution {
public:
    static bool cmp(pair<int, int>& x, pair<int, int>& y) {
        int nx = (x.second ? (x.first == 0 ? 2 : 1) : 0);
        int ny = (y.second ? (y.first == 0 ? 2 : 1) : 0);

        if (nx != ny) return nx < ny;
        else if (nx == 1){
          if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        }  
        return false;
    }


    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const long long MOD = 1e9+7;
        int miniCounter = 0;
        vector<pair<int,int>> v(nums1.size());

        for (int i = 0; i < nums1.size(); i++) v[i]={nums1[i],nums0[i]}, miniCounter += nums1[i]+nums0[i];

        sort(v.begin(), v.end(), cmp);

        vector<long long> p(++miniCounter, 1);
        for (int i = 1; i<miniCounter; i++) p[i] = (p[i-1]*2)%MOD;

        long long max = 0;
        for (auto [a,b] : v) max = (max*p[a+b] + (p[a]-1+MOD)%MOD * p[b])%MOD;
        return max;
        
    }
};
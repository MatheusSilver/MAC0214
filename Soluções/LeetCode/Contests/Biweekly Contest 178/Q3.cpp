class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        unordered_map<int,int> freq;
        long long diff = 0;

        for (int i = 0; i < nums1.size(); i++) freq[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) freq[nums2[i]]--;
        for (auto &numbers : freq) if (abs(numbers.second) %2 == 1) return -1;
        for (auto &numbers : freq) diff += numbers.second > 0 ? numbers.second : 0;
        return diff / 2;
    }
};
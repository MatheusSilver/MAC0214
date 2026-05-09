class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;

        for (const string&event : events) {
            if (counter != 10) {
                if (event == "W"){
                    counter ++;
                }else if (event == "WD" || event == "NB"){
                    score++;
                }else{
                    score += event[0] - '0';
                }
            }
        }

        return {score, counter};

    }
};
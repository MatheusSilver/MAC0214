class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        for (int i = 0; i < m; i++){
            string toappend;
            
            for (int j = 0; j < n; j++){
                if (i == m-1 || j == 0){
                    toappend += '.';
                }else{
                    toappend += '#';
                }
            }
            grid[i] = toappend;
        }
        return grid;
    }
};
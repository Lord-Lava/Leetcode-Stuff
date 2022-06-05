class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>v;
        for(int i =0;i<n;i++){
            vector<int>p(i+1,0);
            v.push_back(p);
        }
        
        for(int i =0;i<n;i++){
            for(int j =0;j<v[i].size();j++){
                if(j==0 || j==(int)v[i].size()-1){
                    v[i][j] = 1;
                }
            }
        }
        
        
        for(int i =0;i<n;i++){
            for(int j =0;j<v[i].size();j++){
                if(v[i][j] == 0){
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
                }
            }
        }
        return v;
    }
};
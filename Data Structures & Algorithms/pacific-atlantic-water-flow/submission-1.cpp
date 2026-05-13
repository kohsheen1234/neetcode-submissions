class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c){
        int m = heights.size();
        int n = heights[0].size();
        visited[r][c]=true;

        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};

        for(int i = 0 ;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<0 || nc>=n || nr>=m|| nc<0){
                continue;
            }

            if(visited[nr][nc]){
                continue;
            }

            if(heights[nr][nc]<heights[r][c]){
                continue;
            }
            dfs(heights, visited, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int r = 0;r<m ;r++){
            dfs(heights, pacific,r,0);
            dfs(heights, atlantic,r,n-1);
        }

        for(int c = 0;c<n ;c++){
            dfs(heights, pacific,0,c);
            dfs(heights, atlantic,m-1,c);
        }

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;


    }
};

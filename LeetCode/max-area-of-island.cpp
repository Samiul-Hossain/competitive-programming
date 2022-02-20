int dfs(int** grid, int a, int b, int r, int c){
    int sum = 1;
    int X[] = {0,0,-1,1};
    int Y[] = {1,-1,0,0};
    if(a<0||b<0||a>=r||b>=c||grid[a][b]!=1)
        return 0;
    grid[a][b] = 0;
    for(int i=0; i<4; i++){
        sum += dfs(grid, a+X[i],b+Y[i],r,c);
    }
    return sum;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int r = gridSize;
    int c = *gridColSize;
    int ans = 0;
    int sum = 0, temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == 1){
                sum = dfs(grid, i, j, r, c);
                if(sum>ans)
                    ans = sum;
            }
        }
    }
    return ans;
}
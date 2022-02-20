int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    int m = gridSize;
    int n = *gridColSize;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='1'){
                count++;
                DFS(i,j,grid,m,n);
            }
        }
    }
    return count;
}
void DFS(int a, int b, char** grid, int m, int n){
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    if(a<0 || b<0 || a>=m || b>=n ||grid[a][b]!= '1' )
    {
        return;
    }
    
    grid[a][b] = '0';
    for(int i=0; i<4; i++){
        DFS(a+X[i],b+Y[i],grid,m,n);
    }
}
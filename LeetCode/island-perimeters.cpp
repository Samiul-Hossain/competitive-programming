int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int X[] = {0,0,-1,1};
    int Y[] = {1,-1,0,0};
    int r = gridSize;
    int c = *gridColSize;
    int sum = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j]==1){
                for(int k=0;k<4; k++){
                    if(i+X[k]<0||j+Y[k]<0||i+X[k]>=r||j+Y[k]>=c||grid[i+X[k]][j+Y[k]]==0){
                        sum++;
                    }
                }
            }
        }
    }
    return sum;
}
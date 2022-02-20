int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
 
    *returnSize = imageSize; 

    
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize); 
    for(int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = imageColSize[0];
    }
    
   
    if(newColor == image[sr][sc]) 
        return image; 
    
    recursive(image, imageSize, imageColSize, sr, sc, newColor, image[sr][sc]);

    return image;
   
}

void recursive(int** image, int imageSize, int* imageColSize, 
                     int x, int y, int newColor, int originalColor){
    if(x >= 0 && x < imageSize && y >= 0 && y < imageColSize[x] && image[x][y] == originalColor){
        image[x][y] = newColor; 
        recursive(image, imageSize, imageColSize, x - 1, y, newColor, originalColor); 
        recursive(image, imageSize, imageColSize, x + 1, y, newColor, originalColor); 
        recursive(image, imageSize, imageColSize, x, y + 1, newColor, originalColor); 
        recursive(image, imageSize, imageColSize, x, y - 1, newColor, originalColor); 
    }
}

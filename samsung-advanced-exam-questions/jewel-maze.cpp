#include <iostream>
using namespace std;
int maze[50][50], answer[50][50];
int n, value;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y){
    return ( (maze[x][y] == 0 || maze[x][y] == 2) && x>=0 && x<n && y>=0 && y<n );
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
}

void getJewel(int row, int col, int diamond){
    if(row == n-1 && col == n-1){
        if(diamond > value){
            value = diamond;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    answer[i][j] = maze[i][j];
                }
            }
        }
    }
    for(int i=0; i<4; i++){
        int x = row + dx[i];
        int y = col + dy[i];
        int check;
        if(isValid(x, y)){
            if(maze[x][y] == 2)
                check = 1;
            else check = 0;
            maze[x][y] = 3;
            getJewel(x, y, diamond+check);
            if(check==1)
                maze[x][y] = 2;
            else maze[x][y] = 0;
        }
    }
}

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> maze[i][j];
            }
        }
        value = -100;
        maze[0][0] = 3;
        getJewel(0, 0, 0);
        print();
        cout << value << endl;
        
    }
    
}
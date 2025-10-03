#include <iostream>
using namespace std;

int board[20][20];
int N,solutionCount=0;

bool isSafe(int row,int col){
    for(int i=0;i<col;i++)
        if(board[row][i]) return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]) return false;
    for(int i=row,j=col;i<N&&j>=0;i++,j--)
        if(board[i][j]) return false;
    return true;
}

bool solveNQUtil(int col,bool printOne){
    if(col>=N){
        solutionCount++;
        if(printOne){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)
                    cout<<(board[i][j]?'Q':'.')<<" ";
                cout<<endl;
            }
            cout<<endl;
        }
        return true;
    }
    bool res=false;
    for(int i=0;i<N;i++){
        if(isSafe(i,col)){
            board[i][col]=1;
            res=solveNQUtil(col+1,printOne)||res;
            board[i][col]=0;
        }
    }
    return res;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=0;
    solveNQUtil(0,true);
    cout<<"Total Solutions: "<<solutionCount;
    return 0;
}

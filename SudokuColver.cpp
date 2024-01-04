#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 map<pair<int,char>,int>Row,Col;
 map<pair<pair<int,int>,char>,int>Grid;


bool isPresent(int r,int c,char p)
{
    if(Row[{r,p}]==1) return true;
    if(Col[{c,p}]==1) return true;
    if(Grid[{{r/3,c/3},p}]==1) return true;
    return false;
}


bool Solve(vector<vector<char>>&board,int row,int col,queue<pair<int,int>>Q)
{
    int nr,nc;
    nr=nc=-1;
    if(!Q.empty()){
         nr=Q.front().first;
        nc=Q.front().second;
        Q.pop();
    }
    for(int i=1;i<10;i++)
    {
        if(!isPresent(row,col,(char)(48+i)))
        {board[row][col]=(char)(48+i);
        if(nr==-1 && nc==-1) return true;
          Row[{row,(char)(48+i)}]=1;
          Col[{col,(char)(48+i)}]=1;
          Grid[{{row/3,col/3},(char)(48+i)}]=1;
          if(Solve(board,nr,nc,Q)) return true;
          Row.erase({row,(char)(48+i)});
          Col.erase({col,(char)(48+i)});
          Grid.erase({{row/3,col/3},(char)(48+i)});
        }
    }
   
return false;
}

    void solveSudoku(vector<vector<char>>& board) {
       queue<pair<int,int>>Q;
        int i=0;
        while(i<board.size())
        {
            int col=0;
            while(col<board[i].size())
            {
              if(board[i][col]!='.') Row[{i,board[i][col]}]=1;
              col++;
            }
            i++;
        }
        i=0;
        while(i<board[0].size())
         {
             int row=0;
             while(row<board.size())
             {
                 
              if(board[row][i]!='.') Col[{i,board[row][i]}]=1;
              row++;
             }
             i++;
         }
         for(int i=0;i<board.size();i++)
         {
             for(int j=0;j<board[i].size();j++)
             {
               if(board[i][j]!='.')
               {
                   Grid[{{i/3,j/3},board[i][j]}]=1;
               }
               else Q.push({i,j});
             }
         }
      
      if(!Q.empty()) {
          int i=Q.front().first;
          int j=Q.front().second;
          Q.pop();
          Solve(board,i,j,Q);
      }


    }
};

int main()
{
    cout<<"Write Positons and number else write -1 to stop"<<endl;
    vector<vector<char>>Board(9,vector<char>(9,'.'));
    while(true)
    {
        int i,j;
         char val;
        cin>>i>>j>>val;
        if(i==-1 || j==-1 || val==-1) break;
        if(i>=9 || j>=9 || i<0 || j<0 || (val-48)>=10 || (val-48)<=0) {
            cout<<"Program terminated dur to wrong input"<<endl;
            cout<<i<<" "<<j<<" "<< val<<endl;
            return 0;
        }
        Board[i][j]=val;
    }
    cout<<"Your Initial configrations is "<<endl;
    for(auto p:Board)
    {
       for(auto k:p) cout<<" "<<k;
       cout<<endl;
    }
    cout<<endl<<endl;
    Solution obj;
    obj.solveSudoku(Board);
    cout<<"Your Final configrations is "<<endl;
    for(auto p:Board)
    {
       for(auto k:p) cout<<" "<<k;
       cout<<endl;
    }

}
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
double t[101][101];
double solve(int p, int i, int j){

    if(i < 0 || j < 0 || i < j)
        return 0.0;

    if( i == 0 && j == 0 )  //reched the top glass  
        return p;

    if(t[i][j] != -1)
        return t[i][j];

    double left_up  = (solve(p, i-1, j-1) - 1) / 2.0;
    double right_up = (solve(p, i-1, j) - 1) / 2.0;
    
    if(left_up < 0)
        left_up = 0;
    if(right_up < 0)
        right_up = 0;

    return t[i][j] = right_up + left_up;
}

double champagneTower(int poured, int query_row, int query_glass) {
    
    for(int i = 0 ; i < 101 ; i++)
        for(int j = 0 ; j < 101 ; j++)
            t[i][j] = -1;

    return min(solve(poured,query_row,query_glass), 1.0);
}
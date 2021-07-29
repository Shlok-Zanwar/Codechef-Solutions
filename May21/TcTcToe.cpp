#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll getMatched(char board[][3]){
    ll ans = 0, i, j;
    bool xDone = false, oDone = false;
    // rows
    for(i = 0; i < 3; i ++){
        for(j = 1; j < 3; j ++){
            if(board[i][j] != board[i][j-1] || board[i][j] == '_'){
                break;
            }
        }
        if(j == 3){
            if(board[i][0] == 'X'){
                xDone = true;
            }
            else{
                oDone = true;
            }
            // ans ++;
        }
    }

// cout << "----------------\n";
// cout << ans << "\n";

    for(i = 0; i < 3; i ++){
        for(j = 1; j < 3; j ++){
            if(board[j][i] != board[j -1][i] || board[j][i] == '_'){
                break;
            }
        }
        if(j == 3){
            if(board[0][i] == 'X'){
                xDone = true;
            }
            else{
                oDone = true;
            }
            // ans ++;
        }
    }
// cout << ans << "\n";
    for(i = 1; i < 3; i ++){
        if(board[i][i] != board[i-1][i-1] || board[i][i] == '_'){
            break;
        }
    }
    if(i == 3){
        if(board[0][0] == 'X'){
            xDone = true;
        }
        else{
            oDone = true;
        }
        // ans ++;
    }
// cout << ans << "\n";
    for(i = 1; i >= 0; i --){
        if(board[2-i][i] != board[1-i][i + 1] || board[2-i][i] == '_' ){
            break;
        }
    }
    if(i == -1){
        if(board[0][2] == 'X'){
            xDone = true;
        }
        else{
            oDone = true;
        }
        // ans ++;
    }
// cout << ans << "\n";
    if(xDone && oDone){
        return 5;
    }
    
    if(!xDone && !oDone){
        return 0;
    }

    if(xDone){
        return 1;
    }

    if(oDone){
        return -1;
    }
    return ans;
}


ll tictactoe(char board[][3], ll x, ll o){
    if(x-o > 1 || o > x){
        return 3;
    }

    ll matched = getMatched(board);
    // cout << matched << "\n";
    if(x + o == 9){
        if(matched == -1){
            return 3;
        }
        if(matched <= 1){
            return 1;
        }
        else{
            return 3;
        }
    }

    if(matched > 1){
        return 3;
    }

    if(matched == 0){
        return 2;
    }

    if(matched == 1){
        if(x > o){
            return 1;
        }
        else{
            return 3;
        }
    }

    if(matched == -1){
        if(x == o){
            return 1;
        }
        else{
            return 3;
        }
    }

    return 0;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll cases, i, j, len, x, o;
    char board[3][3];

    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        x = 0;
        o = 0;
        for(i = 0; i < 3; i ++){
            for(j = 0; j < 3; j ++){
                cin >> board[i][j];
                if(board[i][j] == 'X'){
                    x ++;
                }
                else if(board[i][j] == 'O'){
                    o ++;
                }
            }
        }

        cout << tictactoe(board, x, o) << "\n";


    }

}
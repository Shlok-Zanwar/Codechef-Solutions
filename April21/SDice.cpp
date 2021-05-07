// https://www.codechef.com/APRIL21B/problems/SDICE

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long cases, dice, ans;
    cin >> cases;

    while (cases --){
        cin >> dice;
        long long arr[6] = {0};
        if(dice > 7){
            arr[2] += ((dice/4)-1)*4;
            dice = dice - ((dice/4)-1)*4;
        }
        
        if (dice == 1){
            // arr[2] += 0;
            // arr[3] += 0;
            // arr[4] += 0;1
            arr[5] += 1;
        }
        else if (dice == 2){
            // arr[2] += 0;
            // arr[3] += 0;
            arr[4] += 2;
            // arr[5] += 0;
        }
        else if (dice == 3){
            // arr[2] += 0;
            arr[3] += 1;
            arr[4] += 2;
            // arr[5] += 0;
        }
        else if (dice == 4){
            // arr[2] += 0;
            arr[3] += 4;
            // arr[4] += 0;
            // arr[5] += 0;
        }
        else if (dice == 5){
            arr[2] += 1;
            arr[3] += 3;
            // arr[4] += 0;
            arr[5] += 1;
        }
        else if (dice == 6){
            arr[2] += 2;
            arr[3] += 2;
            arr[4] += 2;
            // arr[5] += 0;
        }
        else if (dice == 7){
            arr[2] += 3;
            arr[3] += 2;
            arr[4] += 2;
            // arr[5] += 0;
        }

        ans = 11*arr[2] + 15*arr[3] + 18*arr[4] + 20*arr[5];
        cout << ans << endl;
    }

}




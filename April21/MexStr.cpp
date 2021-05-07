#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll minimum(ll a, ll b){
    return a >= b ? b : a;
}


void findMex(string str){
    ll i, prev1, prev0;
    ll nextNum[str.length()][2];
    ll lenAfter[str.length()][2];
    string ans;

    prev1 = -1;
    prev0 = -1;
    for(i = str.length() - 1; i >= 0; i -- ){
        nextNum[i][0] = prev0;
        nextNum[i][1] = prev1;

        if(prev1 == -1){
            lenAfter[i][1] = 1;
        }
        else{
            lenAfter[i][1] = 1 + minimum(lenAfter[prev1][0], lenAfter[prev1][1]);
        }

        if(prev0 == -1){
            lenAfter[i][0] = 1;
        }
        else{
            lenAfter[i][0] = 1 + minimum(lenAfter[prev0][0], lenAfter[prev0][1]);
        }


        if(str[i] == '1'){
            prev1 = i;
        }
        else{
            prev0 = i;
        }
    }
    
    if(prev0 == -1){
        cout << "0\n";
    }
    else if(prev1 == -1){
        cout << "1\n";
    }
    else{
        ans = "1";
        i = prev1;
        while(i != str.length()){
            if(lenAfter[i][0] <= lenAfter[i][1]){
                ans += "0";
                if(lenAfter[i][0] == 1){
                    break;
                }
                i = nextNum[i][0];
            }
            else{
                ans += "1";
                if(lenAfter[i][1] == 1){
                    break;
                }
                i = nextNum[i][1];
            }
        }
        cout << ans << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases, i, j,prev1, prev0, cnt1s;
    cin >> cases;
    string str;

    while (cases --){
        cin >> str;
        findMex(str);
    }
}


        // for(i = 0; i < str.length(); i ++){
        //     cout << nextNum[i][0] << " " << nextNum[i][1] << endl;
        // }
        // cout << endl;


        // for(i = 0; i < str.length(); i ++){
        //     cout << lenAfter[i][0] << " " << lenAfter[i][1] << endl;
        // }
        // cout << endl;
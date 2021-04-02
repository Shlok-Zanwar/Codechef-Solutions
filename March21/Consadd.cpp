// https://www.codechef.com/MARCH21C/problems/CONSADD

#include <bits/stdc++.h>
using namespace std;

int main() {
    long noOfCases, rows, columns, x, i, j, k, myValue, temp;
    cin >> noOfCases;
    bool errFound;
    
    while(noOfCases --){
        cin >> rows >> columns >> x;
        long a[rows][columns], ab[rows][columns];
        errFound = false;

        for(i = 0; i < rows; i++){
            for(j = 0; j < columns; j++){
                cin >> a[i][j];
            }
        }

        for(i = 0; i < rows; i++){
            for(j = 0; j < columns; j++){
                cin >> temp;
                ab[i][j] = a[i][j] - temp;
            }
        }

        for(i = 0; i < rows; i++){
            for(j = 0; j < columns; j++){
                myValue = ab[i][j];
                if(myValue == 0){
                    continue;
                }

                if(j + x <= columns){
                    ab[i][j] = 0;
                    for(k = j + 1; k < j + x; k++){
                        ab[i][k] = ab[i][k] - myValue;
                    }
                }
                else if(i + x <= rows){
                    ab[i][j] = 0;
                    for(k = i + 1; k < i + x; k++){
                        ab[k][j] = ab[k][j] - myValue;
                    }
                }
                else{
                    if(ab[i][j] != 0){
                        cout << "No\n";
                        errFound = true;
                        break;
                    }
                }
            }
            if(errFound){
                break;
            }
        }

        if(!errFound){
            cout << "Yes\n";
        }
    }
}
#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long cases, noOfK, rows, cols, mySize, limitJ, limitI, k, i, j, sum, mySizeSq;
    std::cin >> cases;

    while (cases --){
        std::cin >> rows >> cols >> k;
        long long arr[rows][cols];
        long long aux[rows][cols]; 
        noOfK = 0;

        for(i = 0; i < rows; i ++){
            for(j = 0; j < cols; j ++){
                std::cin >> arr[i][j];
                if(arr[i][j] >= k){
                    noOfK ++;
                }
            }
        }

        // Making auxillary matrix
        for(j = 0; j < cols; j ++){
            aux[0][j] = arr[0][j];
        }
        for(i = 1; i < rows; i ++){
            for(j = 0; j < cols; j ++){
                aux[i][j] = arr[i][j] + aux[i-1][j];
            }
        }
        for(i = 0; i < rows; i ++){
            for(j = 1; j < cols; j ++){
                aux[i][j] += aux[i][j-1];
            }
        }


        for(mySize = 2; mySize <= rows; mySize ++){
            limitJ = cols - mySize + 1;
            limitI = rows - mySize + 1;
            mySizeSq = mySize*mySize;

            for(i = 0; i < limitI; i ++){
                for(j = limitJ - 1; j >= 0; j --){

                    sum = aux[i + mySize - 1][j + mySize - 1];
                    if (i > 0){
                        sum = sum - aux[i - 1][j + mySize - 1];
                    }
                    if (j > 0){
                        sum = sum - aux[i + mySize - 1][j - 1];
                    }
                    if (i > 0 && j > 0){
                        sum = sum + aux[i - 1][j - 1];
                    }

                    // std::cout << "checking " << i << " " << j << " " << mySize << " avg " << sum << " " << noOfK <<"\n";
                    if(sum/(mySizeSq) >= k){
                        noOfK += ((limitJ - j)*(limitI-i));
                        limitJ = j;
                    }
                    else{
                        break;
                    }
                }
                if(limitJ == 0){
                    break;
                }
            }
        }
        std::cout << noOfK << "\n";
    }
}

// 1
// 3 4 4

// 2 2 3 
// 3 4 5 
// 4 5 5 
// 4 5 5 
// 4 5 5 
// 4 5 5 
// https://www.codechef.com/MARCH21C/problems/PAPARAZI

#include <bits/stdc++.h>
using namespace std;


struct myStruct {
    long height;
    long iSee;
    double slopeWithISee;
};


int main() {
    long noOfCases;
    cin >> noOfCases;
    long len, i, j, iSee, myMax;
    double slope, slopeWithISee;

    while(noOfCases --){
       cin >> len;
       myStruct arr[len + 1];
       myMax = 1;

       for(i = 1; i < len + 1; i ++){
           cin >> arr[i].height;
       }

       arr[1].iSee = 1;
       arr[1].slopeWithISee = DBL_MAX;

       for(i = 2; i < len + 1; i++){
            iSee = i - 1;

            while(iSee != 1){
                slopeWithISee = double( (arr[i].height - arr[arr[iSee].iSee].height) / double(i - arr[iSee].iSee) );

                if(slopeWithISee >= arr[iSee].slopeWithISee){
                    iSee = arr[iSee].iSee;
                }
                else{
                    break;
                }

            }

            arr[i].iSee = iSee;
            arr[i].slopeWithISee = ((arr[i].height - arr[iSee].height) / double(i - iSee));

            myMax = max(myMax, (i-iSee));

        }

        cout << myMax << "\n";

    }
}
#include <iostream>
using namespace std;

int main(){

    int n;
    int a[n][n];
    cin>>n;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            cin>>a[i][j];
        }
    }

    //Transpose
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            int temp = 0;
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

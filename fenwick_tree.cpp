/*
     ContestName     =   Shinchu_itachi
   " Walking on the road not taken with my own gutts.. "
*/


#include <bits/stdc++.h>
using namespace std ;

int n ;
vector<int> arr  , bit ( N );

void update( int i , int val , int prevalue ) {
        for (  i ; i <= n ;  i = i + ( i & -i))
                bit[i] += ( val - prevalue);
}

int sum ( int i ) {
        // sum functions return sum till the ith index
        int s = 0 ;

        for (  i ; i > 0 ; i = i - ( i & -i))
                s += bit[i];

        return s;
}

void solve() {
        // implementing the fenwick tree here , it is helpful in find the range sum query problem a
        // also findding the answer for array count inversinon

        // so there are two basic operation in fenwick tree
        // one is to find the sum
        // another is to update the tree

        // so basically we first create an fenwick or BIT

        // one more thing , i & -i helps in getting the righmost set bit in i
        // example : -         i  ===  1101100
        // rightmsot bit   ->              -

        // so -i gives two's complement of the number i
        // so                 -i  ===  0010100

        // so when we do     i  ==== 1101100
        // so             & -i  ==== 0010100
        //                           --------
        //                           0000100

        // so we got the rightmost set bit
        // now when we do i - ( i & -i) we got == a number which rightmost set bit have been removed and its previou to i

        int q;
        cin >> n >> q;

        arr.resize(n , 0 );

        for ( auto &i : arr) cin >> i ;

        // now we have to create a fenwick tree
        // basically we create a fenwick tree only with 1 based index
        // now zero as while removing the last set index from a number can lead to infinite loop
        // here by update we will update the value with the new value

        for ( int i = 0 ; i < n ; i ++) {
                update( i + 1 , arr.at(i) , 0);
        }

        // so above we have created the BIT

        // now computing the sum for the type queries
        for ( int i = 0 ; i < q ; i++) {
                int ch , l , r ;  cin >> ch >> l >> r;

                // since the index will be zero based and our bit tree is 1 based so we will update the value of l and r

                if ( ch == 1 ) {
                        // since we have to update the bit with new values we will send the old value to
                        // so that we can update the new value by  preval + ( updateval - preval )
                        update ( l + 1 , r  , arr[l]);

                        // remember one thing afte update you have to update the array value to for the further update
                        arr[l] = r ;
                }

                if ( ch == 2) {
                        cout << sum (r + 1) - sum ( l ) << endl;
                }


        }
        working
}



inline void testcases() {
        int test = 1, testcase = 1 ;
        //cin >> test ;

        cout << setprecision(12) ;
        cerr << setprecision(8) ;
        while (test --) {
                // cout << "Case #" << testcase++ << ": ";
                solve () ;
        }
}





int main () {
        fastio();

#ifndef ONLINE_JUDGE
        // freopen("output.txt", "w", stdout);
        // freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
#endif

        auto start = high_resolution_clock::now();

        testcases();

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cerr << "Time : " << duration.count() / 1000 ;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void display(vector<int> a, long long & n, long long &sum) {
    n++;
    for (long unsigned int i = 0; i < a.size(); i++)
    {cout << a[i] << " "; sum += a[i];}
    cout << endl;
}

int main() {
    long n;
    cin >> n;
    vector<int> a;
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    reverse(a.begin(), a.end());
    set<vector<int>> st;
    long long count = 0, sum = 0;
    do {
        display(a, count, sum);
    } while (next_permutation(a.begin(), a.end()));
    cout << count << " " << sum << "\n";
    return 0;
}

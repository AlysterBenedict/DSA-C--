#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }
        
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans = ans * x;
            }
            x = x * x;
            nn = nn / 2;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    double x1 = 2.0;
    int n1 = 10;
    cout << "pow(2.0, 10) = " << sol.myPow(x1, n1) << endl; // Output: 1024

    double x2 = 2.1;
    int n2 = 3;
    cout << "pow(2.1, 3) = " << sol.myPow(x2, n2) << endl; // Output: 9.261

    double x3 = 2.0;
    int n3 = -2;
    cout << "pow(2.0, -2) = " << sol.myPow(x3, n3) << endl; // Output: 0.25

    double x4 = 1.0;
    int n4 = -2147483648; // Testing INT_MIN
    cout << "pow(1.0, INT_MIN) = " << sol.myPow(x4, n4) << endl; // Output: 1

    return 0;
}
#include<iostream>
using namespace std;

double powern(double x, int n)
{
    long binaryform = n; // Store n in a variable to manipulate its bits
    double ans = 1;      // Initialize result

    // Binary exponentiation: loop runs O(log n) times         [  n=log2(n)+1   ] 1000= 10 bits , 11 iterations
    // because each right shift removes one bit from binaryform
    while (binaryform > 0)
    {
        // If the least significant bit is 1, multiply ans by current x
        if (binaryform & 1)
        {
            ans *= x;
        }

        x *= x;                // Square the base for the next bit
        binaryform >>= 1;      // Move to the next bit (right shift)
    }

    return ans; // Final result: x^n
}


int main()
{
    int n;
    double x;
    cout<<"Enter the power : ";
    cin>>n;
    cout<<"enter the base :";
    cin>>x;
    double result=powern(x,n); //function call
    cout<<x<<" raised to the power "<<n<<" is : "<<result<<endl; //output the result
}


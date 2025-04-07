#include<iostream>
using namespace std;

double powern(double x, int n)
{
    long binaryform = n; // Store n in a variable to manipulate its bits
    double ans = 1;      // Initialize result

    // Binary exponentiation: loop runs O(log n) times         [  n=log2(n)+1   ] 1000= 10 bits , 11 iterations
    // because each right shift removes one bit from binaryform

    if(binaryform<0)
    {
        binaryform=-binaryform;
        x=1/x; // If n is negative, take the reciprocal of x
    // This is equivalent to x^(-n) = 1/(x^n)
    }
if(n==0)
return 1.0;
if(x==0)
return 0.0;
if(x==1)
return 1.0;;
if(n==1)
return x;

if(x==-1 && n&2==0)
return 1.0;
if(x==-1 && n&2==1)
return -1.0;

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


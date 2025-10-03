#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars)
{
    int n=chars.size();
    int read=0;
    int write=0;
    
    if(n== 0 || n==1)
    return n;

    while(read<n)
    {
        int j=read+1;

        while(j<n && chars[j]==chars[read])
        {
            j++;
        }
        chars[write++]=chars[read];
        int count= j-read;

        if(count>1)
        {
            string count_str= to_string(count);
            for(char c : count_str)
            chars[write++]=c;
        }

        read=j;
    }return write;
}

int main()
{
    vector<char> chars;
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    chars.resize(n);
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
    cin>>chars[i];
    int compressed_length=compress(chars);
    cout<<"The number of elements is : "<<compressed_length<<endl;

    cout<<"The compressed array is : ";
    for(int x=0;x<compressed_length;x++)
    cout<<chars[x]<<" ";
}


int main()
{
    int n,m;
    cout<<"Enter the number of books : ";
    cin>>n;
    cout<<"Enter the number of students : ";
    cin>>m;
    vector<int> arr(n);
    cout<<"Enter the number of pages in each book :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int ans = allocateBooks(arr,n,m);
    cout<<"the minimum number of maximum pages which can be aloocated to a student is : " <<ans<<endl;
    return 0;
}
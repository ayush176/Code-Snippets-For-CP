#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    //Block size 
    int BLK = sqrt(n);

    //Size of ans by blocks
    int m = (n+BLK-1)/BLK;
    vector<int> ans(m);

    for(int i=0;i<n;)
    {
        int j=0;
        int te = INT_MAX;
        while(i<n && j<BLK)
        {
            te = min(te,v[i]);
            i++;j++;
        }
        ans[(i-1)/BLK] = te;
    }
    int q;
    cin>>q;

    //Answering the query
    
    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int lb = l/BLK;
        int rb = r/BLK;

        int temp = INT_MAX;

        if(lb==rb)
        {
            for(int i=l;i<=r;i++)
            {
                temp = min(v[i],temp);
            }
        }
        else
        {
            for(int i=l;i<(lb+1)*BLK;i++)
            {
                temp = min(v[i],temp);
            }

            for(int i=lb+1;i<rb;i++)
            {
                temp = min(ans[i],temp);
            }

            for(int i=rb*BLK;i<=r;i++)
            {
                temp = min(v[i],temp);
            }
        }
        
        cout<<temp<<"\n";
    }
    return 0;
}

#include<vector>
#include<queue>
#include <iostream>
using namespace std;


    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>,greater<long long> > priority;
        
        for(int i=0;i<n;i++)
        {
            priority.push(arr[i]);
        }
        
        long long cost=0;

        while(priority.size()>1)
        {
          // extract 1st and 2nd smallest lengths from min-heap
            long long a=priority.top();
            priority.pop();
            long long b=priority.top();
            priority.pop();
            
            cost+=a+b;
            
            if(priority.size()==0)
            {
                return cost;
            }
         
            priority.push(a+b);
        }
        
        return 0;
    }

    int main()
    {
     long long arr[]={4,3,2,6};
     long long n=4;
     cout<<"minimum cost for connecting the ropes = "<<minCost(arr,4);
            return 0;
    }


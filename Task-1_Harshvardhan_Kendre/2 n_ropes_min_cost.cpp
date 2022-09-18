#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int findMinCost(vector<int> const &prices)
{
    priority_queue<int, vector<int>, greater<int> > pq;
 
    int cost = 0;

     for (int i = 0; i < prices.size(); i++) {
        pq.push(prices[i]);
    }
 
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
 
        int y = pq.top();
        pq.pop();
 
        int sum = x + y;
 
        pq.push(sum);
 
        cost += sum;
    }
 
    return cost;
}
 
int main()
{
    vector<int> prices = { 5, 4, 2, 8 };
    cout << "The minimum cost is " << findMinCost(prices);
 
    return 0;
}

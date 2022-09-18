#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findMinimumCost(int arr[], int n) {
   priority_queue< int, vector<int>, greater<int>queue(arr, arr+n);
   int minCost = 0;
     while (queue.size() > 1) {              
      int item1 = queue.top();            
      queue.pop();
      int item2 = queue.top();          
      queue.pop();
      minCost += item1 + item2;         
      queue.push(item1 + item2);
   }
   return minCost;
}
int main() {
   int ropeLength[] = {4, 3, 2, 6, 5, 7, 12};
   int n = 7;
   cout << "Total minimum cost: " << findMinimumCost(ropeLength, n);
}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<queue>
using namespace std;

long double minimizeMaxDis(vector<int> dist,int k){

    /*
    This solution has the time complexity of O(n*k+n)
    */
    int n = dist.size();
    vector<int> howmany(n);
    
    for(int i=0;i<k;i++){

        long double maxvalue = -1;
        int maxindex = -1;
        for(int j=0;j<dist.size()-1;j++){
            long double diff = dist[j+1]-dist[j];
            int sectionlength = diff/(long double)(howmany[j]+1);
            if(maxvalue < sectionlength) {
                maxvalue = sectionlength;
                maxindex = j;
            }
        }
        howmany[maxindex]++;
    }
    
    long double maxAns = -1;
    for(int i=0;i<n-1;i++){
         long double diff = (dist[i+1]-dist[i]);
         long double sectionlength = diff/(long double)(howmany[i]+1);
         maxAns = max(maxAns,sectionlength);
    }
    return maxAns;
}
long double minimizeMaxDisBetter(vector<int> dist,int k){

    /*
    This solution has the time complexity of O(NlogN+KlogN) and space complexity of O(N-1)
    */
    vector<int> howmany(dist.size()-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<dist.size()-1;i++){
        long double diff = (dist[i+1]-dist[i]);
        pq.push({diff,i});
    }

    for(int gasStation = 1; gasStation <= k; gasStation++){
        auto topEle = pq.top(); pq.pop();
        int i = topEle.second;
        int t = ++howmany[i];

        long double finalTopEle = (dist[i+1]-dist[i])/(long double)(t+1);
        pq.push({finalTopEle,i});
    }

    return pq.top().first;
}




int main() {
    
    vector<int> arr = {1,13,17,23};
    cout << minimizeMaxDis(arr,5)<<endl;
    cout << minimizeMaxDisBetter(arr,5);
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printArray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearchIterative(vector<int> &arr, int t, int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != t)
        {
            if (t > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binarySearchRecursive(int *arr, int t, int low, int high)
{

    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == t)
        return mid;
    else if (t > arr[mid])
        return binarySearchRecursive(arr, t, mid + 1, high);
    return binarySearchRecursive(arr, t, low, mid - 1);
}

int lowerBound(int *arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int searchInRotatedSortedArray(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT32_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if(arr[mid] == target) return mid;

        if (arr[low] <= arr[mid])
        { // left is sorted
            if (arr[low] < ans)
                ans = arr[low];
            // if(arr[low]<=target && target <= arr[mid])
            // high = mid-1;
            low = mid + 1;
        }
        else
        { // right is sorted
            if (arr[mid] < ans)
                ans = arr[mid];
            // if(arr[mid]<=target && target <= arr[high])
            // low = mid+1;
            high = mid - 1;
        }
    }
    return ans;
}

int minimumInRotatedSortedArray(vector<int> nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low]; // after loop low == high --> min
}
int singleElement(vector<int> arr)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
            return arr[mid];
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid - 1] == arr[mid]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int peakForOneELement(vector<int> arr)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 2] < arr[n - 1])
        return arr[n - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid - 1] < arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySqrt(int n)
{
    int low = 1;
    int high = n;
    // int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            // ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int maxElement(vector<int> arr)
{
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[max] < arr[i])
            max = i;
    }
    return arr[max];
}
int kokoTotalHours(vector<int> arr, int mid)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += ceil((double)arr[i] / (double)mid);
    }
    return total;
}

int kokoBinarySearch(vector<int> piles, int h)
{
    int low = 1;
    int high = maxElement(piles);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (kokoTotalHours(piles, mid) <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int checkMinDaysToMakeMBouquets(vector<int> arr, int m, int k, int mid)
{
    if (m * k > arr.size())
        return -1;
    int count = 0;
    int completed = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= mid)
        {
            count++;
            cout << "count: " << count << endl;
            if (count >= k)
            {
                count -= k;
                completed++;
                cout << "completed: " << completed << endl;
            }
        }
        else{
            count = 0;
        }
    }
    cout << "completed: " << completed << endl;
    if (completed >= m)
        return 0;
    return 1;
}

pair<int, int> minDaysRange(vector<int> arr)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < arr[min])
            min = i;
        if (arr[i] > arr[max])
            max = i;
    }
    return {arr[min], arr[max]};
}

int minDaysToMakeMBouquets(vector<int> arr, int m, int k)
{
    pair<int, int> range = minDaysRange(arr);
    int low = range.first;
    int high = range.second;

    cout << "Started: \nlow: " << low << "\nhigh: " << high << endl;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "mid: " << mid << endl;
        int ch = checkMinDaysToMakeMBouquets(arr, m, k, mid);
        cout << "ch: " << ch << endl;
        if (ch == -1)
            return -1;
        else if (ch == 0)
            high = mid - 1;
        else
            low = mid + 1;
        cout << "low: " << low << endl;
        cout << "high: " << high << endl;
        cout << "......................\n\n\n\n";
    }
    return low;
}

bool possible(vector<int> arr,int threshold,int mid){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += ceil((double)arr[i]/(double)mid);
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int> arr, int threshold){
    int low = 1;
    int high = maxElement(arr);

    while(low<=high){
        int mid = (low+high)/2;
        if(possible(arr,threshold,mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}


pair<int,int> capacityRange(vector<int> arr){
    int sum = 0;
    int max = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>arr[max]){
            max = i;
        }
        sum += arr[i];
    }

    return {arr[max],sum};
}

int daysRequired(vector<int> arr, int capacity){
    int days = 1; 
    int load = 0;
    for(int i=0; i<arr.size(); i++){
        if(load+arr[i]>capacity){
            load = arr[i];
            days++;
        }else load += arr[i];
    }
    return days;
}

int leastCapacity(vector<int> arr,int days){
    pair<int,int> range = capacityRange(arr);
    int low = range.first;
    int high = range.second;

    while(low<=high){
        int mid = (low+high)/2;
        cout<<daysRequired(arr,mid)<<endl;
        if(days <= daysRequired(arr,mid)) high = mid-1;
        else low = mid+1;
        cout<<"low: "<<low<<" high: "<<high<<endl;
    }
    return low;
}

int lowerBoundB(vector<int> arr, int x){

    int low = 0;
    int high = arr.size()-1;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }else low = mid+1; 
    }
    return ans;
}


void printPattern(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j ==0 || i==n-1 || j==m-1){
                cout<<"*";
            }else cout<<" ";
        }
        cout<<endl;
    }
}


int findKthMissingNumber(vector<int> arr,int k){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        int missing = arr[mid]-(mid+1);
        if(missing<k) low = mid+1;
        else high = mid-1;
    }
    return high+1+k;
}


int main(){

    vector<int> arr = {2,4,6,7,11};
    int i = findKthMissingNumber(arr,6);
    cout<<i;
    
    return 0;
}
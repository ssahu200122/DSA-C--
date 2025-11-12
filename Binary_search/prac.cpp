#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T d){
        data = d;
        next = nullptr;
    }
};
template<typename K>
class LinkedList{
    public:
    Node<K> *head,*tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(K d){
        head = nullptr;
        tail = nullptr;
        append(d);
    }
    LinkedList(vector<K> arr){
        head = nullptr;
        tail = nullptr;
        for(int i=0;i<arr.size();i++){
            append(arr[i]);
        }

    }

    void append(K d){
        Node<K> *n = new Node<K>(d);
        if(head==nullptr){
            head =n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
    }

    void traverse(){
        Node<K> *current = head;
        while(current!=nullptr)
        { 
        cout<<current->data<<" ";
        current = current->next;
        }
        cout<<"--------"<<endl;
        
    }


};



bool canWePlace(vector<int> arr,int dist, int cows){
    int remainingCows = cows-1;
    int last = arr[0];
    int n = arr.size();
    for(int i=1;i<n;i++){
        if(remainingCows<=0) break;
        if(arr[i]-last>=dist){
            remainingCows--;
            last = arr[i];
        }
    }

    return remainingCows <= 0; 
}

int aggressiveCows(vector<int> arr,int k){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int i=1;i<=(arr[n-1]-arr[0]);i++){
        if (!canWePlace(arr,i,k)) return i-1;
    }
}

int aggressiveCowsB(vector<int> arr, int k){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 1;
    int high = (arr[n-1]-arr[0]);
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(arr,mid,k)) low = mid+1;
        else high = mid-1;
    }
    return high;
}


void demo(){
    for(int i=0;i<11;i++){
        for(int j=0;j<9;j++){
            if(j==5) break;
            cout<<"("<<i<<","<<j<<") ";
        }
        cout<<endl;
    }
}


int main(){
    vector<int> arr = {4, 2, 1, 3, 6};
    cout<<aggressiveCowsB(arr,2);
    return 0;
}
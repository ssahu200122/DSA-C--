#include <iostream>
#include <vector>
#include<algorithm>
#include<numeric>
using namespace std;

int numberOFStudent(vector<int> books,int pages) {
    int studentsRequired = 1;
    int currentPageSum = 0;
    for(int i=0; i<books.size();i++){
        if(books[i]+currentPageSum<=pages){
            currentPageSum += books[i];
        }
        else{
            studentsRequired++;
            currentPageSum = books[i];
        }
    }
    return studentsRequired;
}

int bookallocationProblemLinearSearch(vector<int> books,int students){
    int n = books.size();
    if(students>n) return -1;
    int maxpages = *max_element(books.begin(),books.end());
    long sumpages = accumulate(books.begin(),books.end(),0L);
    for(int i=maxpages;i<=sumpages;i++){
        if(students == numberOFStudent(books,i)) return i;
    }
}

int main() {
    
    vector<int> books = {25,46,28,49,24};
    cout<< bookallocationProblemLinearSearch(books,4);
    return 0;
}
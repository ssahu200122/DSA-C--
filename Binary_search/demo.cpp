#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;

        Node(T data){
            this->data = data;
            this->next = nullptr;
        }
};

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
    
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        void append(T data){
            Node<T>* temp = new Node<T>(data);
            if(!head) head = temp;
            if(!tail) tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }

        }

        void appendFromArray(T* arr,int n){
            for(int i=0;i<n;i++){
                this->append(arr[i]);
            }
        }

        void traverse(){
            Node<T>* temp = head;
            while(temp){
               cout<<temp->data<<" ";
               temp = temp->next;
            }
            
        }

        T pop(){
            T lastElement = tail->data;
            
        }
};

int main(){
    LinkedList<int> LL;
    LL.append(6);
    LL.append(8);
    LL.append(1);
    LL.append(9);
    int arr[] = {4,5,2,9,0,1};
    LL.appendFromArray(arr,6);
    LL.traverse();
}
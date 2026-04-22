#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
    public:
    vector<int> v;
    void insert(int data){
        v.push_back(data);
        int idx=v.size()-1;

        while(idx>0){
            int parent=(idx-1)/2;
            if(v[parent]<v[idx]){
                swap(v[parent],v[idx]);
                idx=parent;
            }
            else{
                break;
            }
        }
      
    }
    void print(){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
     void heapify(int idx){
        int left=2*idx+1;
        int right=2*idx+2;
        int largest=idx;

        if(left<v.size() && v[left]>v[largest]){
            largest=left;
        }
        if(right<v.size() && v[right]>v[largest]){
            largest=right;
        }
        if(largest!=idx){
            swap(v[largest],v[idx]);
            heapify(largest);
        }
    }
    int deleteMax(){
        if(v.size()==0){
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int ans=v[0];
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify(0);
        return ans;
    }
};
class MinHeap{
    public:
    vector<int> v;
    void insert(int data){
        v.push_back(data);
        int idx=v.size()-1;

        while(idx>0){
            int parent=(idx-1)/2;
            if(v[parent]>v[idx]){
                swap(v[parent],v[idx]);
                idx=parent;
            }
            else{
                break;
            }
        }
      
    }
    void print(){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
     void heapify(int idx){
        int left=2*idx+1;
        int right=2*idx+2;
        int largest=idx;

        if(left<v.size() && v[left]<v[largest]){
            largest=left;
        }
        if(right<v.size() && v[right]<v[largest]){
            largest=right;
        }
        if(largest!=idx){
            swap(v[largest],v[idx]);
            heapify(largest);
        }
    }
    int deleteMin(){
        if(v.size()==0){
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int ans=v[0];
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify(0);
        return ans;
    }
};
int main(){
    MinHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(15);
    h.insert(30);
  //  h.deleteMin();
    h.print();

    h.deleteMin();
    h.print();
    h.deleteMin();
    h.print();
}
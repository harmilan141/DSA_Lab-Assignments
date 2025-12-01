// heap basics

//heap basics append and delete function
#include <iostream>
#include<vector>
using namespace std;
class heap
{
  public:
  int getparent(int child)
  {
    return (child-1)/2; 
  }
  void doprecolateup(vector<int>&h)
  {
    int child=h.size()-1;
    while(1)
    {
        int parent=getparent(child);
        if(h[child]>h[parent])
        {
            swap(h[child],h[parent]);
            child=parent;
        }
        else break;
    }
  }
  int getchild1(int parent,vector<int>&h)
  {
    int child=parent*2+1;
    if(child>h.size()-1) return child;
    else return parent;
  }
  int getchild2(int parent,int size)
  {
    int child=parent*2+2;
    if(child<size) return child;
    else return parent;
  }
  int getchild2(int parent,int size)
  {
      int child= parent*2+2;
      if(child<size) return child;
      else return parent;
  }
  void doprecolatedown(vector<int>&h)
  {
    int parent=0;
    while(parent)
    {
        int child1=getchild1(parent,h.size());
        int child2=getchild2(parent,h.size());
        int maxpos=parent;
        if(h[child1]>h[maxpos])
        {
            maxpos=child1;
        }
        if(h[child2]>h[maxpos])
        {
            maxpos=child2;
        }
        
        if(maxpos!=parent)
        {
           swap(h[parent],h[maxpos]);
           parent=maxpos;
        }
        else break;
    }
  }
  void append(vector<int>&h,int val)
  {
    h.push_back(val);
    doprecolateup(h);
    show(h);
  }
  void dodelete(vector<int>&h)
  {
    h[0]=h[h.size()-1];
    h.pop_back();
    doprecolatedown(h);
    show(h);
  }
  void show(vector<int> heap)
    {
        cout<<"\n============\n";
        for(int i=0;i<heap.size();i++)
            cout<<heap[i]<<"  ";
    }
    
    void buildMaxHeap(vector<int>&h)
    {
        int n=h.size();
        for (int i = 0; i <n; i++) 
        {
            doprecolatedown(h);
        }
        show(h);
    }
};

int main()
{
     heap obj;
        
        vector<int> heap{10,21,45,1,45,3,5};
        obj.buildMaxHeap(heap);
        // obj.dodelete(heap);
        // obj.dodelete(heap);
        // obj.dodelete(heap);
        // obj.dodelete(heap);
        

    return 0;
}
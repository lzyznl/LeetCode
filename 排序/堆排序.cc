#include <iostream>
#include <vector>
using namespace std;

//不断向下调整，始终保持大根堆的结构
void HeapAdjust(vector<int>& vt,int k,int len)
{
    for(int i=2*k;i<=len;i*=2){
        if(i<len&&vt[i]<vt[i+1]){
            i++;
        }
        if(vt[k]>vt[i]){
            break;
        }
        else{
            swap(vt[k],vt[i]);
            k=i;
        }
    }
}

//建立大根堆
void BuildHeap(vector<int>& vt){
    int n = vt.size();
    for(int i=n/2;i>=1;--i){
        HeapAdjust(vt,i,n-1);
    }
}

void HeapSort(vector<int>& vt){
    int n = vt.size();
    BuildHeap(vt);
    for(int i=n-1;i>=1;--i){
        swap(vt[i],vt[1]);
        HeapAdjust(vt,1,i-1);
    }
}

void add(vector<int>& vt,int num){
    vt.push_back(num);
    HeapSort(vt);
}
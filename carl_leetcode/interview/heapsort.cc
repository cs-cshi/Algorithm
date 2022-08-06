#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& arr, int a,int b){
    arr[a]=arr[a]^arr[b];
    arr[b]=arr[a]^arr[b];
    arr[a]=arr[a]^arr[b];
}

void adjust(vector<int>& arr,int len,int index){
    int maxid=index;
    // 计算左右子节点的下标 left=2*i+1 right=2*i+2 parent=(i-1)/2
    int left = 2 * index + 1;
    int right = 2 * index + 2;
     // 寻找当前以index为根的子树中最大/最小的元素的下标
    if(left < len and arr[left] < arr[maxid]) 
        maxid=left;
    if(right < len and arr[right] < arr[maxid]) 
        maxid=right;
    // 进行交换，记得要递归进行adjust,传入的index是maxid
    if( maxid != index ){
        swap(arr,maxid,index);
        adjust(arr,len,maxid);
    }
}

void heapsort(vector<int>&arr,int len){
    // 初次构建堆，i要从最后一个非叶子节点开始，所以是(len-1-1)/2，0 这个位置要加等号
    for(int i = (len - 1 - 1) / 2; i >= 0 ; i--){
        adjust(arr,len,i);
    }
    
    // 从最后一个元素的下标开始往前遍历，每次将堆顶元素交换至当前位置，并且缩小长度（i为长度），从0处开始adjust
    for(int i=len-1;i > 0;i--){
        swap(arr,0,i);
        adjust(arr,i,0);// 注意每次adjust是从根往下调整，所以这里index是0！
    }
}

int main(){
    vector<int> arr={ 3,4,2,1,5,8,7,6 };
    cout<<"before: "<<endl;
    for(int item:arr) 
        cout<<item<<" ";
    cout<<endl;
    
    heapsort(arr,arr.size());
    cout<<"after: "<<endl;
    for(int item:arr)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class SGTree
{
    vector <int> seg;

    public:

    SGTree(int n)
    {
        seg.resize(4*n+1);
    }

    void build(int ind,int low,int high,vector <int> arr)
    {
        if(low==high)
        seg[ind]=arr[ind];

        int mid=low+(high-low)/2;
        build(ind*2+1,low,mid,arr);
        build(ind*2+2,mid+1,high,arr);

        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
        
    }
    int query(int ind,int low,int high,int l,int r) //query type 1 : (2,4)
    {
        //no overlap , so we return INT_MAX taaki we dont consider
        if(high<l || low>r) // query ==(2,4)=(l,r) , (0,1) & (5,6)
            return INT_MAX; // yahan yaa high chota h L se yaa low bda h r se 
   
        
        //complete overlap jaise (2,2) yaa (3,4) because it lies within that completely
        if(l<=low && high<=r) //(l<low<high<r) it means low and high lies btw l,r
        return seg[ind];      // sidha value return krdo
        
        //partial overlap jaise (1,2)
        int mid=low+(high-low)/2;
        int left=(ind*2+1,low,mid,l,r);
        int right=(ind*2+2,mid+1,high,l,r);
        return min(left,right);
   
    }

    void update(int ind,int low,int high,int i,int val)
    {
        if(low==high)
        seg[ind]=val;

        int mid=low+(high-low)/2;
        if(i<=mid)
        update(ind*2+1,low,mid,i,val);
        else
        update(ind*2+2,mid+1,high,i,val);

        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

    }


};
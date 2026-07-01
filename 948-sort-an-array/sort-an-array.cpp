class Solution {
public:

    void mergesort(vector<int>& a, int i, int j){
        if(i==j){
            return;
        }
        int mid=i+(j-i)/2;

        mergesort(a, i, mid);
        mergesort(a,mid+1, j);
        merge(a,i,mid,j);
    }

    void merge(vector<int>&a, int i , int mid, int j){
        vector<int> temp;
        int left=i;
        int right=mid+1;
        while(left<=mid and right<=j ){
            if(a[left]>a[right]){
                temp.push_back(a[right]);
                right++;
            }
            else{
                temp.push_back(a[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right<=j){
            temp.push_back(a[right]);
            right++;
        }


        int k=0;
        while(k<temp.size()){
            a[k+i]=temp[k];
            k++;
        }

    }


    vector<int> sortArray(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        

        mergesort(nums, i, j);
        return nums;
    }
};
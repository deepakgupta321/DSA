class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;



        while(i<=j){
            int mid=i+(j-i)/2;


            if(j-i+1<=2){
                int len=j-i+1;
                if(len==1){
                    return i;
                }
                for(int j=i; j<len; j++){
                    if(arr[j+1]>arr[j]){
                        return j+1;
                    }
                    return 0;
                }
            }

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }

            if(arr[mid]<arr[mid+1]){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return 0;
    }
};
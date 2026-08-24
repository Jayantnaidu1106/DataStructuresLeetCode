class Solution {
public:
    int search(vector<int>& arr, int x) {
        	int ans = -1;
	    
	    
	    int l = 0;
	    int r = arr.size()-1;
	    
	    while(l<=r){
	        int mid = l + (r-l)/2;
	        if(arr[mid]==x){
	            return mid;
	            
	        }
	        if(arr[l]<= arr[mid]){
	            if(x>= arr[l] && x<arr[mid]){
	                r = mid - 1;
	            }else{
	                l = mid+1;
	            }
	        }else{
	            if(x> arr[mid] && x<= arr[r]){
	                l = mid + 1;
	            }else{
	                r = mid - 1;
	            }
	        }
	    }

        return -1;
    }
};
//Merge
//Runtime: 32
//Memory Usage: 89.7


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int *mergedArr = new int [nums1.size() + nums2.size()];
       int index1 = 0, index2= 0, indexMerge = 0;
       int size = nums1.size() + nums2.size();
       while(1){
           if(index1 == nums1.size() || index2 == nums2.size()) break;
       	  mergedArr[indexMerge++] = ((nums1[index1] < nums2[index2]) ? nums1[index1++] : nums2[index2++]);
       	  
       }
       while(index1 < nums1.size()) mergedArr[indexMerge++] = nums1[index1++];
       while(index2 < nums2.size()) mergedArr[indexMerge++] = nums2[index2++];
        return ((mergedArr[(size) / 2] + mergedArr[(size - 1) / 2] ) / 2.0);	
    }
};

//Run half to find mid
//Runtime: 20
//Memory Usage: 89.3

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0, i = 0, j = 0, k = 0, n = nums1.size(), m = nums2.size(), right = 0;
        while(i < ((n + m) / 2 + 1)) {
            left = right;
            if(j < n && (k >= m || nums1[j] < nums2[k])){
                
                right = nums1[j++];
                 
            }else{
                right = nums2[k++];
            }
            
            ++i;
        }
        if((n + m) & 1) return right;
        else return (left + right) / 2.0;
    }
};

//Find K-th

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size(), len2 = nums2.size();
	int a = (len1 + len2 + 1) / 2, b = (len1 + len2 + 2)  / 2;
        return 0.5 * (kThSmall(nums1, 0, len1 - 1, nums2, 0, len2 - 1, a) + kThSmall(nums1, 0, len1 - 1, nums2, 0, len2 - 1, b));   
    }
private:
    int kThSmall(vector <int>& nums1, int begin1, int end1, vector<int>& nums2, int begin2, int end2, int k){
    	int len1 = end1 - begin1 + 1;
	int len2 = end2 - begin2 + 1;
	if(len2 > len1) return kThSmall(nums2, begin2, end2, nums1, begin1, end1, k);
	if(len2 == 0) return nums1[begin1 + k  - 1];

	if(k == 1) return min(nums1[begin1], nums2[begin2]);

	int i = begin1 + min(k / 2 , len1) - 1;
	int j = begin2 + min(k / 2,  len2) - 1;

	if(nums1[i] > nums2[j]) return kThSmall(nums1, begin1, end1, nums2, j  + 1, end2, k - (j - begin2 + 1));
	else return kThSmall(nums1, i + 1, end1, nums2, begin2, end2, k - (i - begin1 + 1));
	
    }
};
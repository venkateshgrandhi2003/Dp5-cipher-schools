// class Solution {
// public:
//     //O(M*N)
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i=0;i<n;i++){
//             int j=m+i-1;
//             for(;j>=0 && nums1[j]>nums2[i];j--){
//                 nums1[j+1]=nums1[j];
//             }
//             nums1[j+1]=nums2[i];
//         }
//     }
// };
/////////////////////////////////
class Solution {
public:
    //O(M+N)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=nums1.size();
        if(!n){
            return;
        }
        int i=m-1;//end of first array(filled)
        int j=n-1;//end of second array
        int k=len-1;//end of first array

        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                j--;
            }else{
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }

        while(j>=0){
            nums1[k]=nums2[j];;
            j--;
            k--;
        }
    }
};

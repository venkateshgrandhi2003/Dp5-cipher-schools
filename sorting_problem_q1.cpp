#include<bits/stdc++.h>
using namespace std;


// void sort012(vector<int> &nums){
//   int zero=0,one=0,two=0;
//   for(const int &n:nums){
//     if(n==0){
//       zero++;
//     }else if(n==1){
//       one++;
//     }else{
//       two++;
//     }
//   }

//   for(int &n:nums){
//     if(zero>0){
//       n=0;
//       zero--;
//     }else if(one>0){
//       n=1;
//       one--;
//     }else{
//       n=2;
//       two--;
//     }
//   }
// }

void sort012(vector<int> &nums){
      int low=0,mid=0,high=nums.size()-1;
      while(mid<=high){
          switch(nums[mid]){
              case 0:swap(nums[low],nums[mid]);low++,mid++;break;
              case 1:mid++;break;
              case 2:swap(nums[high],nums[mid]);high--;break;
          }
      }
}

int main(){
  vector<int> arr{1,1,0,2,2,1,2,1};
  sort012(arr);
  for(const int &n:arr){
    cout<<n<<" ";
  }
}
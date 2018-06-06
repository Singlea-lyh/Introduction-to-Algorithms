/* 
 * 实现最大子数组问题
 * 方法一：一般算法，穷举法
 * 方法二：分支策略
 *
 * 测试数组：{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}
 * 最大数组为：{18, 20, -7, 12}
 */

#include <iostream>

// #define DIVIDE_STRATEGY 1
#define NORMAL 1


using namespace std;

typedef struct Max_SubArray_Info{
    int left;
	int right;
	int max_value;
}MaxSubArrayInfo;

MaxSubArrayInfo Get_Max_SubArray_Divide(int A[], int left, int right);
MaxSubArrayInfo Get_Max_SubArray(int A[], int left, int right);
MaxSubArrayInfo Get_Max_SubArray_CrossMid(int A[], int left, int mid, int right);

int main(){
	int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    MaxSubArrayInfo stMaxSubArray;
	int i = 0;

#ifdef DIVIDE_STRATEGY 
	stMaxSubArray = Get_Max_SubArray_Divide(A, 0, 15);
#endif 
#ifdef NORMAL
	stMaxSubArray = Get_Max_SubArray(A, 0, 15);
#endif
	cout<<"Max Sub Array : " << endl;
	for (i = stMaxSubArray.left ; i <= stMaxSubArray.right; i++)
	  cout << "A["<<i<<"] : " << A[i] << endl;
    cout<<"Max Value is: " <<  stMaxSubArray.max_value<<endl;
	return 0;
}

#ifdef DIVIDE_STRATEGY 
MaxSubArrayInfo Get_Max_SubArray_Divide(int A[], int left, int right){
     MaxSubArrayInfo stMaxSubArray;
	 MaxSubArrayInfo stLeftMaxSubArray;
	 MaxSubArrayInfo stRightMaxSubArray;
	 MaxSubArrayInfo stCrossMidMaxSubArray;

	 int mid = 0;
	 if(left == right){
	     stMaxSubArray.left = left;
		 stMaxSubArray.right= left;
		 stMaxSubArray.max_value = A[left];
		 return stMaxSubArray;
	 }
	 else{
		 mid = (left + right) / 2;
	     stLeftMaxSubArray = Get_Max_SubArray_Divide(A, left, mid);
		 stRightMaxSubArray = Get_Max_SubArray_Divide(A, mid + 1, right);
		 stCrossMidMaxSubArray = Get_Max_SubArray_CrossMid(A, left, mid, right); 
	 }
	 if (stLeftMaxSubArray.max_value > stRightMaxSubArray.max_value &&
				 stLeftMaxSubArray.max_value > stCrossMidMaxSubArray.max_value){
	     stMaxSubArray.left = stLeftMaxSubArray.left;
		 stMaxSubArray.right = stLeftMaxSubArray.right;
		 stMaxSubArray.max_value = stLeftMaxSubArray.max_value;
	 }
	 else if(stRightMaxSubArray.max_value > stLeftMaxSubArray.max_value && 
				 stRightMaxSubArray.max_value > stCrossMidMaxSubArray.max_value){
		 stMaxSubArray.left = stRightMaxSubArray.left;
		 stMaxSubArray.right = stRightMaxSubArray.right;
		 stMaxSubArray.max_value = stRightMaxSubArray.max_value;	    
	 }
	 else{
		 stMaxSubArray.left = stCrossMidMaxSubArray.left;
		 stMaxSubArray.right = stCrossMidMaxSubArray.right;
		 stMaxSubArray.max_value = stCrossMidMaxSubArray.max_value;
	 }
	 return stMaxSubArray;
}

MaxSubArrayInfo Get_Max_SubArray_CrossMid(int A[], int left, int mid, int right){
	MaxSubArrayInfo stMaxSubArray;
    
	int left_sum, right_sum, sum;
	int i, left_k, right_k;
	sum = 0;
    left_sum = A[mid];
	left_k =  mid;
	for(i = mid; i >= left; i--){
		sum += A[i];
		if(sum > left_sum){
		    left_sum = sum;
			left_k = i;
		}
	}
	sum = 0;
	right_sum = A[mid + 1];
	right_k = mid + 1;
	for(i = mid + 1; i <= right; ++i){
		sum += A[i];
		if(sum > right_sum){
			right_sum = sum;
			right_k = i;
		}
	}

	stMaxSubArray.left = left_k;
	stMaxSubArray.right = right_k;
	stMaxSubArray.max_value = left_sum + right_sum;

	return stMaxSubArray;
}
#endif

#ifdef NORMAL  
MaxSubArrayInfo Get_Max_SubArray(int A[], int left, int right){
    int left_max, right_max, max_value;
    int i, j;
	int temp_value, temp_k, temp_max;
	MaxSubArrayInfo stMaxSubArray;
    
	max_value = -99999999;

	for(i = left; i < right; ++i){
		temp_value = A[i];
		temp_max = A[i];
		temp_k = i;
		for(j = i + 1; j <= right; ++j){
			temp_value += A[j];
			if(temp_value > temp_max){
				temp_max = temp_value;
				temp_k = j;
			}
		}
		if(temp_max > max_value){
			max_value = temp_max;
			left_max = i;
			right_max = temp_k;
		}
	}
    stMaxSubArray.left = left_max;
	stMaxSubArray.right = right_max;
	stMaxSubArray.max_value = max_value;

	return stMaxSubArray;
}


#endif 





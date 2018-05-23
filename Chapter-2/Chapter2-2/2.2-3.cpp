/*
 *选择排序伪代码：
  SelesctSort(A)
       for i = 1 to n-1
	       temp = A[i]
		   k = i
		   j = i + 1
		   while(j <= n )
		       if(A[j] < temp )
			          temp = A[j]
					  k = j
				++j
			temp = A[i]
			A[i] = A[k]
			A[j] = temp 
   循环不变式：每次排序后数组前面的以排的序列有序
   由于每次都要从头到未进行遍历，所以最好和最坏情况下的时间复杂读相似，都为O(n*n)
   当前面的n-1个数排序之后，最后一个自然有序，所以只需要进行n-1次排序
 */

#include<iostream>

int main(){
    using namespace std;
	int i, j, k;
	int A[6] = {31, 41, 59, 26, 41, 58};
    int temp;

	for(i = 0; i < 5; ++i){
		temp = A[i];
		k = i;
		j = i + 1;
		while(j < 6){
			if(A[j] < temp){
				temp = A[j];
				k = j;
			}
		    ++j;
		}
		temp = A[i];
		A[i] = A[k];
		A[k] = temp;
		for(k = 0; k < 6; ++k)
		  cout<< A[k] << " ";
		cout<<endl;
	}
}

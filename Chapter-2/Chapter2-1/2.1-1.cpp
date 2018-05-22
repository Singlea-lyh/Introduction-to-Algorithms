/* 
 *打印数组A = < 31, 41, 59 26, 41, 58>的插入排序过程
 *
 */ 

#include<iostream>

int main(){
	using namespace std;
	int A[6] = {31, 41, 59, 26, 41, 58};
	int i , j, key;

	for(j = 1; j < 6; ++j){
		key = A[j];
        i = j - 1;	
		while(i >= 0 && A[i] > key ){
			A[i + 1] = A[i];
			--i;
		}
	    A[++i] = key;
		for(int k = 0; k < 6; ++k)
		  cout<< A[k] << " ";
		cout<<endl;
	}
}

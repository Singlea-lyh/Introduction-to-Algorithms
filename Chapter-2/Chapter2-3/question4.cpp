/*# 给出一个确定n个元素任意排列中逆序对数量的算法，时间复杂度为nlgn
*
*算法描述：采用归并排序的思想，在最后合并时，比较数组中元素大小，计算逆序对数，每次合并时，前面数组元素小于后面数组，则逆序对数加一

*伪代码：
*   globalInversion = 0                     // 记录逆序对数 
*   INVERSIONMERGER(A, p, q, r)
*       n1 = q - p + 1;
*       n2 = r - q;
*       for i = 1 to n1 
*            L[i] = A[p + i - 1]
*       for i = 1 to n2 
*            R[i] = A[q + i]
*        i = 1
*        j = 1
*        for k = p to r
*            if L[i] > R[j] 
*                A[k] = R[j]
*                ++j
*                ++globalInversion
*            else 
*                A[k] = L[i]
*                ++i
*            if j > n2 or i > n1 
*                break 
*       while(i <= n1 )
*            A[++k] = L[i++]
*       while(j <= n2)
*            A[++k] = R[i++]
*            
*/ 
#include <iostream>
using namespace std;
#if 0
int globalInversion = 0;
int  INVERSIONMERGER(int A[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for(i = 0; i < n1; ++i)
	{
		L[i] = A[left + i];
	}
	for(j = 0; j < n2; ++j)
	{
		R[j] = A[mid + j + 1];
	}
	i = 0; j = 0;
	for(k = left; k <= right; ++k)
	{
		if(L[i] > R[j])
		{
			A[k] = R[j++];
			// cout<< ++globalInversion << " : " << "<" << L[i] << "," << R[j] << ">" << endl;
			globalInversion = n1 - i;
		}
		else 
		{
			A[k] = L[i++];
		}
	    if(i >= n1 || j >= n2)
		  break;
	}
	while(i < n1)
	  A[++k] = L[i++];
	while(j < n2)
	  A[++k] = R[j++];
	for(int l = 0; l < 5; l++)
	  cout<< A[l] << " ";
	cout<<endl;
	return globalInversion;
 }

int  MERGERSORT(int A[], int left, int right)
{
	int mid = (right + left) / 2;
	int nleft , nright , count;
	if(left < right)
	{
	   nleft = MERGERSORT(A, left, mid);
	   nright = MERGERSORT(A, mid + 1, right );
	   count = nleft + nright +INVERSIONMERGER(A, left, mid, right);
	} 
	
    for(int i = 0; i < 5; ++i)
	  cout<< A[i] << " ";
	cout<<endl;
    cout << count << endl;
	return count;
}

int main()
{
	int A[5] = {2, 3, 8, 6, 1};
	MERGERSORT(A, 0, 4);
	return 0;
}
#endif


#if 1
#define MAX_VALUE 12343564
int Count_Reversations(int *A, int n);
int Merge_Reversations(int *A, int p, int r);
int main(){
     int a[5] = { 2,3,8,6,1 };
     cout << Count_Reversations(a, 5) << endl;
     return 0;
}
int Count_Reversations(int*A, int n){ //接口函数
     return Merge_Reversations(A, 0, n - 1);
}
int Merge_Reversations(int *A, int p, int r){
     if (p>=r)
          return 0;
     int i, j, k,mid,n1,n2, reversations = 0;
     mid = (p + r) >> 1;
     int next_count= Merge_Reversations(A, p, mid) + Merge_Reversations(A, mid + 1, r);
     n1 = mid - p + 1;
     n2 = r - mid;
     int *R = new int[n2 + 1];
     int *L = new int[n1 + 1];
     for (i = 0; i < n1; i++)
          L[i] = A[i + p];
     for (j = 0; j < n2; j++)
          R[j] = A[j + mid + 1];
     L[n1] = R[n2] = MAX_VALUE; //设置为最大值，当做哨兵
     i = j = 0;
     for (k = p; k <= r; k++){
          if (L[i]>R[j]){
                 reversations +=n1-i;
                 A[k] = R[j++];
     }
     else
         A[k] = L[i++];
}
    delete[]R, L;
    return reversations +next_count;
}

#endif

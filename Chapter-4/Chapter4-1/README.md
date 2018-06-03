# 最大子数组问题

/*
    最大子数组问题：以一个非全是正数的数组中，寻找此数组的最大子数组。

	方法1、暴力求解法，求解出数组的所有子数组，比较所有子数组，从而求出最大子数组
	方法2、分治法：求解数组A[low...high]的在最大子数组，先将数组分解为两个规模相等的子数组，在求解子数组的最大子数组，比如将数组分解为
	               A[low...mid] 和 A[mid + 1 ...high] 两个子数组。此时A[low...high]的最大子数组A[i ... j]必然满足以下三种情况：
				     1) 完全位于子数组A[low ... mid]中，此时low <= i <= j <= mid
					 2) 完全位于子数组A[mid ... high]中，此时mid < i <= j <= high
					 3) 跨越了中点，此时low <= i <= mid < j <=high
			      A[low ... high] 的最大子数组必然是A[low ... mid] 、A[mid + 2 ... high] 、跨越中点的最大子数组中的最大者。可以递归的求解
				  A[low ... mid] 和 A[mid ... high]的最大子数组。对于跨越中点的最大子数组由于有了限制条件，所以可在线性时间内求出起最大子
				  数组。
				  时间复杂度：T(n) = 2T(n) + θ(n)


*/

方法一伪代码：
FIND-MAX-SUBARRAY(A, low, high)
   max-sum = 0;
   for i = low to high
	   sub-sum = sub-max-sum = A[i]
	   sub-low = sub-high = i
	   for j = i + 1 to high
	       sub-sum = sub-sum + A[j]
           if sub-sum > sub-max-sum
		      sub-max-sum = sub-sum
			  sub-high = j
       if sub-max-sum > max-sum 
	      lef = i
		  right = sun high
		  max-sum = sub - max -sum
	return (left, high, max-sum)

方法二伪代码：
// 求跨越中点的最大子数组
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)        
     left-sum = A[mid] 
	 right-sum = A[mid + 1]
	 sum = 0
	 for i = mid downto low
	     sum += A[i]
		 if left-sum < sum 
		     left-sum = sum
			 left = i
	 
	sum = 0
	for i = mid + 1 to high
	    sum += A[i]
	    if righ-sum < sum 
		   right-sum = sum 
		   right = i
	return (left, high, left-sum + right-sum)

// 求解最大子数组的递归
FIND-MAX-SUBARRAY(A, low, high)
	if(low == high)
		return (low, high, A[high])
	else mid = (low + high) / 2
	    (left-low, left-high, left-sum) = FIND-MAX-SUBARRAY(A, low, mid)
		(right-low, right-high, right-sum) = FIND-MAX-SUBARRAY(A, mid + 1, high)
		(cross-left, cross-right, cross-sum) = FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
	if left-sum > right-sum and left-sum > cross-sum
	    return (left-low, left-high, left-sum)
	elseif right-sum > left-sum and right-sum > cross-sum
	    return (right-low, right-high, right-sum)
	else 
	    return (cross-low, cross-high, cross-sum)



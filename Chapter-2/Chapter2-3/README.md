#设计算法

#2.3.1 分治法
     采用递归思想，分为三个步骤：分解， 解决子问题， 合并
	 归并排序的核心在于以排好序列的合并
  #归并排序合并操作伪代码：

    MERGE(A, p, q, r)
		n1 = q - p + 1
		n2 = r - q
		//let L[1..n1 + 1] and R[1 .. n2 + 1] be new arrays
		for i = 1 to n1
		     L[i] = A[p + i - 1]
		for i = 1 to n2
		     R[i] = A[q + i]
	    L[n1 + 1] = @@
		R[n2 + 1] = @@               //@@表示无穷大
		i = 1
		j = 1
		for k = p to r
		     if L[i] <= R[j]
			     A[k] = L[i]
				 i++
			else
			     A[k] = R[j]
				    j++

     #归并排序伪代码
		 MERGE-SORT(A, p, r)
		      if(p < r)
		           q = (p + r) / 2   //向下取整
				   MERGE-SORT(A, p, q)
		           MERGE-SORT(A, q + 1, r)
		           MERGE(A, p, q, r)


#2.3.2 分析分治算法
		算法时间复杂度：@@(nlgn)               //@@表示theta

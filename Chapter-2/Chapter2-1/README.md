#插入排序

#插入排序伪代码
INSERTION-SORT(A)
		for j = 2 to A.length
		    key = A[j]
			i = j -1
			while i > 0 and A[i] > key
			    A[i + 1] = A[i]
				i = i -1
		    A[i + 1] = key

#证明循环不变式正确性分三步：初始化，保持，终止



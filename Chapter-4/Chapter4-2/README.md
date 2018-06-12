# 矩阵乘法的Strassen算法

#普通矩阵乘法伪代码：
SQUARE-MAXTRIX-MULTIPLY(A, B)
	n = A.rows
	let C be new n*n matrix
	for i = 1 to n
	    for j = 1 to n 
		C[i][j] = 0
		for k = 1 to n 
          C[i][j] += A[i][k] * B[k][j]
时间复杂度为 O(n*n*n)

# 使用普通递归 
SEQARE-MATRIX-MULTIPLY-RECURSIVE(A, B)
		n = A.rows
		let C be new n*n matrix
		if n == 1 
		    C[i][j] = A[1][1] * B[1][1]
		else 
		    C[1][1] = SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[1][1] , B[1][1])
		            + SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[1][2] , B[2][1])
		    C[1][2] = SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[1][1] , B[1][2])
		            + SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[1][2] , B[2][2])
		    C[1][1] = SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[2][1] , B[1][2])
		            + SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[2][2] , B[2][1])
		    C[1][1] = SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[2][1] , B[1][2])
		            + SEQSRE-MATRIX-MULTIPLY-RECURSIVE(A[2][2] , B[2][2])
		return C

注意：以上中的A[1][1], A[1][2],A[2][1], A[2][2], B[1][1], B[1][2],B[2][1], B[2][2], 不是数组中对应位置的值，而是将数组平分后的不同部分


时间复杂度为 θ(n * n * n)


#Strassen 算法


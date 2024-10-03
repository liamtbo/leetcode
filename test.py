
num = 6
matrix = []
for i in range(num): matrix.append([0] * num)
for i in range(num):
    for j in range(num):
        matrix[i][j] = i * num + j
for row in matrix:
    print(row)

alpha = [0,0]
print(matrixalph)
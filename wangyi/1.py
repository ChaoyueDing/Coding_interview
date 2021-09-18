m = input()

grid = [[] for i in range(m)]
for i in range(m):
    line = input().split('')
    for j in range(len(line)):
        grid[i].append(int(line[j]))

def pooling(input_h, input_w, kernel_h, kernel_w, stride_h):
    res = []
    for i in 

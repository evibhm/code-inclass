# 用递归方法求数列“1，1，1，3，5，9，17，31……”的前 20 项

arr = [1, 1, 1]
for i in range(4, 21):
    arr.append(sum(arr[-3:]))
print(arr)

# 没用的递归版
def rec(n: int):
    return rec(i-1) + rec(i-2) + rec(i-3) if n > 3 else 1


print(rec(i) for i in range(1, 21))
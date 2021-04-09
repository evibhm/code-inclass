prime_nums = []
for i in range(2, 1001):
    for j in range(2, int(i ** 0.5) + 1):
        if i % j == 0:
            break
    else:
        prime_nums.append(i)
print("Prime numbers: ", prime_nums)
print("Total: ", len(prime_nums))

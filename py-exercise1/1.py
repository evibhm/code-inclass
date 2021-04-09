print("Please input three integers:")
num = [eval(i) for i in input().split()]
num_sum = sum(num)
num_avg = num_sum / len(num)
print("Sum = {}, Avg = {}".format(num_sum, num_avg))

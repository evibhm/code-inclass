def fun_for():
    sum = 0
    for i in range(1, 1001):
        sum += i
    return sum


def fun_while():
    sum = 0
    i = 1
    while i < 1001:
        sum += i
        i += 1
    return sum


print("For loop sum: ", fun_for())
print("While loop sum: ", fun_while())

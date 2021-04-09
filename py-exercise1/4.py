while True:
    print("Please enter the three sides of the triangle:")
    try:
        side = [eval(i) for i in input().split()]
        if len(side) != 3:
            print("There are no three input data")
            continue
        if side[0] + side[1] > side[2] and side[1] + side[2] > side[0]\
           and side[2] + side[0] > side[1]:
            break
        print("ERROR: The input side length cannot form a triangle.")
    except(NameError, SyntaxError):
        print("ERROR: The input data is not a real number.")
p = sum(side) / 2
area = p
for i in side:
    area *= p - i
area = area ** 0.5
print("Area: {:.2f}".format(area))

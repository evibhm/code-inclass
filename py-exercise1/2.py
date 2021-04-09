denominations = (50, 20, 10, 5, 1)

print("Please enter the amount payable and the actual amount paid:")
amount_payable, amount_actual = [eval(i) for i in input().split()]
amount_change = amount_actual - amount_payable
print("Should get change: {} yuan".format(amount_change))
ac = amount_change
for den in denominations:
    if ac >= den:
        print("{} yuan banknotes * {}".format(den, ac // den))
        ac %= den

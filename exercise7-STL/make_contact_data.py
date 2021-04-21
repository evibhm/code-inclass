from random import randint
from random import choices
name = [chr(i) for i in range(65, 91)] + [chr(i) for i in range(97, 123)]

with open("contact_data.txt", "w") as f:
    for i in range(10000):
        f.write("{} {}\n".format("".join(choices(name, k=randint(3, 5))), randint(1000000, 9999999999)))
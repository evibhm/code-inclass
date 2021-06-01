dict_data = {"计算机科学 2104":33, "计算机科学 2102":28, "计算机科学 2101":34, "计算机科学 2103":30}

print("按键排序：")
print(sorted(list(dict_data.items()), key=lambda x: x[0]))

print("按值排序：")
print(sorted(list(dict_data.items()), key=lambda x: x[1]))

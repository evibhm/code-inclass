import pprint

dicTXL = {"小新": {"手机": "13913000001", "QQ": "18191220001"},
          "小亮": {"手机": "13913000002", "QQ": "13913000002"},
          "小刚": {"手机": "13913000003", "QQ": "18191220003"}}
dicOther = {"大刘": {"手机": "13914000001", "QQ": "18191230001"},
            "大王": {"手机": "13914000002", "QQ": "18191230002"},
            "大张": {"手机": "13914000003", "QQ": "18191230003"}}
dicWX = {"小新": "xx9907", "小刚": "gang1004", "大王": "jack_w", "大刘": "liu666"}

dicTXL.update(dicOther)
print("合并字典：")
pprint.pprint(dicTXL)

for k, v in dicTXL.items():
    if k in dicWX.keys():
        v["微信"] = dicWX[k]
    else:
        v["微信"] = v["手机"]
print("追加字典：")
pprint.pprint(dicTXL)

# TEST 1
print("TEST 1:")
print("字典数据：")
pprint.pprint(dicTXL)

# TEST 2
print("TEST2:")
dicTXL["小刚"]["手机"] = "13913000006"
print("修改后字典数据：")
pprint.pprint(dicTXL)

# TEST 3
print("TEST 3:")
name = input("请输入要查询的联系人：")
if name in dicTXL.keys():
    print(f"{name}的联系方式是：")
    pprint.pprint(dicTXL[name])
else:
    print("没有该同学的联系方式")

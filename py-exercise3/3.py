s = {
    "小李": [77, 54, 57],
    "小张": [89, 66, 78],
    "小杨": [69, 58, 93],
}
s = {
    '小李': [77, 54],
    '小张': [89, 66, 78, 99],
    '小陈': [90], 
    '小杨': [69, 58, 93]
}


def avg(*args):
    return int(sum(args)/len(args))


res = {}
for k, v in s.items():
    res[k] = avg(*v)
print(res)

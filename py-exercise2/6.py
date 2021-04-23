from typing import Counter


course1 = {'李雷', '张玉', '王晓刚', '陈红静', '方向', '司马清'}
course2 = {'施小冉', '李芳芳', '刘潇', '方向', '孙一航', '黄煌'}
course3 = {'陈红静', '方向', '刘培良', '张玉', '施小冉', '司马清'}

data = {}
for name in course1:
    data[name] = data.get(name, 0) + 1
for name in course2:
    data[name] = data.get(name, 0) + 1
for name in course3:
    data[name] = data.get(name, 0) + 1

print(f"{25 - len(data)} 名同学没有选课")

count = Counter(data.values())
print(f"{count[3]} 名同学选了三门课")
print(f"{count[2]} 名同学选了两门课")
print(f"{count[1]} 名同学选了一门课")

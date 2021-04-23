import pandas as pd

data = pd.read_excel("1.xlsx", index_col=0)
data.rename(columns={"工作经历（年）": "工作经历"}, inplace=True)

for index, row in data.iterrows():
    if row["所学专业"] == "计算机科学" and row["年龄"] < 25:
        print(f"{index}:获得面试机会")
    elif row["所学专业"] == "人工智能" and row["工作经历"] >= 2:
        print(f"{index}:获得面试机会")
    elif row["所学专业"] == "大数据":
        print(f"{index}:获得面试机会")
    else:
        print(f"{index}:抱歉，您不符合面试要求")

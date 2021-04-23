while True:
    try:
        n = int(input("请输入一个正整数："))
    except BaseException:
        print("ERROR: 输入的不是正整数，请重新输入")
    else:
        if n > 0:
            break
        else:
            print("ERROR: 输入的不是正整数，请重新输入")

if n < 16:
    print("不存在能被 16 整除的数")
else:
    print(f"能被 16 整除的最大的数是 {n // 16 * 16}")

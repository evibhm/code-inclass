for hundurd in range(3, 6): # 已知 600 不是水仙花数
    for decade in range(0, 10):
        for unit in range(0, 10):
            if hundurd ** 3 + decade ** 3 + unit ** 3 ==\
               hundurd * 100 + decade * 10 + unit:
                print(hundurd * 100 + decade * 10 + unit)

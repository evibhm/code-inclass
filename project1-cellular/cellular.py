# -*- coding: utf-8 -*-
"""
Created on Tue Nov 24 10:35:42 2020

@author: Mr.Wang
"""

# 课程：计算科学基础（课后实践练习）
# 实践内容：设计生命游戏，完成cellular.py的代码编写

############### 答题者信息-开始 ###############
# 姓名： your name
# 学号： your code
# 合作者（如有）：
############### 答题者信息-结束 ###############


# 元胞自动机--生命游戏
############### 帮助代码-开始 ###############

# 答题者无需理解帮助代码的实现细节，但仍需要掌握如何使用该部分函数
# 以下代码中，确保可以直接调用random()函数
import os
from random import random 

#系统指定生命空间的大小，也即：6行；6列
width=6
hight=6

###辅助函数1 初始化生命空间
def init(life_prob):
    #(life_prob=0.2):
    """
    初始化游戏，以life_prob的概率生成活细胞
    输入：life_prob——生成活细胞的概率
    输出：width x height大小的细胞状态
    """   
    screen = [[' ' for i in range(width+2)] for j in range(hight+2)]
    for i in range(1, hight+1):
        for j in range(1, width+1):
            if random() < life_prob:
                screen[i][j] = 'o'
    return screen
    # 请将以下"pass"删除，然后补充函数的实现代码


###辅助函数2 打印细胞状态
def print_screen(screen):
    """ 
    screen 参数类型与init()函数返回值类型一致，表示当前
    细胞状态。由于屏幕打印时行距比字符宽度大很多，所以请在打印
    每个字符后面加空格，并在最后一个字符的后面打印'|'表示生命
    空间的边界(注意：表示生命空间边界的符号可以换成你们喜欢的符号，不局限
    于'|')
    """
    print(' ', end='')
    for i in range(hight):
        print('_', end='_')
    print('_')
    print('|', end='')
    for i in range(hight):
        print(' ', end=' ')
    print(' |')
    for i in range(1, hight+1):
        print('|', end=' ')
        for j in range(1, width+1):
            print(screen[i][j], end=' ')
        print('|')
    print('|', end='')
    for i in range(hight):
        print('_', end='_')
    print('_|')
    # 请将以下"pass"删除，然后补充函数的实现代码


###辅助函数3 计算相邻细胞中活细胞的数目
def get_near_by_cells_count(screen, x, y):
    """
    get_near_by_cells_count()的形参有：screen, x, y；
    其中screen与init()函数的返回值类型一致，表示当前细胞的状态；
    x和y均为int类型，表示生命空间各细胞,也即：n*n空间内的格子，所在的行号和列号
    函数返回值为int类型，表示位置(x，y)的细胞其相邻活细胞的数量
    """
    cnt = 0
    if x < 1 or x > hight or y < 1 or y > width:
        print("ERROR: OUT OF RANGE!")
    else:
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if screen[i][j] == 'o':
                    cnt += 1
        if screen[x][y] == 'o':
            cnt -= 1
    return cnt
    # 请将以下"pass"删除，然后补充函数的实现代码


###辅助函数4 更新细胞的状态
def update(screen):
    """
    该函数包含一个参数，screen，其类型与init()函数返回值类型一致，表示当前
    细胞状态。该函数根据传入生命空间screen内细胞的状态，利用更新原则对细胞
    状态进行更新，并返回更新后的细胞状态，返回值类型与screen类型一致
    
    """
    new_screen = [[' ' for i in range(width + 2)] for j in range(hight + 2)]
    for i in range(1, hight+1):
        for j in range(1, width+1):
            new_screen[i][j] = screen[i][j]
    for i in range(1, hight+1):
        for j in range(1, width+1):
            count = get_near_by_cells_count(new_screen, i, j)
            if count == 3:
                new_screen[i][j] = 'o'
            elif count != 2:
                new_screen[i][j] = ' '
    return new_screen
    # 请将以下"pass"删除，然后补充函数的实现代码


###辅助函数5，判断细胞状态是否没有变化
def is_state_same(screen, new_screen):
    """
    参数screen和new_screen分别表示更新前和更新后的细胞状态
    根据判断更新前后细胞的状态，如果更新前细胞(i,j)的状态与更新后细胞(i,j)
    的状态一致，则返回True；否则返回False

    """
    is_same = True
    for i in range(1, hight+1):
        for j in range(1, width+1):
            if screen[i][j] != new_screen[i][j]:
                is_same = False
                break
        if is_same == False:
            break
    return is_same
    # 请将以下"pass"删除，然后补充函数的实现代码


#####以下为主程序，主要实现游戏实现与人机互动
def start():
    """
    (1)游戏开始后，用户输入活细胞的概率：life_prob的值，并调用辅助函数1 
    实现生命空间内细胞状态的随机生成
    (2)根据辅助函数1生成的细胞状态，调用辅助函数2，将当前细胞的状态进行打印
    (3)实现人机互动，如果按q键则结束游戏；如果按其他键则继续游戏
    (4)提示：如果要继续游戏，则需要对细胞生命状态进行更新，也即需要调用辅助函数3；
    并判断细胞生命状态更新前后差异，如果没有变化则终止游戏
    """

    ##以下代码实现了输入任意键游戏开始功能
    #os.system("cls") # 用于清空窗口之前打印的内容
    #print('==== 元胞自动机 ====')
    #print('作者：your name\n')
    #print('按下任意键开始游戏...')
    #input()
    #os.system("cls")
    ##请在以下部分实现主程序的上述功能
    #os.system("cls") # 用于清空窗口之前打印的内容
    print('==== 元胞自动机 ====')
    print('作者：your name\n')
    print('按下任意键开始游戏...')
    input()
    os.system("cls")
    screen = init(random())
    print_screen(screen)
    while True:
        print("按下任意键继续，q键结束：")
        operation = input()
        if operation == 'q':
            break
        new_screen = update(screen)
        if is_state_same(screen, new_screen):
            print("This is the last status.")
            break
        else:
            screen = new_screen
        os.system("cls")
        print_screen(screen)
    # 请将以下"pass"删除，然后补充函数的实现代码


###以下为主程序的测试代码
if __name__ == "__main__":
    
    # 以下为start()函数的测试代码
    start()




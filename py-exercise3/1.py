import numpy as np


def area(r: float):
    return np.math.pi * r * r


print(f"半径为 {3.5} 的圆的面积是：{area(3.5):.2f}")
print(f"半径为 {2.9} 的圆的面积是：{area(2.9):.2f}")
print(f"外圆半径为 {6.2}，内圆半径为 {3.3} 的圆环面积是：{area(6.2)-area(3.3):.2f}")
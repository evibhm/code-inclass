def fun(*nums):
    nums_avg = sum(nums) / len(nums)
    return tuple([nums_avg] + [i for i in nums if i < nums_avg])


if __name__ == "__main__":
    # TEST
    print(fun(1, 2, 3, 4, 5, 6))

import jieba

try:
    with open("三国演义.txt", "r", encoding="GBK") as f:
        text = f.read()
except FileNotFoundError:
    print("无法打开指定的文件!")
    exit(0)
except LookupError:
    print("指定了未知的编码!")
    exit(0)
except UnicodeDecodeError:
    print("读取文件时解码错误!")
    exit(0)
except IOError:
    print("读取文件出错")
    exit(0)
else:
    print("读取文件成功")


jieba.del_word("玄德曰")
jieba.del_word("孔明曰")

words = jieba.cut(text)
word_frequency = {}

for word in words:
    if len(word) > 1:
        word_frequency[word] = word_frequency.get(word, 0) + 1
exclude_words = ["却说", "不可", "不能", "如此", "如何"]
for word in exclude_words:
    try:
        del(word_frequency[word])
    except:
        continue

word_frequency = list(word_frequency.items())
word_frequency.sort(key=lambda x: x[1], reverse=True)

for k, v in word_frequency[:20]:
    print(f"{k:<10}{v:>5}")

try:
    with open("三国演义_词频.txt", "w") as f:
        for k, v in word_frequency[:20]:
            f.write(f"{k:<10}{v:>5}\n")
except FileNotFoundError:
    print("无法打开指定的文件!")
    exit(0)
except LookupError:
    print("指定了未知的编码!")
    exit(0)
except UnicodeDecodeError:
    print("读取文件时解码错误!")
    exit(0)
except IOError:
    print("写入文件出错")
    exit(0)
else:
    print("写入文件成功")

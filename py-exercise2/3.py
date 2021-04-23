import re

sentences = []
pattern = re.compile(r"[A-Za-z]+")

while True:
    try:
        sentences.append(input())
    except EOFError:
        break
words = []
for sentence in sentences:
    words.extend(pattern.findall(sentence))
print(f"最长的单词长度是：{max(len(i) for i in words)}")

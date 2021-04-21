import re
import requests

book_data = []

headers = {
    'Connection': 'keep-alive',
    'Cache-Control': 'max-age=0',
    'sec-ch-ua': '" Not A;Brand";v="99", "Chromium";v="90", "Microsoft Edge";v="90"',
    'sec-ch-ua-mobile': '?0',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.72 Safari/537.36 Edg/90.0.818.42',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'Sec-Fetch-Site': 'none',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-User': '?1',
    'Sec-Fetch-Dest': 'document',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
}

title_pat = re.compile(r'(?<=&#34; title=").*?(?=")')
author_pat = re.compile(r'(?<=<p class="pl">).*?(?=/)')


print("Catch Start...")
for start in range(0,250,25):
    url = f"https://book.douban.com/top250?start={start}"
    page = requests.get(url, headers=headers)
    page.encoding = "utf-8"
    text = page.text

    title_it = title_pat.finditer(text)
    author_it = author_pat.finditer(text)
    for t, a in zip(title_it, author_it):
        title = t.group()
        author = "_".join(a.group().split())
        print(f"Book Found: Title: {title} Author:{author}")
        book_data.append({"title": title, "author": author})

with open("book_data.txt", "w") as f:
    for i in book_data:
        f.write(f"{i['author']} 《{i['title']}》\n")

print("Done.")

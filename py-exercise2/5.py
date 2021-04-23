import numpy as np

scores = {"012": (90, 94, 97, 86, 85, 89, 88, 85),
          "005": (91, 91, 92, 98, 90, 96, 90, 95),
          "108": (96, 86, 97, 96, 87, 86, 86, 96),
          "037": (95, 95, 94, 93, 97, 98, 99, 95),
          "066": (95, 87, 94, 94, 93, 99, 96, 97),
          "020": (89, 97, 91, 95, 89, 94, 97, 92)}

scores_final = {}
for k, v in scores.items():
    score_p = sorted(v)
    scores_final[k] = np.mean(score_p[1:-1])
scores_final = list(scores_final.items())
scores_final.sort(key=lambda x:x[1], reverse=True)

for no, score in scores_final:
    print(f"选手编号：{no}, 得分：{score:.2f}")

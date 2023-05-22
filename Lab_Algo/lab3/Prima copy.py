
import math


def get_min(R, U):
    rm = (math.inf, -1, -1)
    for v in U:
        rr = min(R, key=lambda x: x[0] if (x[1] == v or x[2] == v) and (
            x[1] not in U or x[2] not in U) else math.inf)
        if rm[0] > rr[0]:
            rm = rr

    return rm


# довжина, вершина 1, вершина 2)
R = [(math.inf, -1, -1), (4, 1, 2), (8, 1, 8), (8, 2, 3), (11, 2, 8), (7, 3, 4),
     (9, 4, 5), (10, 5, 6), (14, 4, 6), (4, 3, 6), (2, 7, 6), (1, 8, 7), (7, 8, 9), (2, 9, 3), (6, 9, 7), ]

N = 9     # число вершин в графі
U = {1}  
T = []    # список ребер кістка

while len(U) < N:
    r = get_min(R, U)       # ребро с минимальным весом
    if r[0] == math.inf:    # если ребер нет, то остов построен
        break

    T.append(r)             # добавляем ребро в остов
    U.add(r[1])             # добавляем вершины в множество U
    U.add(r[2])

print(T)

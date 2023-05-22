# R = [(4, 1, 2), (8, 1, 8), (8, 2, 3), (11, 2, 8), (7, 3, 4),
#      (9, 4, 5), (10, 5, 6), (14, 4, 6), (4, 3, 6), (2, 7, 6), (1, 8, 7), (7, 8, 9), (2, 9, 3), (6, 9, 7), ]

# Rs = sorted(R, key=lambda x: x[0])
# U = set()   
# D = {}     
# T = []      

# for r in Rs:
#     if r[1] not in U or r[2] not in U:  
#         if r[1] not in U and r[2] not in U:  
          
#             D[r[1]] = [r[1], r[2]]
            
#             D[r[2]] = D[r[1]]
#         else:                           
#             if not D.get(r[1]):             
#                 D[r[2]].append(r[1])        
                
#                 D[r[1]] = D[r[2]]
#             else:
               
#                 D[r[1]].append(r[2])
#                 D[r[2]] = D[r[1]]

#         T.append(r)             
#         U.add(r[1])             
#         U.add(r[2])

# for r in Rs:    
#     if r[2] not in D[r[1]]:     
#         T.append(r)             
#         gr1 = D[r[1]]
#         D[r[1]] += D[r[2]]      
#         D[r[2]] += gr1

# print(T)

R = [(4, 1, 2), (8, 1, 8), (8, 2, 3), (11, 2, 8), (7, 3, 4),
     (9, 4, 5), (10, 5, 6), (14, 4, 6), (4, 3, 6), (2, 7, 6), (1, 8, 7), (7, 8, 9), (2, 9, 3), (6, 9, 7)]

Rs = sorted(R, key=lambda x: x[0])
D = {i: [i] for r in Rs for i in r[1:]}
T = []

for r in Rs:
    if D[r[1]] != D[r[2]]:
        T.append(r)
        gr1, gr2 = D[r[1]], D[r[2]]
        for i in gr2:
            gr1.append(i)
            D[i] = gr1

print(T)

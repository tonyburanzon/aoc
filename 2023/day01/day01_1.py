inp = open("input", "r")

lines = inp.readlines()
codes = []
for line in lines:
    firstNum = 0
    lastNum = 0
    for i in line:
        if i.isdigit(): 
            firstNum = int(i)
            break
    for i in line[::-1]:
        if i.isdigit(): 
            lastNum = int(i)
            break
    codes.append([firstNum, lastNum])

sum = 0
for code in codes:
    sum += (code[0] * 10) + code[1]

print(sum)


elvesCals = []
inp = open("input", "r")

lines = inp.readlines()

calCount = 0

for line in lines:
    if line.strip() == "":
        elvesCals.append(calCount)
        calCount = 0
    else:
        calCount += int(line.strip())

elvesCals.sort(reverse=True)

print(elvesCals)
top3 = elvesCals[0] + elvesCals[1] + elvesCals[2]

print(top3)

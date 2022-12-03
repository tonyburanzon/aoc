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

print(max(elvesCals))


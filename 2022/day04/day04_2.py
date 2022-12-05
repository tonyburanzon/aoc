input = open("input", "r")

lines = input.readlines()

def doesOverlap(lLow, lHigh, rLow, rHigh):
    return (int(lLow) <= int(rLow) and int(lHigh) >= int(rLow)) or (int(rLow) <= int(lLow) and int(rHigh) >= int(lLow))

count = 0
for line in lines:
    line = line.strip()
    lSection, rSection = line.split(",")
    lLow, lHigh = lSection.split("-")
    rLow, rHigh = rSection.split("-")
    
    overlap = doesOverlap(lLow, lHigh, rLow, rHigh)

    if overlap:
        count += 1


print(count)

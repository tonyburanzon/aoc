input = open("input", "r")

lines = input.readlines()

def doesEncapsulate(lLow, lHigh, rLow, rHigh):
    return (int(lLow) <= int(rLow) and int(lHigh) >= int(rHigh)) or (int(rLow) <= int(lLow) and int(rHigh) >= int(lHigh))

count = 0
for line in lines:
    line = line.strip()
    lSection, rSection = line.split(",")
    lLow, lHigh = lSection.split("-")
    rLow, rHigh = rSection.split("-")
    
    encap = doesEncapsulate(lLow, lHigh, rLow, rHigh)

    if encap:
        count += 1


print(count)

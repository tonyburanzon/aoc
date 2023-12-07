inp = open("input", "r")
#inp = open("tempInp", "r")

numbers = {
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9
        }

def findNumStr(string: str, reverse: bool):
    for num in numbers:
        if string[0:len(num)] == (num if not reverse else num[::-1]):
            return numbers[num]
    return 0

lines = inp.readlines()
codes = []

for line in lines:
    firstNum = 0
    lastNum = 0

    for i in range(len(line)):
        if line[i].isdigit(): 
            firstNum = int(line[i])
            break
        elif findNumStr(line[i:], False):
            firstNum = findNumStr(line[i:], False)
            break

    revLine = line[::-1] 
    for i in range(len(revLine)):
        if revLine[i].isdigit(): 
            lastNum = int(revLine[i])
            break
        elif findNumStr(revLine[i:], True):
            lastNum = findNumStr(revLine[i:], True)
            break
    codes.append([firstNum, lastNum])

sum = 0
for code in codes:
    sum += (code[0] * 10) + code[1]

print(sum)

def findMatch(sack1, sack2, sack3):
    s1Letters = [0 for i in range(122)]
    s2Letters = [0 for i in range(122)]
    s3Letters = [0 for i in range(122)]

    for letter in sack1:
        s1Letters[ord(letter) - ord('A')] += 1
   
    for letter in sack2:
        s2Letters[ord(letter) - ord('A')] += 1

    for letter in sack3:
        s3Letters[ord(letter) - ord('A')] += 1

    for i in range(len(s1Letters)):
        if s1Letters[i] and s2Letters[i] and s3Letters[i]:
            return (chr(i + ord('A')))
       
def letterPoints(letter):
    if ord(letter) < ord('a'):
        return ord(letter) - ord('A') + 26 + 1
    else:
        return ord(letter) - ord('a') + 1

input = open("test_input", "r")

lines = input.readlines()

print(type(lines))

total = 0
groups = lines[::3]
print(groups)
"""
for line in lines: 
    line = line.strip()
    totChars = int(len(line)/2)
    lSide = line[:totChars]
    rSide = line[totChars:]

    matchedLetter = findMatch(lSide, rSide)
    total += letterPoints(matchedLetter)

print(total)
"""

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

input = open("input", "r")

lines = input.readlines()

numGroups = int(len(lines) / 3)
groups = [lines[i*3:i*3+3] for i in range(numGroups)]

total = 0
for group in groups:
    matchedLetter = findMatch(group[0].strip(), group[1].strip(), group[2].strip())
    total += letterPoints(matchedLetter)

print(total)

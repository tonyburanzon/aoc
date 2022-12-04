input = open("input", "r")

lines = input.readlines()

def findMatch(lSide, rSide):
    rLetters = [0 for i in range(122)]
    lLetters = [0 for i in range(122)]

    for letter in rSide:
        rLetters[ord(letter) - ord('A')] += 1
   
    
    for letter in lSide:
        lLetters[ord(letter) - ord('A')] += 1


    for i in range(len(rLetters)):
        if rLetters[i] and lLetters[i]:
            return (chr(i + ord('A')))
       
def letterPoints(letter):
    if ord(letter) < ord('a'):
        return ord(letter) - ord('A') + 26 + 1
    else:
        return ord(letter) - ord('a') + 1

total = 0
for line in lines: 
    line = line.strip()
    totChars = int(len(line)/2)
    lSide = line[:totChars]
    rSide = line[totChars:]

    matchedLetter = findMatch(lSide, rSide)
    total += letterPoints(matchedLetter)

print(total)

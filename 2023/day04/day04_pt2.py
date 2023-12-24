import re

inp = open("input", "r")
lines = inp.readlines()

def findMatchesCount(str1, str2):
    count = 0
    for item1 in str1:
        for item2 in str2:
            if item1 == item2:
                count += 1
    return count

cards = {}
games = []
for line in lines:
    cardNum = int(line.strip().split(":")[0].strip().split()[1])
    print(cardNum)
    card = line.strip().split(":")[1]
    gameSplit = card.strip().split("|")
    winningNums = re.findall(r'\d+', gameSplit[0])
    playerNums = re.findall(r'\d+', gameSplit[1])
    cards[cardNum] = card

totalScore = 0
for game in cards:
    gameSplit = game.strip().split("|")
    winningNums = re.findall(r'\d+', gameSplit[0])
    playerNums = re.findall(r'\d+', gameSplit[1])
    matches = findMatchesCount(winningNums, playerNums)
    if matches > 0:
        totalScore += 2**(matches-1)
print(totalScore)

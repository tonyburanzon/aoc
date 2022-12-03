WIN = 6
DRAW = 3
LOSS = 0

ROCK = 1
PAPER = 2
SCISSORS = 3

def turnPoints(move):
    match move:
        case 'X':
            return LOSS
        case 'Y':
            return DRAW
        case 'Z':
            return WIN


def play(lMove, outcome):
    match lMove:
        case 'A':
            if outcome == 'X':
                return SCISSORS 
            elif outcome == 'Y':
                return ROCK
            else:
                return PAPER
        
        case 'B':
            if outcome == 'X':
                return ROCK 
            elif outcome == 'Y':
                return PAPER
            else:
                return SCISSORS
        
        case 'C':
            if outcome == 'X':
                return PAPER
            elif outcome == 'Y':
                return SCISSORS
            else:
                return ROCK



inp = open("input","r")

lines = inp.readlines()

totScore = 0


for line in lines:
    lMove, rMove = line.strip().split()
    totScore += play(lMove, rMove) + turnPoints(rMove) 

print(totScore)

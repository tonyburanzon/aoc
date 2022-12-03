WIN = 6
DRAW = 3
LOSS = 0

def turnPoints(move):
    match move:
        case 'X':
            return 1
        case 'Y':
            return 2
        case 'Z':
            return 3


def play(lMove, rMove):
    match lMove:
        case 'A':
            if rMove == 'X':
                return DRAW
            elif rMove == 'Y':
                return WIN
            else:
                return LOSS
        
        case 'B':
            if rMove == 'X':
                return LOSS
            elif rMove == 'Y':
                return DRAW
            else:
                return WIN
        
        case 'C':
            if rMove == 'X':
                return WIN
            elif rMove == 'Y':
                return LOSS
            else:
                return DRAW



inp = open("input","r")

lines = inp.readlines()

totScore = 0


for line in lines:
    lMove, rMove = line.strip().split()
    totScore += play(lMove, rMove) + turnPoints(rMove) 

print(totScore)

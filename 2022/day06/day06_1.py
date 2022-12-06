input = open("input", "r")

buffer = input.readline().strip()

def isUnique(buffer):
    if len(buffer) == 1:
        return True

    curLetter = buffer.pop()
    for letter in buffer:
        if curLetter == letter:
            return False
    return isUnique(buffer)

for index in range(4,len(buffer)):
    marker = [i for i in buffer[index-4:index]]
    if isUnique(marker):
        print(index)
        break


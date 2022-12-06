input = open("input", "r")

buffer = input.readline().strip()

MARKER_LEN = 14
def isUnique(buffer):
    if len(buffer) == 1:
        return True

    curLetter = buffer.pop()
    for letter in buffer:
        if curLetter == letter:
            return False
    return isUnique(buffer)

for index in range(MARKER_LEN,len(buffer)):
    marker = [i for i in buffer[index-MARKER_LEN:index]]
    if isUnique(marker):
        print(index)
        break


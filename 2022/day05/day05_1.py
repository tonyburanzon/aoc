input = open("new_input", "r")

stacks = [[] for i in range(9)]

lines = input.readlines()

for i in range(9):
    line = lines[i].strip()
    for crate in line:
        stacks[i].append(crate)

for i in range(10,len(lines)):
    inst = lines[i].strip().split()
    numCrates = int(inst[1])
    fromStack = int(inst[3]) - 1
    toStack = int(inst[5]) - 1

    for j in range(numCrates):
        stacks[toStack].append(stacks[fromStack].pop())

message = ""
for i in range(len(stacks)):
   message += stacks[i].pop()

print(message)

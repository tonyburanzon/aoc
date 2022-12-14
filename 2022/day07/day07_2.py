class Directory:
    def __init__(self, name, parentDirectory = None):
       self.name = name
       self.fileList = []
       self.dirList = []
       self.parentDirectory = parentDirectory

    def __str__(self):
        print(self.dirList)
        print(self.fileList)

    def addDirectory(self, dirName):
        self.dirList.append(Directory(dirName, self))

    def addFile(self, fileName, size):
        self.fileList.append((fileName, size))

    def getDirectory(self, dirName):
        for dir in self.dirList:
            if dir.name == dirName:
                return dir

    def sumDirectorySize(self):
        dirList = [dir for dir in self.dirList]
        totFileSize = 0
        for file in self.fileList:
            totFileSize += file[1]

        for dir in dirList:
            totFileSize += dir.sumDirectorySize()

        return totFileSize



    
def readLine(command, currDirectory):
    match command[0]:
        case "$":
            #this is a new command
            match command[1]:
                case "cd":
                    dirName = command[2]
                    if dirName == "..":
                        currDirectory = currDirectory.parentDirectory
                    else:
                        currDirectory = currDirectory.getDirectory(dirName)

                    
        case "dir":
            #Add the directory to the current buff list
            dirName = command[1]
            currDirectory.addDirectory(dirName)

        case _:
            #Add the file to the current buff list
            size = int(command[0])
            fileName = command[1]
            currDirectory.addFile(fileName, size)

    return currDirectory


input = open("input", "r")

lines = input.readlines() 

currDirectory = Directory("/")
root = currDirectory

lines.pop(0)

for line in lines:
    line = line.strip().split()
    currDirectory = readLine(line, currDirectory)

dirList = [root]

totDiskSpace = 70000000
diskSpaceNeeded = 30000000
totDiskUsed = root.sumDirectorySize()

sizeToDelete = diskSpaceNeeded - (totDiskSpace - totDiskUsed)


possibleDeleteDirs = []
for dir in dirList:
    for dir2 in dir.dirList:
        dirList.append(dir2)
    if dir.sumDirectorySize() >= sizeToDelete:
        possibleDeleteDirs.append(dir)

tempDir = possibleDeleteDirs.pop()
lowest = tempDir.sumDirectorySize()

for dir in possibleDeleteDirs:
    if dir.sumDirectorySize() < lowest:
        lowest = (dir.sumDirectorySize())

print(lowest)

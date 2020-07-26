

class Recorder:
    def __init__(self):
        self.savedCode = []
        self.preCodeId = ''

        self.folder = 'submission/'
        self.savedCodeFileName = 'savedCode.txt'
        self.previousCodeIdFile = 'preCodeId.txt'

        self.__readSavedCodeList()
        self.__readCodeId()

    def __readCodeId(self):
        try:
            file = open(self.folder + self.previousCodeIdFile, 'r')
            self.preCodeId = file.read()
            file.close()
        except FileNotFoundError:
            print(self.previousCodeIdFile + " haven't been created")

    def __storeCodeId(self, id: str):
        file = open(self.folder + self.previousCodeIdFile, 'w')
        file.write(id)
        file.close()

    def __readSavedCodeList(self):
        try:
            file = open(self.folder + self.savedCodeFileName, 'r')
            content = file.read()
            self.savedCode = content.split('|')
            file.close()
        except FileNotFoundError:
            print(self.savedCodeFileName + " haven't been created")

    def __storeSavedCodeList(self):
        file = open(self.folder + self.savedCodeFileName, 'w')
        for proName in self.savedCode:
            file.write(proName + '|')
        file.close()

    def record(self, code: str, problemName: str):
        if not self.checkExist(problemName):
            pName = problemName.replace(' ', '_')
            file = open(self.folder + pName + '.txt', 'w')
            file.write(code)
            file.close()
            self.savedCode.append(problemName)
        else:
            print(problemName + " is already exist")

    def checkExist(self, problemName: str):
        return problemName in self.savedCode

    def saveAll(self):
        self.__storeSavedCodeList()


if __name__ == '__main__':
    recorder = Recorder()
    print(recorder.savedCode)
    print(recorder.preCodeId)

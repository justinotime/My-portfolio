import random
import math

def insertBin(myList):
    for i in range(0,8):
        myList.append(random.randint(0,1))

   
    
def getBin(myList):
    print(myList)
    
def getDecimal(myList):
    decimal = 0
    back_MyList = myList[::-1]
    for i in range(0, len(back_MyList)):
        if (back_MyList[i] == 1):
            decimal += 2 ** i
    print(decimal)       

def main():
    myList = []
    insertBin(myList)
    getBin(myList)
    getDecimal(myList)

    
    




if __name__ == "__main__":
    main()
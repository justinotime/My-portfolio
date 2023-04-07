import random
# Create Condition for head and tails
coin = ['heads', 'tails']

# Give the player the choice to decide on how many flips do they want.
enterGame = 1
while (enterGame == 1):
    YesNo = input("Would you like to play?: ")
    if (YesNo == "Yes"):
        continue
    elif (YesNo == "No"):
        enterGame = 0


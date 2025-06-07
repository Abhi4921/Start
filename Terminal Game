import random

print("Welcome to Castle Adventure!\n")
print("You are an adventurer in the medieval times on the quest to find the treasure.\n")
print("You're quest is to find the treasure guarded by the ancient creature!\n")
print("Find the treasure and claim it after defeating the dragon!\n")
name = input("Enter your character name: ")
gender = input("Enter gender of your character: ")
#Basic info obtained
atk = blk = heal = spl = 0
print("\n")
if(gender.lower() == "male"):
    print("Name : ",name)
    print("Gender : ",gender)
    print("Pick character:")
    print("Knight Abilities: \n" \
    "Special Ability: Increase 5 points to attack ability!\n"
    "Attack : 30 points\n" \
    "Block : 12 points\n" \
    "Healing : 10 points\n")
    print("Peasant Abiities: \n" \
    "Special Ability: Increase 10 points to block ability!\n"
    "Attack : 15 points\n"
    "Block : 25 points\n"
    "Healing : 20 points\n")
    ans1 = int(input("Enter 1 for Knight or 2 for Peasant "))
    if(ans1 == 1):
        print("Congraluations! You chose Knight!\n")
        chr = "Knight"
        atk = 30
        blk = 12
        heal = 10
        spl = 5
    elif(ans1 == 2):
        print("Congraluations! You chose Peasant!\n")
        chr = "Peasant"
        atk = 15
        blk = 25
        heal = 20 
        spl = 10
elif(gender.lower() == "female"):
    print("Name : ",name)
    print("Gender : ",gender)
    print("Pick character:")
    print("Fairy Abilities: \n" \
    "Special Ability: Increase 10 points to heal ability!\n"
    "Attack : 15 points\n" \
    "Block : 15 points\n" \
    "Healing : 25 points\n")
    print("Princess Abilites: \n" \
    "Special Ability: Increase 5 points to attack ability!\n"
    "Attack : 30 points\n" \
    "Block : 5 points\n" \
    "Healing : 15 points\n")
    ans2 = int(input("Enter 3 for Fairy or 4 for Princess "))
    if(ans2 == 3):
        print("Congraluations! You chose Fairy!\n")
        chr = "Fairy"
        atk = 15
        blk = 15
        heal = 25
        spl = 10
    else:
        print("Congraluations! You chose Princess!\n")
        chr = "Princess"
        atk = 30
        blk = 5 
        heal = 15
        spl = 5
else:
    print("Wrong input!")
    raise Exception("Gender has to be male or female")

print("You can hear the rumbling and the earth starts shaking.\n")
print("A big red dragon arrives on spot breathing fire throught it's nostrils.\n")
npcatk = random.randrange(10,25)
print("Dragon attack: " ,npcatk)
npcatk1 = npcatk
print("You have a HP of 100 \n")
print("You stand you're ground and get ready to fight it.Good luck adventurer!\n") 
hp = npchp = 100
fight = input("Start fight? ")

if(fight.lower() == "yes"):
    while(hp > 0 and npchp > 0):
        print("Your turn! \n")
        move = int(input("Enter 1 for attack , 2 for block , 3 to heal or 4 to use special move! "))
        print("\n")
        if(move == 1):
            print("You attack!\n")
            print("Dragon loses" , atk , "HP!\n")
            npchp -= atk
            print("Dragon attacks!\n")
            print("You lose" , npcatk , "HP!\n")
            hp -= npcatk
            if(hp > 100):
                hp = 100
            if(hp < 0):
                    hp = 0
            elif(npchp < 0):
                    npchp = 0
            print("Player HP: ",hp)
            print("Dragon HP: ",npchp)
        elif(move == 2):
            print("Dragon attacks!\n")
            print("You block Dragon's attack!\n")
            if(blk >= npcatk1):
                npcatk1 = 0
            else:
                npcatk1 -= blk
            print("You sustain damage of" , npcatk1 , "HP!\n")
            hp -= npcatk1
            if(hp < 0):
                    hp = 0
            elif(npchp < 0):
                    npchp = 0
            print("Player HP: ",hp)
            print("Dragon HP: ",npchp)
        elif(move == 3):
            print("Dragon attacks!\n")
            hp -= npcatk
            print("You sustain damage of" , npcatk , " HP!\n")
            print("You heal yourself by" , heal , "HP!\n")
            hp += heal
            if(hp > 100):
                hp = 100
            if(hp < 0):
                    hp = 0
            elif(npchp < 0):
                    npchp = 0
            print("Player HP: ",hp)
            print("Dragon HP: ",npchp)
        elif(move == 4):
            print("You used special move!\n")
            if(chr == "Knight"):
                atk += spl
                print("Attack is increased by " , spl , "points!\n")
                print("You attack Dragon!\n")
                npchp -= atk
                print("Dragon sustains damage of " , atk , "HP!\n")
                print("Dragon attacks you!")
                hp -= npcatk
                print("You sustain damage of " , npcatk , "HP!\n")
                if(hp > 100):
                 hp = 100
                if(hp < 0):
                    hp = 0
                elif(npchp < 0):
                    npchp = 0
                print("Player HP: ",hp)
                print("Dragon HP: ",npchp)
            elif(chr == "Peasant"):
                blk += spl
                print("Block is increased by " , spl , "points!\n")
                if(blk >= npcatk1):
                    npcatk1 = 0
                else:
                    npcatk1 -= blk
                print("Dragon attacks!\n")
                hp -= npcatk1
                print("You sustain damage of " , npcatk1 , " HP!\n")
                if(hp < 0):
                    hp = 0
                elif(npchp < 0):
                    npchp = 0
                print("Player HP: ",hp)
                print("Dragon HP: ",npchp)
            elif(chr == "Fairy"):
                heal += spl
                print("Healing is increased by " , spl , " points!\n")
                print("Dragon attacks!\n")
                hp -= npcatk
                print("You sustain a damage of " , npcatk , " HP!\n")
                hp += heal
                print("You heal yourself by " , heal , " HP!\n")
                if(hp > 100):
                 hp = 100
                if(hp < 0):
                    hp = 0
                elif(npchp < 0):
                    npchp = 0
                print("Player HP: ",hp)
                print("Dragon HP: ",npchp)
            elif(chr == "Princess"):
                atk += spl
                print("Attack is increased by " , spl , "points!\n")
                print("Dragon attacks!\n")
                hp -= npcatk
                print("You sustain damage of " , npcatk , "HP!\n")
                print("You attack Dragon!\n")
                npchp -= atk
                print("Dragon sustains damage of " , atk , "HP!\n")
                if(hp < 0):
                    hp = 0
                elif(npchp < 0):
                    npchp = 0
                print("Player HP: ",hp)
                print("Dragon HP: ",npchp)
    if(hp <= 0):
        print("You lost! \n")
    elif(npchp <= 0):
        print("You won! \n")
    else:
        print("Result undetermined")
elif(fight.lower() == "no"):
    print("Exiting Game!")
    exit()
else:
    print("Wrong input!")
    raise Exception("Type in yes or no only")

# Parent Class
class villain:
    # Initialize Each Villain With Attributes Health and Energy
    def __init__(self, health, energy):
        self.health = health
        self.energy = energy

    # Method To Prompt User To Choose A Weapon or Shield
    def choose_action(self):
        action = int(input("1 for Weapon\n2 for Shield\n"))
        if action == 1:
            return "Attack"
        elif action == 2:
            return "Defend"

    # Method To Convert Number Entered By User When Prompted To choose A Weapon And Return The Weapon Chosen
    def convert_weapon(self, player, n):
        if n == 1:
            return player.w1
        elif n == 2:
            return player.w2
        elif n == 3:
            return player.w3
        elif n == 4:
            return player.w4

    # Method To Convert Number Entered By User When Prompted To choose A Shield And Return The Shield Chosen
    def convert_shield(self, player, n):
        if n == 1:
            return player.s1
        elif n == 2:
            return player.s2

    # Method To Implement Changes During Each Round Of The Game
    def apply_damage(self, player, opponent, wep, sh):
        # Check For Resources Of Weapon And Shield, Initiate An Error Message If Empty
        if wep.resource <= 0 or sh.resource <= 0:
            print("\"\"\"No Resource Available!\"\"\"")
            return
        # Decrease Energy Of Players
        player.energy -= wep.energy
        opponent.energy -= sh.energy
        # Decrement The Resources Of The Weapon And The Shield
        wep.resource -= 1
        sh.resource -= 1
        # Ignore Shield When Weapon Is Kalman Missile
        if wep.name == "Kalman Missile":
            opponent.health -= wep.damage
        else:
            # Decrease Health Of Opponent Player
            damage = wep.damage
            damage -= (sh.save/100) * damage
            opponent.health -= damage

# Child Class For Class Villain


class weapon(villain):
    # Initialize Each Weapon With Attributes Name, Energy, Damage And Resource
    def __init__(self, name, energy, damage, resource):
        self.name = name
        self.energy = energy
        self.damage = damage
        self.resource = resource

# Child Class For Class Villain


class shield(villain):
    # Initialize Each Shield With Attributes Name, nergy, Save And Resource
    def __init__(self, name, energy, save, resource):
        self.name = name
        self.energy = energy
        self.save = save
        self.resource = resource

# Child Class For Class Villain


class Gru(villain):
    # Inherit Health And Energy from Parent Class
    def __init__(self, health, energy):
        super().__init__(health, energy)
    # Creating Weapons Of Gru
    w1 = weapon("Freeze Gun", 50, 11, 1000)
    w2 = weapon("Electric Prod", 88, 18, 5)
    w3 = weapon("Mega Magnet", 92, 10, 3)
    w4 = weapon("Kalman Missile", 120, 20, 1)

    # Creating Shields Of Gru
    s1 = shield("Energy Projected Barrier Gun", 20, 40, 1000)
    s2 = shield("Selective Permeability", 50, 90, 2)

# Child Class For Class Villain


class Vector(villain):
    # Inherit Health And Energy From Parent Class
    def __init__(self, health, energy):
        super().__init__(health, energy)

    # Creating Weapons Of Vector
    w1 = weapon("Laser Blasters", 40, 8, 1000)
    w2 = weapon("Plasma Grenades", 56, 13, 8)
    w3 = weapon("Sonic Resonance Cannon", 100, 22, 3)

    # Creating Shields Of Vector
    s1 = shield("Energy Net Trap", 15, 32, 1000)
    s2 = shield("Quantum Deflector", 40, 80, 3)

# Child Class Of Class Gru And Class Vector


class Game(Gru, Vector):
    # Initialize Class Game With The Two Players And Round Number
    def __init__(self, villain1, villain2):
        self.villain1 = villain1
        self.villain2 = villain2
        self.round = 1

    # Default Player To Play With
    player = "Gru"

    # Method To Choose Villain To Play With
    def choose_villain(self):
        player = int(input("Enter 1 for Gru\nEnter 2 for Vector\n"))
        if player == 2:
            print("You are Vector!")
            Game.player = "Vector"
        else:
            print("You Are Gru!")

    # Method To Implement The Game
    def play_round(self):
        # Display Round Number
        print("Round", self.round)
        #  User To choose Weapon Or Shield
        action = self.villain1.choose_action()
        # Case Attack ( Player Chose Weapon )
        if action == "Attack":
            if Game.player == "Gru":
                # Prompt Player To Choose Weapon From Gru's Artillery
                print("Choose a weapon(Gru):\n1:", villain1.w1.name, "\n2:", villain1.w2.name, "\n3:", villain1.w3.name, "\n4:", villain1.w4.name)
                # W Store Number Taken From User
                w = int(input())
                # Wep Store Weapon Chosen By User
                wep = self.convert_weapon(villain1, w)
                # Prompt Player To Choose Shield From Vector's Artillery
                print("Choose a shield(Vector):\n1:", villain2.s1.name, "\n2:", villain2.s2.name)
                # D Store Number Taken From User
                d = int(input())
                # Sh Store Shield Chosen By User
                sh = self.convert_shield(villain2, d)
                print("Player chose", wep.name, "\t", "Opponent chose", sh.name)
                self.apply_damage(villain1, villain2, wep, sh)
            elif Game.player == "Vector":
                # Prompt Player To Choose Weapon From Vector's Artillery
                print("Choose a weapon(Vector):\n1:", villain2.w1.name, "\n2:", villain2.w2.name, "\n3:", villain2.w3.name)
                # W Store Number Taken From User
                w = int(input())
                # Wep Store Weapon Chosen By User
                wep = self.convert_weapon(villain2, w)
                # Prompt Player To Choose Shield From Gru's Artillery
                print("Choose a shield(Gru):\n1:", villain1.s1.name, "\n2:", villain1.s2.name)
                # D Store Number Taken From User
                d = int(input())
                # Sh Store Shield Chosen By User
                sh = self.convert_shield(villain1, d)
                print("Player chose", wep.name, "\t", "Opponent chose", sh.name)
                self.apply_damage(villain2, villain1, wep, sh)
        # Case Defend ( Player Chose Shield )
        elif action == "Defend":
            if Game.player == "Gru":
                # Prompt Player To Choose Shield From Gru's Artillery
                print("Choose a shield(Gru):\n1:", villain1.s1.name, "\n2:", villain1.s2.name)
                # D Store Number Taken From User
                d = int(input())
                # Sh Store Shield Chosen By User
                sh = self.convert_shield(villain1, d)
                # Prompt Player To Choose Weapon From Vector's Artillery
                print("Choose a weapon(Vector):\n1:", villain2.w1.name, "\n2:", villain2.w2.name, "\n3:", villain2.w3.name)
                # W Store Number Taken From User
                w = int(input())
                # Wep Store Weapon Chosen By User
                wep = self.convert_weapon(villain2, w)
                print("Player chose", sh.name, "\t", "Opponent chose", wep.name)
                self.apply_damage(villain2, villain1, wep, sh)
            elif Game.player == "Vector":
                # Prompt Player To Choose Shield From Vector's Artillery
                print("Choose a shield(Vector):\n1:", villain2.s1.name, "\n2:", villain2.s2.name)
                # D Store Number Taken From User
                d = int(input())
                # Sh Store Shield Chosen By User
                sh = self.convert_shield(villain2, d)
                # Prompt Player To Choose Weapon From Vector's Artillery
                print("Choose a weapon(Gru):\n1:", villain1.w1.name, "\n2:", villain1.w2.name, "\n3:", villain1.w3.name, "\n4:", villain1.w4.name)
                # W Store Number Taken From User
                w = int(input())
                # Wep Store Weapon Chosen By User
                wep = self.convert_weapon(villain1, w)
                # Display Choices Of Players
                print("Player chose", sh.name, "\t", "Opponent chose", wep.name)
                # Implement Changes in Players' Attributes And Weapon And Shield Resources
                self.apply_damage(villain1, villain2, wep, sh)
        # Display Stats Of Players
        if Game.player == "Gru":
            print("Your Health:", villain1.health)
            print("Your Energy:", villain1.energy)
            print("Opponent Health:", villain2.health)
            print("Opponent Energy:", villain2.energy)
        else:
            print("Your Health:", villain2.health)
            print("Your Energy:", villain2.energy)
            print("Opponent Health:", villain1.health)
            print("Opponent Energy:", villain1.energy)
        # Increment Round Number
        self.round += 1

    # Method To Start The Game
    def start_game(self):
        while villain1.health > 0 and villain1.energy > 0 and villain2.health > 0 and villain2.energy > 0:
            self.play_round()
        winner = "Gru" if villain2.health <= 0 or villain2.energy <= 0 else "Vector"
        # Display Winner
        print(winner, "wins the game!")


# Initializing 2 Players
villain1 = Gru(100, 500)
villain2 = Vector(100, 500)
game = Game(villain1, villain2)
# Choose Which Villain To Play With
Game.choose_villain(game)
# Start Game
game.start_game()

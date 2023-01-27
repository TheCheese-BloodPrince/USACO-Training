"""
ID: karasia1
LANG: PYTHON3
PROG: gift1
"""
fin = open ('gift1.in', 'r')
finlines = fin.readlines()
fin.close()

bank = dict()
for i in range(1,int(finlines[0])+2):
    bank[finlines[i]] = 0
finlines = finlines[int(finlines[0])+1:]

class Instruction:
    def __init__(self, giver: str, money: int, numPeople: int, people: list):
        self.giver = giver
        self.money = money
        self.numPeople = numPeople
        self.people = people
instructions = list()
while len(finlines)>0:
    people = int(finlines[1].split()[1])
    instruction = finlines[:people+2]
    finlines = finlines[people+2:]
    instructions.append(Instruction(instruction[0], int(instruction[1].split()[0]), people, instruction[2:]))

for i in instructions:
    if i.money==0: continue
    gift = i.money//i.numPeople
    for j in i.people:
        bank[j] += gift
    bank[i.giver] -= gift*i.numPeople

out = list()
for i in bank:
    j = i.strip() + " " + str(bank[i]) + '\n'
    out.append(j)
print(out)

fout = open ('gift1.out', 'w')
fout.writelines(out)
fout.close()
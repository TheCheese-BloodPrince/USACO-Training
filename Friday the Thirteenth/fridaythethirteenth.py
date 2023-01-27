"""
ID: karasia1
LANG: PYTHON3
PROG: friday
"""
fin = open ('friday.in', 'r')
fout = open ('friday.out', 'w')
x = int(fin.readline())
fin.close()

daysPerMonth = [31,28,31,30,31,30,31,31,30,31,30,31]
LEAPdaysPerMonth = [31,29,31,30,31,30,31,31,30,31,30,31]
days = [0]*7
day = 0
year = 0

for i in range(x):
    print(i)
    if ((i+1900)%4==0 and not (i+1900)%100==0):
        for month in range(12):
            for j in range(1,LEAPdaysPerMonth[month]+1):
                if j==13:
                    days[day] += 1
                if day==6:
                    day=0
                else:
                    day += 1
        year += 1
    else:
        for month in range(12):
            for j in range(1,daysPerMonth[month]+1):
                if j==13:
                    days[day] += 1
                if day==6:
                    day=0
                else:
                    day += 1
        year += 1

print(days)

fout.write (str(days) + '\n')
fout.close()
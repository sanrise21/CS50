from sys import argv,exit
import csv
import re
import numpy as np

def max_occurrences( substring, full_string ):
    pattern = "(?=((" + re.escape(substring) + ")+))"
    matches = re.findall( pattern, full_string )
    return max( len( m[0] ) // len( substring ) for m in matches )










if(len(argv) != 3):
    print("Usage: python dna.py data.csv sequence.txt")

match =list()
match2 = list()
match3=list()


f = open(argv[2],'r')
txt = f.read()
#print(txt)
flag=0

with open(argv[1]) as read:
    csvf = csv.reader(read)
   # next(csvf)
    #for column in csvf:
    #get column headings
    i = next(csvf)
    #print(i)
    total = len(i) - 1
    data = list(csvf)
    #print("The data is")
   # print(data)
    #print(data[0][1])
    #print("the len of data" + str(len(data)))


    #get column headings from 1 position
    #for j in range(1,len(i)):

        #print(i[j])


    #final loop
    for j in range(1,total+1):
        a = max_occurrences(i[j],txt)
        match.append(a)
        #print(a)



    for k in range(0,len(data)):
        for j in range(1,len(i)):
            match2.append(int(data[k][j]))
       # print(match2)
        #match3 = match2
        if(match == match2):
            print(data[k][0])
            flag = 1
            break;

        match2=list()
   # print(match3)
    if flag == 0:
       print("No match")



    #data = np.loadtxt(argv[1],dtype=np.str,delimiter=',',skiprows=0)
    #names = data.name.tolist()


#print(match)
#print(max_occurrences("AGATC",txt))

















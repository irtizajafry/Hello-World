##For a pattern this code checks what is the face(+/-) at the top/start
#It then checks how many are of same face from the top/start 
#Before the point where the first (opposite face)/(face of different sign) appears, it flips all the faces to the sign of this face. 
#It does that till it reaches end of pattern, when all faces have now the same sign
#It then checks if the signs of faces are + or - and reverts all the signs of faces to make all positive

 
f1 = open("pancake.txt","r")
f2 = open("pancakeResult.txt","w")
line = 0;
##print "hi"
for pattern in f1:
    a = list(pattern)

    count=0;
    if line == 0: # this is to ignore the first line in the file
        line = line + 1
        continue
    boolean = True; # test checks if there is a - in the pattern or not
    i = 0
    if len(a) == 2:
        if a[0] == "-":
            a[0] = "+"
            count = count + 1
    while boolean :
        if ((i+1) < len(a)) and (len(a) > 2):
            if a[i] != a[i+1]:
                count = count + 1
                for idd in xrange(0,i+1):
                    if a[idd] == "+":
                        a[idd] = "-"
                    else:
                        a[idd] = "+"
            i = i + 1  
                      
        if "-" not in a:
            boolean = False
    print >> f2,"CASE # " + str(line) + " : " + str(count)         
    line = line + 1
       
f1.close()
f2.close()
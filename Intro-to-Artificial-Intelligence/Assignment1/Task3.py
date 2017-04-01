# Code checks for each number read from file the number of digits there are in each number and then adds their number to a variable whihc is kept lower than 10 so that the loops contiues until all digits 0-9 are found


f1 = open("sheep.txt","r")
f2 = open("sheepResult.txt","w")
case = 0
for letter in f1: # Loop for reading every line of file separately
    case = case + 1 # case keeps count of lines read
    a = 0 # a for adding the number of single-digit numbers and ensuring their count is less than 10 
    count = 0 # count calculates the number of times a number is multiplied before it gets all the digits appear
    L = list("")
    if case == 1: # As the first number only tells number os numbers below
        continue
    ab = int(letter)    
    if ab == 0: 
        print >> f2,"CASE #" + str(case-1) + " : " + "Insomnia" # For the letter = 0 case  
    else: 
        while a<10: 
            count = count + 1
            m = int(letter) * count 
            n = str(m)
            L = L + list(n)
            for i in xrange(0,10): # Loop checks how many digits are in the number letter
                if str(i) in L:
                    a = a + 1 
            if a < 10: # Just to revert value of a = 0 if it becomes >= 10 as there can be numbers with digits repeated from the previous number 
                a = 0                  
                       
        print >> f2, "CASE # " + str(case-1) + " : " + str(int(letter)*(count))
f1.close()
f2.close()
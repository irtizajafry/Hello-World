def isPrime(x):
    for i in xrange(2,x):
        if x%i == 0:
            return False
    return True

def isPalindrome(x):
    i = 0
    y = (len(x))/2
    z = len(x)-1
    for i in range(0,y):
        if(x[i]!=x[z-i]):
            return False
    return True    

count = 0
num = 2
while count < 20:
    if isPrime(num) and isPalindrome(str(num)):
        print num
        count = count + 1
    num = num + 1
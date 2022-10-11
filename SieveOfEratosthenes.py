# Algorithm of Sieve_Of_Eratosthene in python
def SieveOfEratosthenes(num):
    prime = [True for i in range(num+1)]  # making a boolean array
    p = 2
    while (p * p <= num):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):

            # Updating all multiples of p
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1

    # Printing all prime numbers
    for p in range(2, num+1):
        if prime[p]:
            print(p)


# Driver code
if __name__ == '__main__':
    num = int(input("Enter Number till which you want prime numbers: "))
    print("prime numbers smaller than or equal to", num)
    SieveOfEratosthenes(num)

#Lambda is used as an anonymous function inside another function.
#Tuples are used to store multiple items in a single variable.
#split() is used to spilt the value from input into integer 
#If a, b and c are not exactly 1, then not possible to create a problemset
print((lambda a,b,c,n: 'YES' if a > 0 and b > 0 and c > 0 and a+b+c >= n and n >= 3 else 'NO')(*tuple(map(int, input().split()))))
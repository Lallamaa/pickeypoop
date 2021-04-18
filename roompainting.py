import math #for floor()

#Declare array
paint = []
colour = []
a, b = [int(x) for x in input().split()]

#Insert the input value in paint array
for x in range(a):
    paint.append(int(input()))

#Insert the input value in colour array
for x in range(b):
    colour.append(int(input()))

total = 0
#Calculate the extra value
extra_max = max(paint) + max(colour)

#Sort the array
paint.sort()
colour.sort()

#Binary search function
def binary_search(first,last,target,extra):

    #Return the largest integer less than or equal to 
    middle = math.floor((first+last)/2)

    if middle >= first:

        #Target found in array
        if target == paint[middle]:
            return 0        
        #Calculate the difference between target and middle
        elif (paint[middle]-target) < extra and (paint[middle]-target >= 0):
            extra = abs(target-paint[middle])

        #If target is greater than middle
        if target > paint[middle]:
            return binary_search(middle+1, last, target, extra)
        #Else if target is lesser than middle
        else:
            return binary_search(first, middle-1, target, extra)
    return extra

#Implement the binary search by searching the number in colour as target
for x in colour:
    total += (binary_search(int(0),len(paint)-1,x,extra_max))
print(total) #print total extra

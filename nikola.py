class State(tuple):
    
    #This method will be called when an object is created, class is needed to be instantiated
    def __new__(cls, last, square):
        return tuple.__new__(cls, (last, square))

    #Class function to determine the jump position based on the constraints
    def jump(self, n):
        last, square = self

        #If the jump is in the forward direction
        if square+last+1 <= n:
            #One square longer than the preceding jump
            yield State(last+1,square+last+1)
        
        #If the jump is in the backward direction
        if last > 0 and square-last > 0:
            #Exactly the same length as the preceding jump
            yield State(last, square-last)

def move(state, data):
    memory, n, entryFee = data
    if state[1] == n:
        return 0
    if state not in memory:
        #in case of overflow 
        temp = 2147483647 
        for jump_state in state.jump(n):
            #To find the min entry fee
            temp = min(temp, entryFee[jump_state[1]-1] + move(jump_state, data))
        #Assign the entry fee into memory
        memory[state] = temp
    #Return entry fee
    return memory[state]

#main function
def main():
    #input number of squares
    n = int(input())
    #input cost based on number of squares
    entryFee = [int(input()) for x in range(n)]
    #print entry fee
    print(move(State(0,1), ({}, n, entryFee)))

#main esxecuted when ran directly
if __name__ == "__main__":
    main()
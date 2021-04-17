from collections import defaultdict 

votes = defaultdict(lambda: 0)
while True:
    ppl = input()
    if ppl == '***': #ends the input with ***
        break
    votes[ppl] = votes[ppl] + 1 #count the num of votes for each ppl 
if len(votes.items()) >= 2 or sum(votes.values()) > 1:
    sorted_voted = sorted(list(votes.items()), key=lambda z: z[1], reverse=True) #sort the votes desc order
    if len(sorted_voted) == 1: #when the len ppl == 1 
        print(sorted_voted[0][0])
    elif sorted_voted[0][1] != sorted_voted[1][1]: #num of vote(between 1st and 2nd) not equal
        print(sorted_voted[0][0])
    else:
        print("Runoff!")
else:
    print("Must be at least 2 votes on the list")
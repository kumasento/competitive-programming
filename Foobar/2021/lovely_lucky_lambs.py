import math

def solution(total_lambs):
    # Your code here
    
    if total_lambs == 1:
        return 0
    if total_lambs == 2:
        return 1
        

    min_hire = int(math.log(total_lambs + 1, 2))
    # curr_lambs = 2 ** min_hire - 1
    # remain_lambs = total_lambs - curr_lambs
    # fibs[0] = 2 ** (min_hire - 2)
    # fibs[1] = fibs[0] * 2
    # fibs[2] = fibs[0] + fibs[1]
    # i = 2
    # while fibs[i] <= remain_lambs:
    #     remain_lambs -= fibs[i]
       
    #     min_hire += 1
    #     fibs[i+1] = fibs[i] + fibs[i-1]
        
    #     i += 1
    
    a = 1
    b = 1
    curr_lambs = 2
    max_hire = 2
    i = 3
    while i <= total_lambs:
        c = a + b
        a = b
        b = c

        if total_lambs - curr_lambs < c:
            break
        max_hire += 1
        curr_lambs += c
        i += 1
        
    return max_hire - min_hire

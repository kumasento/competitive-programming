
x = str(raw_input())
ans = ""
start_with_non_zero = False
for c in x:
    i = ord(c) - ord('0')
    reverted = 9 - i
    result = i
    if reverted < i:
        if reverted == 0:
            if start_with_non_zero:
                result = reverted
        else:
            start_with_non_zero = True
            result = reverted
    if result != 0 and start_with_non_zero == False:
        start_with_non_zero = True
    ans += str(result)
print ans

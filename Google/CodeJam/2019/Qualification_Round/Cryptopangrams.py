from __future__ import print_function

import sys
import math

def main():
  T = int(input())
  for t in range(T):
    line = input()
    N = int(line.split()[0])
    L = int(line.split()[1])

    line = input()
    ciphers = [int(n) for n in line.split()]

    gcds = [math.gcd(ciphers[i], ciphers[i+1]) for i in range(L-1)]

    i = 0
    while i < L - 1:
      if gcds[i] != ciphers[i]:
        break
      i += 1

    primes = [0 for _ in range(L + 1)]
    primes[i] = ciphers[i] // gcds[i]
    for j in range(i, L):
      primes[j+1] = ciphers[j] // primes[j]
    for j in reversed(range(1, i+1)):
      primes[j-1] = ciphers[j] // primes[j]

    primeToChar = dict({k: chr(ord('A') + i) for i, k in enumerate(sorted(set(primes)))})
    ans = ""
    for prime in primes:
      ans += primeToChar[prime]
    print("Case #{}: {}".format(t + 1, ans))
    

if __name__ == "__main__":
  main()

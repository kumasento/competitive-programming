def main():
  n = 30000
  is_prime = [ 1 for _ in range(n) ]
  is_prime[0] = 0
  is_prime[1] = 0
  is_prime[2] = 1

  prime = 2
  while prime < n:
    for i in range(prime + 1, n):
      if is_prime[i] and i % prime == 0:
        is_prime[i] = 0
    new_prime = prime
    for i in range(prime + 1, n):
      if is_prime[i]:
        new_prime = i
        break
    if new_prime == prime:
      break
    prime = new_prime

  primes = [ i for i in range(n) if is_prime[i] ] 
  s = ''.join([str(i) for i in primes])
  print(s)
  print(len(s))


if __name__ == '__main__':
  main()


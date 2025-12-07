# brute_force.py
"""
Brute Force Attack on Diffie–Hellman by testing all
possible small private keys.

Usage:
    python3 brute_force.py P G PublicKey max_key
"""

import sys

if len(sys.argv) != 5:
    print("Usage: python3 brute_force.py P G PublicKey max_key")
    sys.exit(1)

P = int(sys.argv[1])
G = int(sys.argv[2])
TargetPublic = int(sys.argv[3])
max_key = int(sys.argv[4])

print(f"[*] Starting Brute Force Attack: P={P}, G={G}, TargetPublic={TargetPublic}, MaxKey={max_key}")

for priv in range(1, max_key + 1):
    pub = pow(G, priv, P)
    if pub == TargetPublic:
        print(f"[+] Found private key: {priv}")
        sys.exit(0)

print("[-] Private key not found in given range.")
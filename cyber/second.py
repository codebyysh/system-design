# dictionary_attack.py
"""
Dictionary Attack on Diffie–Hellman when the private key
is chosen from a weak wordlist or small set of passphrases.

Usage:
    python3 dictionary_attack.py P G PublicKey wordlist.txt
"""

import sys
import hashlib

if len(sys.argv) != 5:
    print("Usage: python3 dictionary_attack.py P G PublicKey wordlist.txt")
    sys.exit(1)

P = int(sys.argv[1])
G = int(sys.argv[2])
TargetPublic = int(sys.argv[3])
wordlist_file = sys.argv[4]

def passphrase_to_private(word):
    """Convert passphrase to integer private key."""
    h = hashlib.sha256(word.encode()).hexdigest()
    return int(h, 16) % P

print(f"[*] Starting Dictionary Attack on DH: P={P}, G={G}, TargetPublic={TargetPublic}")
print(f"[*] Using wordlist: {wordlist_file}")

with open(wordlist_file, "r", encoding="utf-8", errors="ignore") as f:
    for count, word in enumerate(f, start=1):
        word = word.strip()
        if not word:
            continue
        
        # Derive private key
        priv = passphrase_to_private(word)

        # Calculate public key
        pub = pow(G, priv, P)

        # Check match
        if pub == TargetPublic:
            print(f"[+] Found private key: {priv} (passphrase: '{word}')")
            sys.exit(0)

        if count % 1000 == 0:
            print(f"[-] Checked {count} words...")

print("[-] Not found in wordlist.")
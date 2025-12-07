def caesar(text, key, mode='enc'):
    d = 1 if mode == 'enc' else -1
    return ''.join(chr((ord(c)-65+d*key)%26+65) if c.isupper()
                   else chr((ord(c)-97+d*key)%26+97) if c.islower() else c for c in text)

key = 3
plain = "MY NAME IS YASH"
enc = caesar(plain, key, 'enc')
dec = caesar(enc, key, 'dec')
print(f"Key: {key}, Plain: {plain}, Encrypted: {enc}, Decrypted: {dec}")

def caesar_cipher(text, key, mode='enc'):
    d = 1 if mode == 'enc' else -1
    result = ''
    for c in text:
        if c.isupper():
            result += chr((ord(c) - 65 + d * key) % 26 + 65)
        elif c.islower():
            result += chr((ord(c) - 97 + d * key) % 26 + 97)
        else:
            result += c
    return result


def rail_fence_encrypt(text):
    rail1 = text[::2]
    rail2 = text[1::2]
    return rail1 + rail2

def rail_fence_decrypt(cipher):
    half = (len(cipher) + 1) // 2
    rail1 = cipher[:half]
    rail2 = cipher[half:]
    result = ''
    for i in range(half):
        result += rail1[i]
        if i < len(rail2):
            result += rail2[i]
    return result



import math

def row_column_encrypt(text, key):
    num_rows = math.ceil(len(text) / key)
    padded_len = num_rows * key
    text = text.ljust(padded_len)  # pad with spaces

    # Create matrix row-wise
    matrix = [text[i:i+key] for i in range(0, padded_len, key)]
    # Read column-wise
    cipher = ''.join(''.join(row[i] for row in matrix) for i in range(key))
    return cipher

def row_column_decrypt(cipher, key):
    num_rows = math.ceil(len(cipher) / key)
    num_full_cols = len(cipher) % key
    if num_full_cols == 0:
        num_full_cols = key

    matrix = [''] * num_rows
    idx = 0
    for col in range(key):
        for row in range(num_rows):
            if col < num_full_cols or row < num_rows - 1 or col < len(cipher) % key:
                if len(matrix[row]) < key:
                    matrix[row] += cipher[idx]
                    idx += 1

    return ''.join(matrix).rstrip()




if __name__ == "__main__":
    plaintext = input("Enter plaintext: ")
    key = int(input("Enter key (integer for Caesar & Row-Column): "))

    # Caesar Cipher
    caesar_encrypted = caesar_cipher(plaintext, key, 'enc')
    caesar_decrypted = caesar_cipher(caesar_encrypted, key, 'dec')
    print(f"\n[Caesar Cipher]\nEncrypted: {caesar_encrypted}\nDecrypted: {caesar_decrypted}")

    # Rail Fence Cipher (2-Rail)
    rail_encrypted = rail_fence_encrypt(plaintext)
    rail_decrypted = rail_fence_decrypt(rail_encrypted)
    print(f"\n[Rail Fence Cipher]\nEncrypted: {rail_encrypted}\nDecrypted: {rail_decrypted}")

    # Row-Column Cipher
    row_encrypted = row_column_encrypt(plaintext, key)
    row_decrypted = row_column_decrypt(row_encrypted, key)
    print(f"\n[Row-Column Cipher]\nEncrypted: {row_encrypted}\nDecrypted: {row_decrypted}")
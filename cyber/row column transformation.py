def row_column_encrypt(plain, key):
    plain = plain.replace(' ', '').upper()
    klen = len(key)
    while len(plain) % klen:
        plain += 'X'
    rows = [plain[i:i+klen] for i in range(0, len(plain), klen)]
    order = sorted([(k, i) for i, k in enumerate(key)], key=lambda x: (x[0], x[1]))
    col_order = [i for k,i in order]
    return ''.join(''.join(row[i] for row in rows) for i in col_order)




def row_column_decrypt(cipher, key):
    klen = len(key)
    rows_count = len(cipher) // klen
    order = sorted([(k, i) for i, k in enumerate(key)], key=lambda x: (x[0], x[1]))
    col_order = [i for k,i in order]
    # Recreate empty matrix
    matrix = [['']*klen for _ in range(rows_count)]
    idx = 0
    for num, col in enumerate(col_order):
        for row in range(rows_count):
            matrix[row][col] = cipher[idx]
            idx += 1
    return ''.join(''.join(r) for r in matrix).rstrip('X')




plain = "HELLO WORLD! HOW ARE YOU?"
key = "HELLO"

encrypted = row_column_encrypt(plain, key)
decrypted = row_column_decrypt(encrypted, key)

print(f"Key: {key}")
print(f"Plain: {plain}")
print(f"Encrypted: {encrypted}")
print(f"Decrypted: {decrypted}")

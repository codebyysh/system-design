def rail_fence_encrypt(text, rails):
    fence = [[] for _ in range(rails)]
    rail = 0
    direction = 1

    for char in text:
        fence[rail].append(char)
        rail += direction
        if rail == 0 or rail == rails - 1:
            direction *= -1

    return ''.join(''.join(row) for row in fence)




def rail_fence_decrypt(cipher, rails):
    pattern = list(range(rails)) + list(range(rails-2, 0, -1))
    indexes = []
    i = 0
    while len(indexes) < len(cipher):
        indexes.append(pattern[i % len(pattern)])
        i += 1
    pos = [indexes.count(i) for i in range(rails)]
    fence = [[] for _ in range(rails)]
    k = 0
    for r in range(rails):
        for _ in range(pos[r]):
            fence[r].append(cipher[k])
            k += 1
    result = []
    rail_ptrs = [0]*rails
    for r in indexes:
        result.append(fence[r][rail_ptrs[r]])
        rail_ptrs[r] += 1
    return ''.join(result)

# Main program
plain_text = input("Enter plain text: ")
key = int(input("Enter key (number of rails): "))

encrypted = rail_fence_encrypt(plain_text, key)
decrypted = rail_fence_decrypt(encrypted, key)

print("Encrypted message:", encrypted)
print("Decrypted message:", decrypted)

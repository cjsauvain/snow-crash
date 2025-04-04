

try:
    hex_string = input("token: ")
    decoded_string = ""
    for i in range(0, len(hex_string), 2):
        hex_value = hex_string[i:i+2]
        num = int(hex_value, 16)
        index = i // 2
        original_num = (num - (index)) % 177
        decoded_string += chr(original_num)

    print(decoded_string[:-1])
except Exception as e:
    print(e)


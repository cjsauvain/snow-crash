hex_string = "66346b6d6d36707c3d827f70826e838244428344757b7f8c890a"

decoded_string = ""
for i in range(0, len(hex_string), 2):
    hex_value = hex_string[i:i+2]
    num = int(hex_value, 16)
    index = i // 2
    original_num = (num - (index)) % 177
    decoded_string += chr(original_num)

print(decoded_string)


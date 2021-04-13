import png

print("Write name of your PNG file: ", end="")
name = input()

try:
    open(name, 'r')
except:
    print("No such file: " + name)
    exit()

reader = png.Reader(name)
file = reader.read()

width = file[0]
height = file[1]
data = list(file[2])

with open("bin/tmp_file", "w") as res_file:
    res_file.write(str(width) + " ")
    res_file.write(str(width) + "\n")
    for row in data:
        for element in row:
            res_file.write(str(element) + " ")

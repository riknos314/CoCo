import disassembler

def main():
    print(1j * 1j)

    z = 2.345 - 3j
    x = 4 + 2j
    y = -4 -2j
    u = -4-4j

    print(x+z)
    print(x-z)
    print(x*z)
    print(x/z)
    print(x+y)
    print(x+u)
    print(x==y)
    x = y
    print(x==y)
    print(type(x))
    x = complex(1,2)
    y = complex(3,4)
    print(x*y)

#main()
disassembler.disassemble(main)

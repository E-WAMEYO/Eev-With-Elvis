operand = input("num1 :")
operand2 = input("num2 :")
sign = input("sign :")


print(operand, sign, operand2)

if sign == "+":
    result = int(operand) + int(operand2)
    print(result)

elif sign == "-":
    result = int(operand)- int(operand2)
    print(result)


elif sign =="/":
    result = int(operand) / int(operand2)
    print(result)


elif sign =="*":
    result = int(operand) * int(operand2)
    print(result)


elif sign =="%":
    result = int(operand) % int(operand2)
    print(result)

elif sign =="**":
    result = int(operand) ** int(operand2)
    print(result)
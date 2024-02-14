# d = {}
# c = int(input("Enter the number of contacts you want to add:"))
# for i in range(c):
#     name = input("Enter the name:")
#     no = input("Enter the phone number:")
#     d[name] = no
# d = dict(sorted(d.items()))
# print(d)


d = {}
c = " "
while c:
    for i in d:
        print(i, ":", d[i])

    c = input("Enter \n1)add title and number\n2)sell \n3)add\nEnter to exit\n")
    if c == "1":
        name = input("Enter the name:")
        no = int(input("Enter no of copies:"))
        d[name] = no
    if c == "2":
        l = list(d.keys())
        for i in range(0, len(d)):
            print(i, ")", l[i], ":", d[l[i]])

        index = int(input("Enter the index of the book you want to sell: "))
        while index not in range(0, len(d)):
            index = int(input("Enter VALID index of the book you want to sell: "))
        no = input("Enter no of copies(default 1): ")

        while int(no) > d[l[index]]:
            no = int(input("Enter valid possible of copies(default 1): "))
        d[l[index]] -= 1 if not no else int(no)
    if c == "3":
        name = input("Enter the name: ")
        no = int(input("Enter no of copies: "))
        if name in d:
            d[name] += no
        else:
            d[name] = no

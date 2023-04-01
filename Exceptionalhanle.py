#Exceptionall handling in python and finally keyword
def func():
    table = input("Enter the table:\t")
    try:
        for i in range(1, 11):
            print(f"{int(table)} X {i} = {int(table)*i}")
        return 1
    except:
        print("Invalid Input")
        return 0

    finally:
        print("My name is ehtsham")

func()

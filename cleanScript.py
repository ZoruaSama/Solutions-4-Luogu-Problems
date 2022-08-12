import os
lists = os.listdir()
for i in lists:
    fileName = os.path.join(os.path.abspath('.'),i,"cmake-build-debug",i+".exe")
    if os.path.exists(fileName):
        os.remove(fileName)
        print("DELETE",fileName)

input("Well Done.")
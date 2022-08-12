# import requests
# board = input()
# url ="http://www.chessdb.cn/chessdb.php?action=queryall&board=" + board
# res = requests.get(url)
# if "move" in res.text:
#     print(res.text.split(',')[0].split(':')[1])
# else:
#     print("0")

with open('out.txt', 'w') as f:
    f.write('hello world')  #文件的写操作
import time 
for i in range(0,365):
    print("\r","进度百分比：{0}%".format(round((i+1)*100/365)),end="",flush=True)
    time.sleep(0.1)
    
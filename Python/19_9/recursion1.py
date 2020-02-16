import time

def countdown(i):
    i=10
    print(i)
    time.sleep(1)
    countdown(i-1)
    if i<=0:
      return 0

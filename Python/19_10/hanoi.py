def hanoi(n,frm,to,aux):
    if n==1 :
        print("move disk 1 from rod",frm,"to rod",to)
        return
    hanoi(n-1,frm,aux,to)
    print("move disk",n,"from rod",frm,"to rod",to)
    hanoi(n-1,aux,to,frm)

hanoi(4,"a","b","c")
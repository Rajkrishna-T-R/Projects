import time
bank={275386751143:[2091,90982,275386751143,"SISIRA THOMAS",[]],
      306087961523:[1872,58723,306087961523,"SAMUEL CIBI",[]], 286496571098:[8736,70092,286496571098,"RAJKRISHNA T R",[]],
      276846789838:[6354,63242,276846789838,"SREE VISHNU",[]], 304165752987:[5544,69420,304165752987,"AAROMAL B S",[]]}

def withd(x):
    wd=int(input("\nEnter the amount to be withdrawed: "))
    if wd>x[1]:
        print("Sorry insufficient balance available")
    elif wd>20000:
        print("Sorry, Maximum withdrawal limit exceeded")
    else:
        x[1]=x[1]-wd
        print("\nâ‚¹",wd,"withdrawed successfully")
        x[4].append([-wd,x[1]])
    return x[1],x[4]

def deposit(x):                                        
    deposit_money = int(input("\nEnter the amount to be deposited: "))
    if deposit_money>0:
        x[1]=x[1]+deposit_money
        print(f"{deposit_money}  deposited successfully")
        x[4].append([deposit_money,x[1]])       
    else:
        print("Error: Money cannot be negative or zero")
    return x[1],x[4]

def display(x):
    print("*"*100) 
    print('\nSTUDENTS BANK OF INDIA\n')
    print('*'*100)
    print('\nACCOUNT HOLDER : ', x[3])
    print('ACCOUNT NUMBER : ', x[2])
    print('*'*100)

def chk_bal(x):
    print("\nyour current balance is:", x[1])

def trh(x):
    for n in range(len(x[4])):
        print("\nTransaction =",x[4][n][0],"Balance =",x[4][n][1])

while True:
    print("\n\n\nâœ¨âœ¨âœ¨ Welcome to Students Bank of India âœ¨âœ¨âœ¨")
    print("\nPlease insert your ATM card....")
    #raspberrypi things
    p=int(input("Enter your PIN : "))
    if p==bank[275386751143][0]:
        print("\n1 : Cash Withdrawal")
        print("2 : ATM Deposit")
        print("3 : Display of Details")
        print("4 : Balance Enquiry")
        print("5 : Transaction History")
        choice=int(input("\nPlease select an option to continue.... "))
        if choice==1:
            bank[275386751143][1],bank[275386751143][4]=withd(bank[275386751143])
        elif choice==2:
            bank[275386751143][1],bank[275386751143][4]=deposit(bank[275386751143])
        elif choice==3:
            display(bank[275386751143])
        elif choice==4:
            chk_bal(bank[275386751143])
        elif choice==5:
            trh(bank[275386751143])
        else:
            print("invalid choice")
            continue
        time.sleep(5)
    elif p==bank[306087961523][0]:
        
        print("\n1 : Cash Withdrawal")
        print("2 : ATM Deposit")
        print("3 : Display of Details")
        print("4 : Balance Enquiry")
        print("5 : Transaction History")
        choice=int(input("\nPlease select an option to continue.... "))
        if choice==1:
            bank[306087961523][1],bank[306087961523][4]=withd(bank[306087961523])
        elif choice==2:
            bank[306087961523][1],bank[306087961523][4]=deposit(bank[306087961523])
        elif choice==3:
            display(bank[306087961523])
        elif choice==4:
            chk_bal(bank[306087961523])
        elif choice==5:
            trh(bank[306087961523])
        else:
            print("invalid choice")
            continue    
        time.sleep(5)
    elif p==bank[286496571098][0]:
        
        print("\n1 : Cash Withdrawal")
        print("2 : ATM Deposit")
        print("3 : Display of Details")
        print("4 : Balance Enquiry")
        print("5 : Transaction History")
        choice=int(input("\nPlease select an option to continue.... "))
        if choice==1:
            bank[286496571098][1],bank[286496571098][4]=withd(bank[286496571098])
        elif choice==2:
            bank[286496571098][1],bank[286496571098][4]=deposit(bank[286496571098])
        elif choice==3:
            display(bank[286496571098])
        elif choice==4:
            chk_bal(bank[286496571098])
        elif choice==5:
            trh(bank[286496571098])
        else:
            print("invalid choice")
            continue   
        time.sleep(5)
    elif p==bank[276846789838][0]:
        
        print("\n1 : Cash Withdrawal")
        print("2 : ATM Deposit")
        print("3 : Display of Details")
        print("4 : Balance Enquiry")
        print("5 : Transaction History")
        choice=int(input("\nPlease select an option to continue.... "))
        if choice==1:
            bank[276846789838][1],bank[276846789838][4]=withd(bank[276846789838])
        elif choice==2:
            bank[276846789838][1],bank[276846789838][4]=deposit(bank[276846789838])
        elif choice==3:
            display(bank[276846789838])
        elif choice==4:
            chk_bal(bank[276846789838])
        elif choice==5:
            trh(bank[276846789838])
        else:
            print("invalid choice")
            continue    
        time.sleep(5)
    elif p==bank[304165752987][0]:
        
        print("\n1 : Cash Withdrawal")
        print("2 : ATM Deposit")
        print("3 : Display of Details")
        print("4 : Balance Enquiry")
        print("5 : Transaction History")
        choice=int(input("\nPlease select an option to continue.... "))
        if choice==1:
            bank[304165752987][1],bank[304165752987][4]=withd(bank[276846789838])
        elif choice==2:
            bank[304165752987][1],bank[304165752987][4]=deposit(bank[304165752987])
        elif choice==3:
            display(bank[304165752987])
        elif choice==4:
            chk_bal(bank[304165752987])
        elif choice==5:
            trh(bank[304165752987])
        else:
            print("invalid choice")
            continue   
        time.sleep(5)
    else:
        print("Invalid Pin...")
        print("THANK YOU FOR USING OUR SERVICE ðŸ™\n")
        time.sleep(5)

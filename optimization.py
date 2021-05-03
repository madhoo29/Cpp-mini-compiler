f = open("basicblocks.txt","r")
opt= open("output.txt","w")
fout2 = open("opt2.txt","w")
fout = open("opt1.txt","w")

list_of_lines = []
arg_values = dict()
optimizedList = []
variablenames=dict()

text=f.read()
bb=text.split("\n\n")
#kkk=1
for block in bb:
    list_of_lines.append(block.split("\n"))
list_of_lines.pop(-1)


count=1
for basic_blocks in list_of_lines:
    print("Basic Block number:",count)
    count+=1
    optimizedList = []
    arg_values = dict()
    for i in basic_blocks:        
        op,arg1,arg2,res = i.split()

        if(op =="not"):
            if(arg1 in arg_values):
                arg1=arg_values[arg1]

            if(arg1=="True"):
                arg_values[res]="False"
                print("=","False","(null)",res)
                
                optimizedList.append(["=","False","(null)",res])
                continue            
                

            elif(arg1=="False"):
                arg_values[res]="True"
                print("=","True","(null)",res)
                #fout.write("=   ,True  ,(null) ,%s   ,res\n")
                optimizedList.append(["=","True","(null)",res])
                continue

        # Constant Folding expression evaluation

        if(op in ["+","-","*","/"]):
            # Strength reduction
            if (op =="*") and arg2=="2":
                print("In strength reduction for *")
                a1=None 
                a2=None
                op = '+'
                a1 = a2 = arg1
                print(op,a1,a2,res)
                optimizedList.append([op,a1,a2,res])

            elif (op =="/") and arg2=="2":
                print("In strength reduction for /")
                a1=None 
                a2=None
                op = '*'
                a1=arg1
                a2 = 0.5            
                print(op,a1,a2,res)
                optimizedList.append([op,a1,a2,res])                

            elif(arg1.isdigit() and arg2.isdigit()):
                result = eval(arg1+op+arg2)
                arg_values[res] = str(result)
                print("=",result,"(null)",res)
                optimizedList.append(["=",result,"(null)",res])
                

            #One constant, one variable
            elif(arg1.isdigit()):
                if(arg2 in arg_values):
                    result = eval(arg1+op+arg_values[arg2])
                    arg_values[res] = str(result)
                    print("=",result,"(null)",res)
                    optimizedList.append(["=",result,"(null)",res])
                else:
                    print(op,arg1,arg2,res)
                    optimizedList.append([op,arg1,arg2,res])
            
            elif(arg2.isdigit()):
                if(arg1 in arg_values):
                    result = eval(arg_values[arg1]+op+arg2)
                    arg_values[res] = str(result)
                    print("=",result,"(null)",res)
                    optimizedList.append(["=",result,"(null)",res])

                else:
                    print(op,arg1,arg2,res)
                    optimizedList.append([op,arg1,arg2,res])
            
            else:
                #both variables
                flag1=0
                flag2=0
                arg1Res = arg1
                arg2Res = arg2
                if(arg1 in arg_values):
                    arg1Res = str(arg_values[arg1])
                    if (arg_values[arg1]).isdigit():
                        flag1 = 1
                    #flag1 = 1                    
                if(arg2 in arg_values):
                    arg2Res = str(arg_values[arg2])
                    #flag2 = 1
                    if (arg_values[arg2]).isdigit():
                        flag2 = 1
                if(flag1==1 and flag2==1):
                    #try:
                    result = eval(arg1Res+op+arg2Res)
                    
                    arg_values[res] = result
                    print("=",result,"(null)",res) 
                    optimizedList.append(["=",result,"(null)",res])
                else:
                    #print("HEREEEEE",arg1Res,arg2Res)
                    print(op,arg1Res,arg2Res,res)
                    optimizedList.append([op,arg1Res,arg2Res,res])
                    
        elif(op == ">=" or op == ">" or op == "<=" or op == "<" or op == "==" ):

            a1=None 
            a2=None
            if(arg1.isdigit()):
                a1=arg1
            else:
                try:
                    a1=arg_values[arg1]
                except:
                    pass

            if(arg2.isdigit()):
                a2=arg2
            else:
                try:
                    a2=arg_values[arg2]
                except:
                    pass

            if(a1 == None or a2==None):
                if(a1!=None):
                    pass
                else:
                    a1=arg1

                if(a2!=None):
                    pass
                else:
                    a2=arg2

                print(op,a1,a2,res)
                optimizedList.append([op,a1,a2,res])
                continue


            result=eval(a1+op+a2)
            arg_values[res]=str(result)
            print("=",result,"(null)",res)
            optimizedList.append(["=",result,"(null)",res])

        elif(op=="="):
            variablenames[res]=1
            if(arg1.isdigit()):
                arg_values[res]=arg1
                print("=",arg1,"(null)",res)
                optimizedList.append(["=",arg1,"(null)",res])
            else:
                if(arg1 in arg_values):
                    print("=",arg_values[arg1],"(null)",res)
                    arg_values[res]=arg_values[arg1]
                    optimizedList.append(["=",arg_values[arg1],"(null)",res])
              
                else:
                    #print("Variablenames",variablenames)
                    print("=",arg1,"(null)",res)                    
                    #arg_values[res]=arg1
                    optimizedList.append(["=",arg1,"(null)",res])   
                    if(arg1[0]!='T'):
                        #print("Yesssssssss")
                        arg_values[res]=arg1

        else:
            a1=None 
            a2=None
            if(arg1.isdigit()):
                a1=arg1
            else:
                try:
                    a1=arg_values[arg1]
                except:
                    pass

            if(arg2.isdigit()):
                a2=arg2
            else:
                try:
                    a2=arg_values[arg2]
                except:
                    pass

            if(a1 == None or a2==None):
                if(a1!=None):
                    pass
                else:
                    a1=arg1

                if(a2!=None):
                    pass
                else:
                    a2=arg2
                    
            print(op,a1,a2,res)
            optimizedList.append([op,a1,a2,res])

        #Deadcode elimination

        all_temp = set()
        usefult_temp = set()
        for ii in optimizedList:
            if str(ii[3])[0] == "T": #result is stored in temporary
                all_temp.add(ii[3])

        for ii in optimizedList: #If a temp is an arg, it is useful to the code
            if str(ii[1])[0] == "T":
                usefult_temp.add(ii[1])
            if str(ii[2])[0] == "T":
                usefult_temp.add(ii[2])
        deadcode = [ i for i in all_temp if i not in usefult_temp]  

    c = 1
    for line in optimizedList:
        if line[3] not in deadcode:
            if (c==1):
                line = [str(i) for i in line]
                s = "{:8}\t\t{:8}\t\t{:8}\t\t{:8}\t\tBasic block #{}\n".format(line[0].strip(),line[1].strip(),line[2].strip(),line[3].strip(),count-1)
                fout2.writelines(s)
            else:
                line = [str(i) for i in line]
                s = "{:8}\t\t{:8}\t\t{:8}\t\t{:8}\n".format(line[0].strip(),line[1].strip(),line[2].strip(),line[3].strip())
                fout2.writelines(s)
            c+=1    

    c = 1
    for line in optimizedList:
        if (c==1):
            line = [str(i) for i in line]
            s = "{:8}\t\t{:8}\t\t{:8}\t\t{:8}\t\tBasic block #{}\n".format(line[0].strip(),line[1].strip(),line[2].strip(),line[3].strip(),count-1)
            fout.writelines(s)
        else:
            line = [str(i) for i in line]
            s = "{:8}\t\t{:8}\t\t{:8}\t\t{:8}\n".format(line[0].strip(),line[1].strip(),line[2].strip(),line[3].strip())
            fout.writelines(s)
        c+=1
           
fout2.close()
fout.close()
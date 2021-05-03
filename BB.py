quad_file = open("Quadruples.txt","r")
bb = open("basicblocks.txt","w")

lines = quad_file.readlines()
dictValues = dict()
constantFoldedList = []
leaders = [1]
basic_blocks = []
Labels = {}
temp=[]

for i in range(len(lines)):
    op,arg1,arg2,res = lines[i].split()

    if op == 'Label':
        Labels[res] = i+1
    if op == 'goto':
        temp.append(res)
        leaders.append(i+2)

for i in temp:
    if Labels[i] not in leaders:
        leaders.append(Labels[i])

leaders.sort()
print('Leaders:',leaders)

for i in range(len(leaders)-1):
    basic_blocks.append(lines[leaders[i]-1:leaders[i+1]-1])

basic_blocks.append(lines[leaders[-1]-1:])

for k in basic_blocks:
    bb.writelines(k)
    bb.write("\n")
    #bb.write("\n-------------------------------------------------------------\n\n")

bb.close()
quad_file.close()

# 2. Extend the shell to implement the commands „list‟ which works as follows:
# myshell$ list f dirname: It will display filenames in a given directory.
# myshell$ list n  dirname: It will count the number of entries in a given directory.
# myshell$ list i dirname: It will display filenames and their inode number for
# the files in a given directory.

import os

def getfilenames(path):
    file_names=os.listdir(path) # get filenames
    for f in file_names:
        print(f"filename={f}\n")

def countentries(path):
    cnt=0
    file_names=os.listdir(path)
    for f in file_names:
        cnt+=1
        print(f"filename={f} ={cnt}\n")
    
    print(f"total number of files in:{path} is {cnt}\n")

def getinode(path):
    file_names=os.listdir(path)
    for f in file_names:
        filepath=path+"/"+f
        print(f"filepath:{filepath}")
        print(f"filename:{f} inode:{os.stat(filepath).st_ino}")
    

def main():
    print("main():")
    user_input=input("myshell$ ")
    args=user_input.split(" ")
    print(f"arg0={args[0]}, arg1={args[1]}, arg2={args[2]}")
    pid=os.fork()
    if(pid<0):
        print("Error in child process Creation.")
    elif(pid==0):
        print(f"child process Created. pid:{pid}")
        if(args[0]=='list'):
            if(args[1]=='f'):
                getfilenames(args[2])
            elif(args[1]=='n'):
                countentries(args[2])
            elif(args[1]=='i'):
                getinode(args[2])
            else:
                print("parameter error.")
        else:
            print("command Error.list f|n|i dirname.")
        print(f"child process Finished. pid:{pid}")
    else:
        print(f"parent process Created. pid:{os.getpid()}")
        os.wait()
        print(f"parent process Finished. pid:{os.getpid()}")


if __name__=='__main__':
    main()

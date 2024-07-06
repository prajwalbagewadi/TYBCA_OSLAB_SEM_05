# 1.Implement the shell program that accepts the command at $ prompt displayed by
# your shell (myshell$). Implement the „count‟ command by creating child process
# which works as follows:
# myshell$ count c filename: To display the number of characters in given file
# myshell$ count w filename: To display the number of words in given file
# myshell$ count l filename: To display the number of lines in given file

import os
import sys

def cntchars(filename):
    with open(filename,'r') as file:
        content=file.read()
        char_cnt=len(content)
        print(f"number of Characters in {filename} is {char_cnt}")

def cntwords(filename):
    word_cnt=0
    with open(filename,'r') as file:
        data=file.read()
        lines=data.split("\n")
        print(f"lines={lines} \n type={type(lines)}")
        for line in lines:
            print(f"line={line} \n type={type(line)}")
            l=line.split(" ")
            print(f"l={l} \n type={type(l)}")
            for word in l:
                word_cnt+=1
                print(f"l={word} ={word_cnt}")
    print(f"number of words in {filename} is {word_cnt}")

def cntlines(filename):
    line_cnt=0;
    with open(filename,'r') as file:
        lines=file.readlines()
        for line in lines:
            line_cnt+=1
            print(f"line={line} ={line_cnt}")
    print(f"number of lines in {filename} is {line_cnt}")
            

def main():
    user_input=input("myshell$ ")
    args=user_input.split(" ")
    print(f"arg0={args[0]} arg1={args[1]} arg2={args[2]}")
    if(args[0]=='count'):
        pid=os.fork()
        if(pid<0):
            print("error in fork system call")
        elif(pid==0):
            print(f"Child Process. in Execution.pid={pid}") 
            if(args[1]=='c'):
                cntchars(args[2])
            elif(args[1]=='w'):
                cntwords(args[2])
            elif(args[1]=='l'):
                cntlines(args[2])
            else:
                print("Error in command parameter.") 
        else:
            print(f"Parent process in Execution.pid={os.getpid()}")
            os.wait() #parent in wait state.
    else:
        print(f"Error in command. command:count c|w|l filename.")

if __name__=='__main__':
    main()

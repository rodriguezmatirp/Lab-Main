
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX,0bbbbh
MOV [00001h],AX

MOV AX,0cccch 
MOV [00004h],AX

MOV AX,0ddddh
MOV [00011h],AX

MOV AX,0eeeeh
MOV [00014h],AX

MOV AX,0ffffh
MOV [00016h],AX


MOV AX,0B60h
MOV DS,AX
MOV AX,0000h
MOV BX,0001h
MOV CX,0002h
MOV DX,0003h
MOV SI,0010h
MOV DI,0020h
MOV BP,0030h


MOV AX,BX
MOV AX,0AAAAh  
MOV AX,[BX]  
MOV AX,[4]  
MOV AX,[BX+SI]  
MOV AX,[SI+4]  
MOV AX,[BX+SI+4]  
                        
                        
; add your code here

ret





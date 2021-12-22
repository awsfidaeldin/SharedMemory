//Program shows how to get the memory allocate strategy: 
//Use Borland C++ Version 3.0
#include<dos.h>
#include<conio.h>
#include<iostream.h>

void main()
{
 clrscr();
  int x;
 asm mov ax,5800h
 asm int 21h
 asm  jc get_out
 asm mov x,ax
 if(x==0)
 cout<<"The Memory Allocation Strategy is First Fit";
 else if(x==1)
 cout<<"The Memory Allocation Strategy is Best Fit";
 else if(x==2)
 cout<<"The Memory Allocation Strategy is Last Fit";
 get_out:
 getch();
}

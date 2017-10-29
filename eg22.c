#include<stdio.h>
int main()
{
struct wordregs
{
unsigned int ax,bx,cx,dx,si,di,cflag,flags;
};
struct byteregs
{
unsigned char al,ah,bl,bh,cl,ch,dl,dh;
};
union regs
{
struct wordregs x;
struct byteregs h;
};
union regs inregs,outregs;
int memsize;
int86(18,&inregs,&outregs);
memsize=outregs.x.ax;
printf("\nTotal memory = %d",memsize);
return 0;
}
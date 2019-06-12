	ifndef	??version
?debug	macro
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	S "swap.cpp"
	?debug	C E9357DC64E08737761702E637070
	?debug	C E9C07B521812783A5C696E636C7564655C737464696F2E68
	?debug	C E9C07B521812783A5C696E636C7564655C5F646566732E68
	?debug	C E9C07B521812783A5C696E636C7564655C5F6E756C6C2E68
	?debug	C E9C07B521812783A5C696E636C7564655C636F6E696F2E68
	?debug	C E9C07B521815783A5C696E636C7564655C696F73747265616D2E68
	?debug	C E9C07B521810783A5C696E636C7564655C6D656D2E68
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	void swapVal(int inp1 , int inp2)
   ;	
	assume	cs:_TEXT
@swapVal$qii	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	  int temp;
   ;	  temp = inp1 ;
   ;	
	mov	ax,word ptr [bp+4]
	mov	word ptr [bp-2],ax
   ;	
   ;	  inp1 = inp2;
   ;	
	mov	ax,word ptr [bp+6]
	mov	word ptr [bp+4],ax
   ;	
   ;	  inp2 = temp;
   ;	
	mov	ax,word ptr [bp-2]
	mov	word ptr [bp+6],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swapVal$qii	endp
   ;	
   ;	void swapRefVar(int &inp1 , int &inp2)
   ;	
	assume	cs:_TEXT
@swapRefVar$qrit1	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	  int temp;
   ;	  temp = inp1 ;
   ;	
	mov	bx,word ptr [bp+4]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-2],ax
   ;	
   ;	  inp1 = inp2;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	mov	bx,word ptr [bp+4]
	mov	word ptr [bx],ax
   ;	
   ;	  inp2 = temp;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bp-2]
	mov	word ptr [bx],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swapRefVar$qrit1	endp
   ;	
   ;	void swapRef(int *inp1 , int *inp2)
   ;	
	assume	cs:_TEXT
@swapRef$qpit1	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	  int temp;
   ;	  temp = *inp1 ;
   ;	
	mov	bx,word ptr [bp+4]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-2],ax
   ;	
   ;	  *inp1 = *inp2;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	mov	bx,word ptr [bp+4]
	mov	word ptr [bx],ax
   ;	
   ;	  *inp2 = temp;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bp-2]
	mov	word ptr [bx],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swapRef$qpit1	endp
   ;	
   ;	int main()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
   ;	
   ;	{
   ;	 int num1=10 ,num2=20;
   ;	
	mov	word ptr [bp-2],10
	mov	word ptr [bp-4],20
   ;	
   ;	 clrscr();
   ;	
	call	near ptr _clrscr
   ;	
   ;	  printf("\n\tVAL : Value before swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  swapVal(num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	call	near ptr @swapVal$qii
	pop	cx
	pop	cx
   ;	
   ;	  printf("\n\tVAL : Value after swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+52
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  printf("\n\tREF: Value before swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+103
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  swapRef(&num1,&num2);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	lea	ax,word ptr [bp-2]
	push	ax
	call	near ptr @swapRef$qpit1
	pop	cx
	pop	cx
   ;	
   ;	  printf("\n\tREF: Value after swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+154
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  printf("\n\tREFVAR: Value before swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+204
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  swapRefVar(num1,num2);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	lea	ax,word ptr [bp-2]
	push	ax
	call	near ptr @swapRefVar$qrit1
	pop	cx
	pop	cx
   ;	
   ;	  printf("\n\tREFVAR: Value after swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+258
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 getch();
   ;	
	call	near ptr _getch
   ;	
   ;	 return 0 ;
   ;	
	xor	ax,ax
	jmp	short @4@58
@4@58:
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
_main	endp
	?debug	C E9
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	10
	db	9
	db	'VAL : Value before swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'VAL : Value after swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REF: Value before swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REF: Value after swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REFVAR: Value before swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REFVAR: Value after swapping  num1 : %d num2 : %d '
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	@swapRef$qpit1
	public	@swapRefVar$qrit1
	public	@swapVal$qii
	extrn	@ios@usercount:word
	extrn	@ios@nextbit:word
	extrn	@ios@stdioflush:word
	extrn	@ios@floatfield:word
	extrn	@ios@adjustfield:word
	extrn	@ios@basefield:word
	extrn	_getch:near
	extrn	_clrscr:near
	extrn	_printf:near
_s@	equ	s@
	end

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
	?debug	S "funover.cpp"
	?debug	C E9157FC64E0B66756E6F7665722E637070
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
   ;	void swap(int &inp1 , int &inp2)
   ;	
	assume	cs:_TEXT
@swap$qrit1	proc	near
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
@swap$qrit1	endp
   ;	
   ;	void swap(float &inp1 , float &inp2)
   ;	
	assume	cs:_TEXT
@swap$qrft1	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
   ;	
   ;	{
   ;	  float temp;
   ;	  temp = inp1 ;
   ;	
	mov	bx,word ptr [bp+4]
	fld	dword ptr [bx]
	fstp	dword ptr [bp-4]
   ;	
   ;	  inp1 = inp2;
   ;	
	fwait	
	mov	bx,word ptr [bp+6]
	fld	dword ptr [bx]
	mov	bx,word ptr [bp+4]
	fstp	dword ptr [bx]
   ;	
   ;	  inp2 = temp;
   ;	
	fwait	
	mov	bx,word ptr [bp+6]
	fld	dword ptr [bp-4]
	fstp	dword ptr [bx]
	fwait	
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swap$qrft1	endp
   ;	
   ;	int main()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,12
   ;	
   ;	{
   ;	 int num1=10 ,num2=20;
   ;	
	mov	word ptr [bp-2],10
	mov	word ptr [bp-4],20
   ;	
   ;	 float  fnum1=7.29,fnum2=8.79;
   ;	
	fld	dword ptr DGROUP:s@
	fstp	dword ptr [bp-8]
	fld	dword ptr DGROUP:s@+4
	fstp	dword ptr [bp-12]
   ;	
   ;	 clrscr();
   ;	
	fwait	
	call	near ptr _clrscr
   ;	
   ;	  printf("\n\tREFVAR: Value before swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+8
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  swap(num1,num2);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	lea	ax,word ptr [bp-2]
	push	ax
	call	near ptr @swap$qrit1
	pop	cx
	pop	cx
   ;	
   ;	  printf("\n\tREFVAR: Value after swapping  num1 : %d num2 : %d ",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+62
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	  printf("\n\tREFVAR: Value before swapping  fnum1 : %f fnum2 : %f ",fnum1,fnum2);
   ;	
	fld	dword ptr [bp-12]
	sub	sp,8
	fstp	qword ptr [bp-20]
	fld	dword ptr [bp-8]
	sub	sp,8
	fstp	qword ptr [bp-28]
	mov	ax,offset DGROUP:s@+115
	push	ax
	fwait	
	call	near ptr _printf
	add	sp,18
   ;	
   ;	  swap(fnum1,fnum2);
   ;	
	lea	ax,word ptr [bp-12]
	push	ax
	lea	ax,word ptr [bp-8]
	push	ax
	call	near ptr @swap$qrft1
	pop	cx
	pop	cx
   ;	
   ;	  printf("\n\tREFVAR: Value after swapping  fnum1 : %f fnum2 : %f ",fnum1,fnum2);
   ;	
	fld	dword ptr [bp-12]
	sub	sp,8
	fstp	qword ptr [bp-20]
	fld	dword ptr [bp-8]
	sub	sp,8
	fstp	qword ptr [bp-28]
	mov	ax,offset DGROUP:s@+171
	push	ax
	fwait	
	call	near ptr _printf
	add	sp,18
   ;	
   ;	 getch();
   ;	
	call	near ptr _getch
   ;	
   ;	 return 0 ;
   ;	
	xor	ax,ax
	jmp	short @3@58
@3@58:
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
	db	-82
	db	'G'
	db	-23
	db	'@'
	db	-41
	db	-93
	db	12
	db	'A'
	db	10
	db	9
	db	'REFVAR: Value before swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REFVAR: Value after swapping  num1 : %d num2 : %d '
	db	0
	db	10
	db	9
	db	'REFVAR: Value before swapping  fnum1 : %f fnum2 : %f '
	db	0
	db	10
	db	9
	db	'REFVAR: Value after swapping  fnum1 : %f fnum2 : %f '
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	extrn	__turboFloat:word
	public	_main
	public	@swap$qrft1
	public	@swap$qrit1
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
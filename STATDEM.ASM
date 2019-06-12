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
	?debug	S "statdem.c"
	?debug	C E90E87C54E097374617464656D2E63
	?debug	C E9C07B521812783A5C696E636C7564655C737464696F2E68
	?debug	C E9C07B521812783A5C696E636C7564655C5F646566732E68
	?debug	C E9C07B521812783A5C696E636C7564655C5F6E756C6C2E68
	?debug	C E9C07B521812783A5C696E636C7564655C636F6E696F2E68
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
   ;	static void sfun()
   ;	
	assume	cs:_TEXT
sfun	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  printf("\n\tstatic");
   ;	
	mov	ax,offset DGROUP:s@
	push	ax
	call	near ptr _printf
	pop	cx
   ;	
   ;	}
   ;	
	pop	bp
	ret	
sfun	endp
   ;	
   ;	void dummy()
   ;	
	assume	cs:_TEXT
_dummy	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  printf("\n\tdummy");
   ;	
	mov	ax,offset DGROUP:s@+9
	push	ax
	call	near ptr _printf
	pop	cx
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_dummy	endp
   ;	
   ;	int main()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	  int num;
   ;	 clrscr();
   ;	
	call	near ptr _clrscr
   ;	
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
	pop	bp
	ret	
_main	endp
_TEXT	ends
_BSS	segment word public 'BSS'
outmains	label	word
	db	2 dup (?)
_outmain	label	word
	db	2 dup (?)
	?debug	C E9
_BSS	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	10
	db	9
	db	'static'
	db	0
	db	10
	db	9
	db	'dummy'
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
_outmains	equ	outmains
	public	_outmain
	public	_dummy
_sfun	equ	sfun
	extrn	_getch:near
	extrn	_clrscr:near
	extrn	_printf:near
_s@	equ	s@
	end

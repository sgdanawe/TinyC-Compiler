	.file	"ass1b_18CS30015.c"
	.text
	.section	.rodata
.LC0:
	.string	"\nThe greater number is:%d"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp				#register base pointer is pushed on to the stack
	movq	%rsp, %rbp			#stack pointer is copied to the base pointer
	subq	$16, %rsp			#stack pointer is decreased by 16 resulting in allocating space on the stack 
	movl	$45, -8(%rbp)		#number 45 is stored at the address %rbp-8.....(-8(%rbp)=rbp-8)
	movl	$68, -4(%rbp)		#number 68 is stored at the address %rbp-4.....(-4(%rbp)=rbp-4)
	movl	-8(%rbp), %eax		#Now as we have to compare the above two values we will store one number in the register eax in which return value from a function is stored
	cmpl	-4(%rbp), %eax		#Now value in -4(%rbp) (i.e. 68) is compared with the value stored in eax register. This is done by subtracting (%eax-(-4(%rbp)))
	jle	.L2						#Now the comparison done in the last step is checked. jle means less than or equal to 0. If this is true then a jump will be taken to .L2 and the next line will be ignored after returning to this point from .L2 else the next line will be executed
	movl	-8(%rbp), %eax		#This line will be executed if the less than equal to comparison becomes false. Here we thwn copy the value at the address (%rbp - 8) in eax register  
	movl	%eax, -12(%rbp)		#Now the value from the eax register is copied at the address (%rbp - 12). Note that as we cannot directly move the values in a stack, we are using eax register as a temp register
	jmp	.L3						#This instruction tells to jump to .L3
.L2:
	movl	-4(%rbp), %eax		#This line will be executed if the less than equal to comparison becomes true. Here the value at address (%rbp-4) is copied to eax register
	movl	%eax, -12(%rbp)		#Now the value from the eax register is copied at the address (%rbp - 12). Note that as we cannot directly move the values in a stack, we are using eax register as a temp register
.L3:
	movl	-12(%rbp), %eax		#executing the jmp .L3 instruction we reach here. Here we will copy the value at the address (%rbp-12) into the eax register(eax=mem[%rbp-12])
	movl	%eax, %esi			#esi=eax
	leaq	.LC0(%rip), %rdi	#moves address of "\nThe greater number is:%d" into stack where rdi is pointing
	movl	$0, %eax			#as the return value of main function is 0, so 0 is stored in eax(%eax=0)
	call	printf@PLT			#pushing the argument to printf. Then printf will be called
	movl	$0, %eax			#as the return value of main function is 0, so 0 is stored in eax(%eax=0)
	leave						#copies rbp to rsp, pops old rbp from stack
	ret							#pops the return address of the stack. Function exit
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

	.file	"ass1a_18CS30015.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\nGCD of %d, %d, %d and %d id: %d"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp					#base pointer is pushed to the stack
	movq	%rsp, %rbp				#copy the stack pointer to the base pointer(rbp=rsp)
	subq	$32, %rsp				#stack pointer is decreased by 32 resulting in allocating space on the stack(rsp=rsp-32)
	#Following 4 instruction are going to store the 4 variable values on to the stack
	movl	$45, -20(%rbp)			#number 45(=a) is stored at the address %rbp-20(Mem[rbp-20]=45)
	movl	$99, -16(%rbp)			#number 99(=b) is stored at the address %rbp-16(Mem[rbp-16]=99)
	movl	$18, -12(%rbp)			#number 18(=c) is stored at the address %rbp-12(Mem[rbp-12]=18)
	movl	$180, -8(%rbp)			#number 180(=d) is stored at the address %rbp-8(Mem[rbp-8]=180)
	#Now as we are going to call the GCD4 function so its arguments are stored in the respective registers
	movl	-8(%rbp), %ecx			#ecx register is used to store the 4th argument to a function GCD4 (eax=Mem[rbp-8])
	movl	-12(%rbp), %edx			#edx register is used to store the 3rd argument to a function GCD4 (edx=Mem[rbp-12])
	movl	-16(%rbp), %esi			#esi register is used to store the 2nd argument to a function GCD4 (esi=Mem[rbp-16])
	movl	-20(%rbp), %eax			#eax=Mem[rbp-20]
	movl	%eax, %edi				#edi register is used to store the 1st argument to a function GCD4 (edi=eax)
	call	GCD4                    #GCD4 function is called
	movl	%eax, -4(%rbp)			#return value of GCD4 is copied from eax to the address %rbp-4.(mem[%rbp-4]=eax)
	movl	-4(%rbp), %edi			#edi=mem[%rbp-4]
	movl	-8(%rbp), %esi			#esi=mem[%rbp-8]
	movl	-12(%rbp), %ecx			#ecx=mem[%rbp-12]
	movl	-16(%rbp), %edx			#edx=mem[%rbp-16]
	movl	-20(%rbp), %eax			#eax=mem[%rbp-20]
	movl	%edi, %r9d				#r9d=edi, r9d is a register
	movl	%esi, %r8d				#r8d=esi, r8d is a register
	movl	%eax, %esi				#esi=eax
	leaq	.LC0(%rip), %rdi		#Giving printf the 1st argument i.e. "\nGCD of %d, %d, %d and %d id: %d"
	movl	$0, %eax				#as the return value of main function is 0, so 0 is stored in eax(%eax=0)
	call	printf@PLT				#pushing the argument to printf. Then printf will be called
	movl	$10, %edi				#assingning the register edi the ASCII value of "\n" i.e. 10
	call	putchar@PLT				#instruction add "\n" character
	movl	$0, %eax				#as the return value of main function is 0, so 0 is stored in eax(%eax=0)
	leave
	ret
	.size	main, .-main
	.globl	GCD4
	.type	GCD4, @function
GCD4:
	pushq	%rbp				#base pointer is pushed to the new stack frame		
	movq	%rsp, %rbp			#stack pointer is copied to the base pointer(rbp=rsp)
	subq	$32, %rsp			#stack pointer is decreased by 32 resulting in allocating memory to the stack(rsp=rsp-32)
	#now the next 4 instruction copies the values stored in the respective registers to the stack
	movl	%edi, -20(%rbp)		#mem[rbp-20]=edi
	movl	%esi, -24(%rbp)		#mem[rbp-24]=esi
	movl	%edx, -28(%rbp)		#mem[rbp-28]=edx
	movl	%ecx, -32(%rbp)		#mem[rbp-32]=ecx
	movl	-24(%rbp), %edx		#edx=mem[rbp-24]
	movl	-20(%rbp), %eax		#eax=mem[rbp-20]
	#Now as GCD function is going to be called the arguments are stored in the respective registers
	movl	%edx, %esi			#esi=edx, esi used to store 2nd argument to a function
	movl	%eax, %edi			#edi=eax, edi used to store 1st argument to a function
	call	GCD					#GCD function is called
	movl	%eax, -12(%rbp)		#register eax is used to store return value of a function. value returned from function GCD is copied at the address rbp-12.(mem[%rbp-12]=eax)
	movl	-32(%rbp), %edx		#edx=mem[rbp-32]
	movl	-28(%rbp), %eax		#eax=mem[rbp-28]
	#Now as GCD function is going to be called the arguments are stored in the respective registers
	movl	%edx, %esi			#esi=edx, esi used to store 2nd argument to a function
	movl	%eax, %edi			#edi=eax, edi used to store 1st argument to a function
	call	GCD					#GCD function is called
	movl	%eax, -8(%rbp)		#register eax is used to store return value of a function. value returned from function GCD is copied at the address rbp-12.(mem[%rbp-12]=eax)
	movl	-8(%rbp), %edx		#edx=mem[%rbp-8]
	movl	-12(%rbp), %eax		#eax=mem[%rbp-12]
	#Now as GCD function is going to be called the arguments are stored in the respective registers
	movl	%edx, %esi			#esi=edx, esi used to store 2nd argument to a function	
	movl	%eax, %edi			#edi=eax, edi used to store 1st argument to a function
	call	GCD					#GCD function is called
	movl	%eax, -4(%rbp)		#mem[%rbp-4]=eax
	movl	-4(%rbp), %eax		#now we will be returning the value of GCD4 function so we are storing it in eax as it is used to store return values of a function
	leave						#rbp is copied to rsp and the old rbp is popped from the stack
	ret							#pops the return address of the stack. Function exit
	.size	GCD4, .-GCD4
	.globl	GCD
	.type	GCD, @function
GCD:
	pushq	%rbp				#base pointer for a new stack frame is pushed
	movq	%rsp, %rbp			#stack pointer is copied to the base pointer(rbp=rsp)
	movl	%edi, -20(%rbp)		#now the values from the registers are retrieved (mem[rbp-20]=edi)
	movl	%esi, -24(%rbp)		#mem[rbp-24]=esi
	jmp	.L6						#this instruction tells to jump to .L6
.L7:
	movl	-20(%rbp), %eax		#eax=mem[%rbp-20]
	cltd						#this instruction converts signed long in eax to signed long double in edx:eax by extending the msb bit(i.e. sign bit) of eax into all bits of edx 
	idivl	-24(%rbp)			#this devides edx:eax by mem[rbp-24] and stores the quotient in eax and remainder in edx
	movl	%edx, -4(%rbp)		#remainder is stored on stack(mem[%rbp-4]=edx) which is used as temp in the c code
	movl	-24(%rbp), %eax		#eax=mem[%rbp-24]
	movl	%eax, -20(%rbp)		#mem[%rbp-20]=eax
	movl	-4(%rbp), %eax		#eax=mem[%rbp-4]
	movl	%eax, -24(%rbp)		#mem[%rbp-24]=eax
.L6:							#while loop
	movl	-20(%rbp), %eax		#eax=mem[rbp-20]
	cltd						#this instruction converts signed long in eax to signed long double in edx:eax by extending the msb bit(i.e. sign bit) of eax into all bits of edx 
	idivl	-24(%rbp)			#this divides edx:eax by mem[rbp-24] and stores the quotient in eax and remainder in edx. (num1%num2) is done here
	movl	%edx, %eax			#remainder in edx is copied to eax(eax=edx)
	testl	%eax, %eax			#this instruction tests wheather value in eax is zero or not
	jne	.L7						#this instruction jumps to .L7 if the value of eax is not equal(jne=jump not equal) to zero
	movl	-24(%rbp), %eax		#here we are storing the return value of the function GCD in to the eax register which is used to store return value of functions
	popq	%rbp				#this pops the base pointer from the stack frame
	ret							#pops the return address of the stack. Function exit
	.size	GCD, .-GCD
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

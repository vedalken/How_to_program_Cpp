	.file	"main.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 8
.LC0:
	.string	"\nInput three integer numbers: "
.LC1:
	.string	"Maximum integer number is "
.LC2:
	.string	"\nInput three double numbers: "
.LC3:
	.string	"Maximum double number is "
.LC4:
	.string	"\nInput three characters: "
.LC5:
	.string	"Maximum char is "
	.text
	.globl	main
	.type	main, @function
main:
.LFB970:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA970
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERi
	leaq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERi
	leaq	-28(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERi
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	_Z7maximumIiET_S0_S0_S0_
	movl	%eax, %ebx
	movl	$.LC1, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERd
	leaq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd
	leaq	-56(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd
	movq	-56(%rbp), %rcx
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rcx, -72(%rbp)
	movsd	-72(%rbp), %xmm2
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm1
	movq	%rax, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	call	_Z7maximumIdET_S0_S0_S0_
	movsd	%xmm0, -72(%rbp)
	movq	-72(%rbp), %rbx
	movl	$.LC3, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rbx, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSolsEd
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-57(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	leaq	-58(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	leaq	-59(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	movzbl	-59(%rbp), %eax
	movsbl	%al, %edx
	movzbl	-58(%rbp), %eax
	movsbl	%al, %ecx
	movzbl	-57(%rbp), %eax
	movsbl	%al, %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	_Z7maximumIcET_S0_S0_S0_
	movsbl	%al, %ebx
	movl	$.LC5, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	movl	$0, %eax
	jmp	.L5
.L4:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L5:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE970:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA970:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE970-.LLSDACSB970
.LLSDACSB970:
	.uleb128 .LEHB0-.LFB970
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L4-.LFB970
	.uleb128 0
	.uleb128 .LEHB1-.LFB970
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE970:
	.text
	.size	main, .-main
	.section	.text._Z7maximumIiET_S0_S0_S0_,"axG",@progbits,_Z7maximumIiET_S0_S0_S0_,comdat
	.weak	_Z7maximumIiET_S0_S0_S0_
	.type	_Z7maximumIiET_S0_S0_S0_, @function
_Z7maximumIiET_S0_S0_S0_:
.LFB972:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	.L7
	movl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L8
	movl	-28(%rbp), %eax
	movl	%eax, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE972:
	.size	_Z7maximumIiET_S0_S0_S0_, .-_Z7maximumIiET_S0_S0_S0_
	.section	.text._Z7maximumIdET_S0_S0_S0_,"axG",@progbits,_Z7maximumIdET_S0_S0_S0_,comdat
	.weak	_Z7maximumIdET_S0_S0_S0_
	.type	_Z7maximumIdET_S0_S0_S0_, @function
_Z7maximumIdET_S0_S0_S0_:
.LFB976:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	%xmm2, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movsd	-32(%rbp), %xmm0
	ucomisd	-8(%rbp), %xmm0
	jbe	.L11
.L16:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
.L11:
	movsd	-40(%rbp), %xmm0
	ucomisd	-8(%rbp), %xmm0
	jbe	.L13
.L17:
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
.L13:
	movq	-8(%rbp), %rax
	movq	%rax, -48(%rbp)
	movsd	-48(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE976:
	.size	_Z7maximumIdET_S0_S0_S0_, .-_Z7maximumIdET_S0_S0_S0_
	.section	.text._Z7maximumIcET_S0_S0_S0_,"axG",@progbits,_Z7maximumIcET_S0_S0_S0_,comdat
	.weak	_Z7maximumIcET_S0_S0_S0_
	.type	_Z7maximumIcET_S0_S0_S0_, @function
_Z7maximumIcET_S0_S0_S0_:
.LFB978:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%esi, %ecx
	movl	%edx, %eax
	movb	%dil, -20(%rbp)
	movb	%cl, -24(%rbp)
	movb	%al, -28(%rbp)
	movzbl	-20(%rbp), %eax
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	cmpb	-24(%rbp), %al
	jge	.L19
	movzbl	-24(%rbp), %eax
	movb	%al, -1(%rbp)
.L19:
	movzbl	-1(%rbp), %eax
	cmpb	-28(%rbp), %al
	jge	.L20
	movzbl	-28(%rbp), %eax
	movb	%al, -1(%rbp)
.L20:
	movzbl	-1(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE978:
	.size	_Z7maximumIcET_S0_S0_S0_, .-_Z7maximumIcET_S0_S0_S0_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB985:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L22
	cmpl	$65535, -8(%rbp)
	jne	.L22
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L22:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE985:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB986:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE986:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.7.2 20120921 (Red Hat 4.7.2-2)"
	.section	.note.GNU-stack,"",@progbits

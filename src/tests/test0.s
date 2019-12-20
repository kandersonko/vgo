	.file	"tests/test0.go"
	.section	.rodata
	.text
	movq	$12, %rax
	addq	$5, %rax
	movq	%rax, -8(%rbp)
	movq	$45, %rax
	divq	$8, %rax
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rax
	mulq	-168(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	$2, %rax
	subq	-8(%rbp), %rax
	movq	%rax, -80(%rbp)
	cmpq	.L0, .L0
	je	.L0
.L0:
	jump	.L0
	cmpq	.L0, .L0
	je	.L0

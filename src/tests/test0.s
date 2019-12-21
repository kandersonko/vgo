	.file	"../tests/test0.go"
	.section	.rodata
	.text

	movq	$12, %rax
	addq	$5, %rax
	movq	%rax, -8(%rbp)

	movq	$2, %rax
	subq	-8(%rbp), %rax
	movq	%rax, -48(%rbp)

	cmpq	$0, .L0
	je	.L0

.L0:

	jump	.L0

	cmpq	$0, .L0
	je	.L0


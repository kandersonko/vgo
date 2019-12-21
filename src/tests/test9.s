	.file	"tests/test9.go"
	.section	.rodata
	.text

	movq	$0, %rax
	mulq	$0, %rax
	movq	%rax, -8(%rbp)


	.file	"Boj11279.c"
	.intel_syntax noprefix
# GNU C17 (GCC) version 8.5.0 20210514 (Red Hat 8.5.0-10) (x86_64-redhat-linux)
#	compiled by GNU C version 8.5.0 20210514 (Red Hat 8.5.0-10), GMP version 6.1.2, MPFR version 3.1.6-p2, MPC version 1.1.0, isl version none
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  Boj11279.c -masm=intel -mtune=generic -march=x86-64 -Og
# -fverbose-asm
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcombine-stack-adjustments -fcommon -fcompare-elim
# -fcprop-registers -fdefer-pop -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
# -fgnu-runtime -fgnu-unique -fguess-branch-probability -fident -finline
# -finline-atomics -fipa-profile -fipa-pure-const -fipa-reference
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fivopts -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-constants
# -fmerge-debug-strings -fomit-frame-pointer -fpeephole -fplt
# -fprefetch-loop-arrays -freg-struct-return -freorder-blocks
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftoplevel-reorder
# -ftrapping-math -ftree-builtin-call-dce -ftree-ccp -ftree-ch
# -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-ter
# -funit-at-a-time -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB22:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	mov	r12, rdi	# arr, arr
	mov	ebp, esi	# n, n
# Boj11279.c:8:     for (i = 0; i < n; i++) {
	mov	ebx, 0	# i,
.L2:
# Boj11279.c:8:     for (i = 0; i < n; i++) {
	cmp	ebx, ebp	# i, n
	jge	.L5	#,
# Boj11279.c:10:         printf("%d ", arr[i]);
	movsx	rax, ebx	# i, i
# Boj11279.c:10:         printf("%d ", arr[i]);
	mov	esi, DWORD PTR [r12+rax*4]	#, *_3
	mov	edi, OFFSET FLAT:.LC0	#,
	mov	eax, 0	#,
	call	printf	#
# Boj11279.c:8:     for (i = 0; i < n; i++) {
	add	ebx, 1	# i,
	jmp	.L2	#
.L5:
# Boj11279.c:12:     printf("\n");
	mov	edi, 10	#,
	call	putchar	#
# Boj11279.c:13: }
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE22:
	.size	printArray, .-printArray
	.globl	charArray
	.type	charArray, @function
charArray:
.LFB23:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	mov	r12, rdi	# arr, arr
	mov	ebp, esi	# n, n
# Boj11279.c:17:     for (i = 0; i < n; i++) {
	mov	ebx, 0	# i,
.L7:
# Boj11279.c:17:     for (i = 0; i < n; i++) {
	cmp	ebx, ebp	# i, n
	jge	.L10	#,
# Boj11279.c:19:         printf("%d ", arr[i]);
	movsx	rax, ebx	# i, i
# Boj11279.c:19:         printf("%d ", arr[i]);
	movsx	esi, BYTE PTR [r12+rax]	# _3, *_2
	mov	edi, OFFSET FLAT:.LC0	#,
	mov	eax, 0	#,
	call	printf	#
# Boj11279.c:17:     for (i = 0; i < n; i++) {
	add	ebx, 1	# i,
	jmp	.L7	#
.L10:
# Boj11279.c:21:     printf("\n");
	mov	edi, 10	#,
	call	putchar	#
# Boj11279.c:22: }
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE23:
	.size	charArray, .-charArray
	.section	.rodata.str1.1
.LC1:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 48
# Boj11279.c:39:     node* rootNode = malloc(sizeof(node));
	mov	edi, 24	#,
	call	malloc	#
	mov	rbp, rax	# rootNode,
# Boj11279.c:43:     scanf("%d", &N);
	lea	rsi, [rsp+12]	# tmp99,
	mov	edi, OFFSET FLAT:.LC1	#,
	mov	eax, 0	#,
	call	__isoc99_scanf	#
# Boj11279.c:46:     for (int i = 0; i < N; i++)
	mov	ebx, 0	# i,
# Boj11279.c:46:     for (int i = 0; i < N; i++)
	jmp	.L12	#
.L14:
# Boj11279.c:57:                 rootNode->num = (rootNode->num) > n ? rootNode->num : n;
	cmp	eax, edx	# n.0_1, _2
	cmovl	eax, edx	# n.0_1,, _3, _2
# Boj11279.c:57:                 rootNode->num = (rootNode->num) > n ? rootNode->num : n;
	mov	DWORD PTR [rbp+0], eax	# rootNode_11->num, _3
.L13:
# Boj11279.c:46:     for (int i = 0; i < N; i++)
	add	ebx, 1	# i,
.L12:
# Boj11279.c:46:     for (int i = 0; i < N; i++)
	cmp	DWORD PTR [rsp+12], ebx	# N, i
	jle	.L17	#,
# Boj11279.c:48:         scanf("%d", &n);
	lea	rsi, [rsp+8]	# tmp100,
	mov	edi, OFFSET FLAT:.LC1	#,
	mov	eax, 0	#,
	call	__isoc99_scanf	#
# Boj11279.c:49:         if(n==0){
	mov	eax, DWORD PTR [rsp+8]	# n.0_1, n
# Boj11279.c:49:         if(n==0){
	test	eax, eax	# n.0_1
	je	.L13	#,
# Boj11279.c:53:             if(rootNode->num==0){
	mov	edx, DWORD PTR [rbp+0]	# _2, rootNode_11->num
# Boj11279.c:53:             if(rootNode->num==0){
	test	edx, edx	# _2
	jne	.L14	#,
# Boj11279.c:54:                 rootNode->num = n;
	mov	DWORD PTR [rbp+0], eax	# rootNode_11->num, n.0_1
	jmp	.L13	#
.L17:
# Boj11279.c:63:     printf("%d", rootNode->num);
	mov	esi, DWORD PTR [rbp+0]	#, rootNode_11->num
	mov	edi, OFFSET FLAT:.LC1	#,
	mov	eax, 0	#,
	call	printf	#
# Boj11279.c:65:     free(rootNode);
	mov	rdi, rbp	#, rootNode
	call	free	#
# Boj11279.c:71: }
	mov	eax, 0	#,
	add	rsp, 24	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
	pop	rbp	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.comm	negative,40000004,32
	.comm	positive,40000004,32
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-10)"
	.section	.note.GNU-stack,"",@progbits

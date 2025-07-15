	.file	"lib/fuck_start.S"
	.text
	.globl	_fuck_start                     # -- Begin function _fuck_start
	.p2align	4
	.type	_fuck_start,@function
_fuck_start:                            # @_fuck_start
.Lfunc_begin0:
	.loc	0 14 0                          # lib/fuck_start.cc:14:0
	.cfi_sections .debug_frame
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
.Ltmp0:
	.loc	0 16 5 prologue_end             # lib/fuck_start.cc:16:5
	#APP
	movq	%rsp, %rax
	#NO_APP
	movq	%rax, -8(%rbp)
	.loc	0 18 21                         # lib/fuck_start.cc:18:21
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
                                        # kill: def $eax killed $eax killed $rax
	.loc	0 18 9 is_stmt 0                # lib/fuck_start.cc:18:9
	movl	%eax, -12(%rbp)
	.loc	0 19 30 is_stmt 1               # lib/fuck_start.cc:19:30
	movq	-8(%rbp), %rax
	addq	$8, %rax
	.loc	0 19 12 is_stmt 0               # lib/fuck_start.cc:19:12
	movq	%rax, -24(%rbp)
	.loc	0 20 19 is_stmt 1               # lib/fuck_start.cc:20:19
	movq	-24(%rbp), %rax
	.loc	0 20 24 is_stmt 0               # lib/fuck_start.cc:20:24
	movslq	-12(%rbp), %rcx
	shlq	$3, %rcx
	addq	%rcx, %rax
	.loc	0 20 31                         # lib/fuck_start.cc:20:31
	addq	$8, %rax
	.loc	0 20 12                         # lib/fuck_start.cc:20:12
	movq	%rax, -32(%rbp)
	.loc	0 23 20 is_stmt 1               # lib/fuck_start.cc:23:20
	movl	-12(%rbp), %edi
	.loc	0 23 26 is_stmt 0               # lib/fuck_start.cc:23:26
	movq	-24(%rbp), %rsi
	.loc	0 23 32                         # lib/fuck_start.cc:23:32
	movq	-32(%rbp), %rdx
	.loc	0 23 15                         # lib/fuck_start.cc:23:15
	callq	main@PLT
	.loc	0 23 9                          # lib/fuck_start.cc:23:9
	movl	%eax, -36(%rbp)
	.loc	0 30 23 is_stmt 1               # lib/fuck_start.cc:30:23
	movslq	-36(%rbp), %rcx
	.loc	0 26 5                          # lib/fuck_start.cc:26:5
	#APP
	movq	$60, %rax
	movq	%rcx, %rdi
	syscall

	#NO_APP
.Ltmp1:
.Lfunc_end0:
	.size	_fuck_start, .Lfunc_end0-_fuck_start
	.cfi_endproc
                                        # -- End function
	.file	1 "inc" "types.hh"
	.file	2 "inc" "c_str.hh"
	.file	3 "inc" "errno.hh"
	.section	.debug_abbrev,"",@progbits
	.byte	1                               # Abbreviation Code
	.byte	17                              # DW_TAG_compile_unit
	.byte	1                               # DW_CHILDREN_yes
	.byte	37                              # DW_AT_producer
	.byte	37                              # DW_FORM_strx1
	.byte	19                              # DW_AT_language
	.byte	5                               # DW_FORM_data2
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	114                             # DW_AT_str_offsets_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	16                              # DW_AT_stmt_list
	.byte	23                              # DW_FORM_sec_offset
	.byte	27                              # DW_AT_comp_dir
	.byte	37                              # DW_FORM_strx1
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	115                             # DW_AT_addr_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	2                               # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	3                               # Abbreviation Code
	.byte	15                              # DW_TAG_pointer_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	4                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	5                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	6                               # Abbreviation Code
	.byte	57                              # DW_TAG_namespace
	.byte	1                               # DW_CHILDREN_yes
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	7                               # Abbreviation Code
	.byte	22                              # DW_TAG_typedef
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	8                               # Abbreviation Code
	.byte	8                               # DW_TAG_imported_declaration
	.byte	0                               # DW_CHILDREN_no
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	24                              # DW_AT_import
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	9                               # Abbreviation Code
	.byte	2                               # DW_TAG_class_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	60                              # DW_AT_declaration
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	0                               # EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.long	.Ldebug_info_end0-.Ldebug_info_start0 # Length of Unit
.Ldebug_info_start0:
	.short	5                               # DWARF version number
	.byte	1                               # DWARF Unit Type
	.byte	8                               # Address Size (in bytes)
	.long	.debug_abbrev                   # Offset Into Abbrev. Section
	.byte	1                               # Abbrev [1] 0xc:0xda DW_TAG_compile_unit
	.byte	0                               # DW_AT_producer
	.short	33                              # DW_AT_language
	.byte	1                               # DW_AT_name
	.long	.Lstr_offsets_base0             # DW_AT_str_offsets_base
	.long	.Lline_table_start0             # DW_AT_stmt_list
	.byte	2                               # DW_AT_comp_dir
	.byte	0                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.long	.Laddr_table_base0              # DW_AT_addr_base
	.byte	2                               # Abbrev [2] 0x23:0x4 DW_TAG_base_type
	.byte	3                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	4                               # DW_AT_byte_size
	.byte	3                               # Abbrev [3] 0x27:0x5 DW_TAG_pointer_type
	.long	44                              # DW_AT_type
	.byte	3                               # Abbrev [3] 0x2c:0x5 DW_TAG_pointer_type
	.long	49                              # DW_AT_type
	.byte	2                               # Abbrev [2] 0x31:0x4 DW_TAG_base_type
	.byte	4                               # DW_AT_name
	.byte	6                               # DW_AT_encoding
	.byte	1                               # DW_AT_byte_size
	.byte	2                               # Abbrev [2] 0x35:0x4 DW_TAG_base_type
	.byte	5                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	8                               # DW_AT_byte_size
	.byte	4                               # Abbrev [4] 0x39:0x43 DW_TAG_subprogram
	.byte	0                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.byte	17                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	14                              # DW_AT_decl_line
                                        # DW_AT_external
	.byte	5                               # Abbrev [5] 0x44:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	120
	.byte	18                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	15                              # DW_AT_decl_line
	.long	224                             # DW_AT_type
	.byte	5                               # Abbrev [5] 0x4f:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	116
	.byte	19                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	18                              # DW_AT_decl_line
	.long	35                              # DW_AT_type
	.byte	5                               # Abbrev [5] 0x5a:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	104
	.byte	20                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	19                              # DW_AT_decl_line
	.long	39                              # DW_AT_type
	.byte	5                               # Abbrev [5] 0x65:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	96
	.byte	21                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	20                              # DW_AT_decl_line
	.long	39                              # DW_AT_type
	.byte	5                               # Abbrev [5] 0x70:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	92
	.byte	22                              # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	23                              # DW_AT_decl_line
	.long	35                              # DW_AT_type
	.byte	0                               # End Of Children Mark
	.byte	6                               # Abbrev [6] 0x7c:0x1b DW_TAG_namespace
	.byte	6                               # DW_AT_name
	.byte	7                               # Abbrev [7] 0x7e:0x8 DW_TAG_typedef
	.long	151                             # DW_AT_type
	.byte	8                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	234                             # DW_AT_decl_line
	.byte	7                               # Abbrev [7] 0x86:0x8 DW_TAG_typedef
	.long	151                             # DW_AT_type
	.byte	9                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	241                             # DW_AT_decl_line
	.byte	7                               # Abbrev [7] 0x8e:0x8 DW_TAG_typedef
	.long	173                             # DW_AT_type
	.byte	12                              # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	240                             # DW_AT_decl_line
	.byte	0                               # End Of Children Mark
	.byte	7                               # Abbrev [7] 0x97:0x8 DW_TAG_typedef
	.long	53                              # DW_AT_type
	.byte	7                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	31                              # DW_AT_decl_line
	.byte	8                               # Abbrev [8] 0x9f:0x7 DW_TAG_imported_declaration
	.byte	1                               # DW_AT_decl_file
	.byte	236                             # DW_AT_decl_line
	.long	126                             # DW_AT_import
	.byte	8                               # Abbrev [8] 0xa6:0x7 DW_TAG_imported_declaration
	.byte	1                               # DW_AT_decl_file
	.byte	243                             # DW_AT_decl_line
	.long	134                             # DW_AT_import
	.byte	7                               # Abbrev [7] 0xad:0x8 DW_TAG_typedef
	.long	181                             # DW_AT_type
	.byte	11                              # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	34                              # DW_AT_decl_line
	.byte	2                               # Abbrev [2] 0xb5:0x4 DW_TAG_base_type
	.byte	10                              # DW_AT_name
	.byte	7                               # DW_AT_encoding
	.byte	8                               # DW_AT_byte_size
	.byte	8                               # Abbrev [8] 0xb9:0x7 DW_TAG_imported_declaration
	.byte	1                               # DW_AT_decl_file
	.byte	244                             # DW_AT_decl_line
	.long	142                             # DW_AT_import
	.byte	6                               # Abbrev [6] 0xc0:0x11 DW_TAG_namespace
	.byte	13                              # DW_AT_name
	.byte	8                               # Abbrev [8] 0xc2:0x7 DW_TAG_imported_declaration
	.byte	2                               # DW_AT_decl_file
	.byte	133                             # DW_AT_decl_line
	.long	211                             # DW_AT_import
	.byte	8                               # Abbrev [8] 0xc9:0x7 DW_TAG_imported_declaration
	.byte	3                               # DW_AT_decl_file
	.byte	11                              # DW_AT_decl_line
	.long	211                             # DW_AT_import
	.byte	0                               # End Of Children Mark
	.byte	6                               # Abbrev [6] 0xd1:0x5 DW_TAG_namespace
	.byte	14                              # DW_AT_name
	.byte	9                               # Abbrev [9] 0xd3:0x2 DW_TAG_class_type
	.byte	15                              # DW_AT_name
                                        # DW_AT_declaration
	.byte	0                               # End Of Children Mark
	.byte	6                               # Abbrev [6] 0xd6:0xa DW_TAG_namespace
	.byte	16                              # DW_AT_name
	.byte	8                               # Abbrev [8] 0xd8:0x7 DW_TAG_imported_declaration
	.byte	2                               # DW_AT_decl_file
	.byte	140                             # DW_AT_decl_line
	.long	211                             # DW_AT_import
	.byte	0                               # End Of Children Mark
	.byte	3                               # Abbrev [3] 0xe0:0x5 DW_TAG_pointer_type
	.long	53                              # DW_AT_type
	.byte	0                               # End Of Children Mark
.Ldebug_info_end0:
	.section	.debug_str_offsets,"",@progbits
	.long	96                              # Length of String Offsets Set
	.short	5
	.short	0
.Lstr_offsets_base0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"clang version 21.0.0git (https://github.com/llvm/llvm-project.git 0e457315f55889878ccbc3e35d4beb04e277733f)" # string offset=0
.Linfo_string1:
	.asciz	"lib/fuck_start.cc"             # string offset=108
.Linfo_string2:
	.asciz	"/tmp"                          # string offset=126
.Linfo_string3:
	.asciz	"int"                           # string offset=131
.Linfo_string4:
	.asciz	"char"                          # string offset=135
.Linfo_string5:
	.asciz	"long"                          # string offset=140
.Linfo_string6:
	.asciz	"std"                           # string offset=145
.Linfo_string7:
	.asciz	"int64_t"                       # string offset=149
.Linfo_string8:
	.asciz	"ptrdiff_t"                     # string offset=157
.Linfo_string9:
	.asciz	"ssize_t"                       # string offset=167
.Linfo_string10:
	.asciz	"unsigned long"                 # string offset=175
.Linfo_string11:
	.asciz	"uint64_t"                      # string offset=189
.Linfo_string12:
	.asciz	"size_t"                        # string offset=198
.Linfo_string13:
	.asciz	"sys"                           # string offset=205
.Linfo_string14:
	.asciz	"str"                           # string offset=209
.Linfo_string15:
	.asciz	"c_str"                         # string offset=213
.Linfo_string16:
	.asciz	"itr"                           # string offset=219
.Linfo_string17:
	.asciz	"_fuck_start"                   # string offset=223
.Linfo_string18:
	.asciz	"sp"                            # string offset=235
.Linfo_string19:
	.asciz	"argc"                          # string offset=238
.Linfo_string20:
	.asciz	"argv"                          # string offset=243
.Linfo_string21:
	.asciz	"envp"                          # string offset=248
.Linfo_string22:
	.asciz	"ret"                           # string offset=253
	.section	.debug_str_offsets,"",@progbits
	.long	.Linfo_string0
	.long	.Linfo_string1
	.long	.Linfo_string2
	.long	.Linfo_string3
	.long	.Linfo_string4
	.long	.Linfo_string5
	.long	.Linfo_string6
	.long	.Linfo_string7
	.long	.Linfo_string8
	.long	.Linfo_string9
	.long	.Linfo_string10
	.long	.Linfo_string11
	.long	.Linfo_string12
	.long	.Linfo_string13
	.long	.Linfo_string14
	.long	.Linfo_string15
	.long	.Linfo_string16
	.long	.Linfo_string17
	.long	.Linfo_string18
	.long	.Linfo_string19
	.long	.Linfo_string20
	.long	.Linfo_string21
	.long	.Linfo_string22
	.section	.debug_addr,"",@progbits
	.long	.Ldebug_addr_end0-.Ldebug_addr_start0 # Length of contribution
.Ldebug_addr_start0:
	.short	5                               # DWARF version number
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
.Laddr_table_base0:
	.quad	.Lfunc_begin0
.Ldebug_addr_end0:
	.ident	"clang version 21.0.0git (https://github.com/llvm/llvm-project.git 0e457315f55889878ccbc3e35d4beb04e277733f)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym main
	.section	.debug_line,"",@progbits
.Lline_table_start0:

cmake_minimum_required(VERSION 3.7.2)
project(corewar)

set(CMAKE_C_STANDARD 90)

execute_process(COMMAND make -C ../libft)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES
		src/globals.c
		src/helpers.c)
set(HEADERS
		includes/globals.h
		includes/structs.h)

set(VM_FILES ${SOURCE_FILES}
		vm/src/main.c
		vm/src/vm_read_input/read_player.c
		vm/src/vm_workcycle/vm_initialization.c
		vm/src/vm_workcycle/vm_memory_ops.c
        vm/src/vm_globals.c
		vm/src/vm_workcycle/vm_lst_accessors.c
		vm/src/vm_workcycle/vm_workcycle.c
		vm/src/vm_workcycle/vm_free_memory.c
		vm/src/vm_workcycle/vm_printing.c
		vm/src/vm_workcycle/vm_process_execution.c
		vm/src/vm_workcycle/vm_instructions_funcs.c
		vm/src/vm_workcycle/vm_cycling.c
		vm/src/vm_workcycle/vm_processes.c
		vm/src/vis/vm_vis.c
		vm/src/vis/vis_init.c
		vm/src/vis/vis_helpers.c
		vm/src/vis/vis_draw.c
		vm/src/vm_read_input/get_player.c
		vm/src/vm_read_input/parse_arg.c
        vm/src/vm_read_input/validate.c
		vm/src/vis/vis_labels.c
		vm/src/vis/vis_keys.c
		vm/src/vis/vis_debug.c
		vm/src/vm_read_input/error_handlers.c
		vm/src/vm_read_input/read_input_globals.c
		vm/src/vm_workcycle/vm_instruction_helpers.c
		vm/src/vm_workcycle/vm_proc_exec_helpers.c vm/src/vis/vis_debug_init.c vm/src/vis/vis_debug_draw.c)

set(VM_HEADERS ${HEADERS}
		vm/includes/vm.h
		vm/includes/vm.h
		vm/includes/vm_initialization.h
		vm/includes/vm_structs.h
		vm/includes/vm_globals.h
		vm/includes/vm_process_execution.h
		vm/includes/vm_workcycle.h
		vm/includes/vm_vis.h
		vm/src/vm_read_input/read_input_globals.c
		vm/src/vm_read_input/error_handlers.c
		vm/includes/read_input.h
		vm/includes/vm_memory_ops.h)

set(ASM_FILES ${SOURCE_FILES}
		asm_f/src/asm_main.c
		asm_f/src/asm_globals.c
		asm_f/src/asm_lst_accessors.c
		asm_f/src/parser/asm_errors.c
		asm_f/src/lexer/asm_break_line.c
		asm_f/src/lexer/asm_extract_token.c
		asm_f/src/parser/parse_all_tokens.c
		asm_f/src/parser/asm_parse_lexical.c
		asm_f/src/parser/asm_parse_syntax.c
		asm_f/src/parser/parse_all_tokens.c
        asm_f/src/asm_shell_for_trim.c
        asm_f/src/lexer/asm_save_comment_or_name_champ.c
		asm_f/src/parser/asm_parse_syntax.c
		asm_f/src/parser/asm_search_same_label.c
		asm_f/src/translator/asm_initialization.c
		asm_f/src/parser/asm_search_same_label.c
		asm_f/src/translator/asm_initialization.c
        asm_f/src/lexer/asm_split_file_into_tokens.c
		asm_f/src/translator/asm_file_to_bytecode.c
		asm_f/src/parser/asm_parse_syntax_helper.c
		asm_f/src/translator/asm_add_inst_cmd.c
        asm_f/src/translator/create_champion_code.c
		asm_f/src/translator/translate_one_instr_to_bytecode.c 
		asm_f/src/translator/put_byte_args_to_instr.c
		asm_f/src/translator/create_dictionary_lables.c
		asm_f/src/translator/add_direct_value_to_instruction.c
		asm_f/src/free_struct_func.c
		asm_f/src/operation_with_file.c
		asm_f/src/asm_free_memory.c asm_f/src/asm_free_memory_add.c)

set(ASM_HEADERS ${HEADERS}
		asm_f/includes/asm.h
		asm_f/includes/asm_globals.h
		asm_f/includes/asm_structs.h
		asm_f/includes/asm_parser.h
		asm_f/includes/asm_translator.h
		asm_f/includes/asm_lexer.h)

set(DISASM_HEADERS ${HEADERS}
		disasm_f/includes/disasm.h)

set(DISASM_FILES ${SOURCE_FILES}
		vm/src/vm_read_input/read_player.c
		vm/src/vm_workcycle/vm_initialization.c
		vm/src/vm_workcycle/vm_memory_ops.c
		vm/src/vm_globals.c
		vm/src/vm_workcycle/vm_lst_accessors.c
		vm/src/vm_workcycle/vm_workcycle.c
		vm/src/vm_workcycle/vm_free_memory.c
		vm/src/vm_workcycle/vm_printing.c
		vm/src/vm_workcycle/vm_process_execution.c
		vm/src/vm_workcycle/vm_instructions_funcs.c
		vm/src/vm_workcycle/vm_cycling.c
		vm/src/vm_workcycle/vm_processes.c
		vm/src/vis/vm_vis.c
		vm/src/vis/vis_init.c
		vm/src/vis/vis_helpers.c
		vm/src/vis/vis_draw.c
		vm/src/vm_read_input/get_player.c
		vm/src/vm_read_input/parse_arg.c
		vm/src/vm_read_input/validate.c
		vm/src/vis/vis_labels.c
		vm/src/vis/vis_keys.c
		vm/src/vis/vis_debug.c
		vm/src/vm_read_input/error_handlers.c
		vm/src/vm_read_input/read_input_globals.c
		vm/src/vm_workcycle/vm_instruction_helpers.c
		vm/src/vm_workcycle/vm_proc_exec_helpers.c vm/src/vis/vis_debug_init.c vm/src/vis/vis_debug_draw.c
		disasm_f/src/disasm_main.c
		disasm_f/src/disassemble.c
		disasm_f/src/free_memory.c disasm_f/src/funcs_helpers.c)

include_directories(asm_f/includes)
include_directories(vm/includes)
include_directories(disasm_f/includes)
include_directories(includes)
include_directories(libft/includes) # header directories
link_directories(libft) # library directories

add_executable(corewar ${VM_FILES} ${VM_HEADERS})
add_executable(asm ${ASM_FILES} ${ASM_HEADERS})
add_executable(disasm ${DISASM_FILES} ${DISASM_HEADERS})

set_target_properties(corewar PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY})
set_target_properties(asm PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY})
set_target_properties(disasm PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY})

# linkage
target_link_libraries(corewar -lft -lncurses)
target_link_libraries(asm -lft)
target_link_libraries(disasm -lft -lncurses)

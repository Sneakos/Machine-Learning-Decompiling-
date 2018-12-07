import os

def mass_compile_gcc():

	base_directory = os.getcwd()
	base_directory = base_directory + "\\"
	source_code_path = base_directory + 'Mass Compiler\\Source Code\\'
	executable_path = base_directory + 'Mass Compiler\\GCC Executables\\'

	if len(os.listdir(source_code_path)) == 0:
		print("Please place c files into the source code directory located in the mass compiler directory.")
		return 0

	print("--------GCC Compiling will begin shortly--------")
	gcc_path = "C:\\MinGW\\bin\\gcc.exe "

	# compile with GCC
	# os.chdir("C:\\MinGW\\bin")
	for file in os.listdir(source_code_path):
	    command_string = gcc_path + "\"" + source_code_path + file + "\""
	    command_string += " -o "
	    command_string += ("\"" + executable_path + file[:-2] +'_gcc' +"\"")
	    # print(command_string)

	    os.system(command_string)
	    
	    print("----------------" + str(file[:-2]) + ".exe" + "----------------------------")

	print("If there were issues compiling you will see errors under the executable name.")
	print("Otherwise your " + str(len(os.listdir(source_code_path))) + " executables will be located in \\Mass Compiler\\GCC Executables")
	print("---------------------------------------------------------------------------")
	return 1


def mass_compile_clang():

	base_directory = os.getcwd()
	base_directory = base_directory + "\\"
	source_code_path = base_directory + 'Mass Compiler\\Source Code\\'
	executable_path = base_directory + 'Mass Compiler\\Clang Executables\\'

	clang_path = '"C:\\Program Files\\LLVM\\bin\\clang.exe" '

	if len(os.listdir(source_code_path)) == 0:
		print("Please place c files into the source code directory located in the mass compiler directory.")
		return 0

	print("--------Clang Compiling will begin shortly--------")
	os.chdir("C:\\Program Files\\LLVM\\bin")

	# compile with GCC
	for file in os.listdir(source_code_path):
		command_string = ''
		command_string += 'clang'  # path to clang with quotes
		command_string += (' "' + source_code_path + file + '" ')  # path to source code with quotes
		command_string += '--output '
		command_string += ("\"" + executable_path + file[:-2] +'_clang' + '.exe ' + "\"")
		# command_string += '"'
		# print(command_string)

		print("-----" + str(file[:-2]) + ".exe" + "-----" )
		os.system(command_string)

	print("If there were issues compiling you will see errors under the executable name.")
	print("Otherwise your " + str(len(os.listdir(source_code_path))) + " executables will be located in \\Mass Compiler\\Clang Executables")
	print("---------------------------------------------------------------------------")

	os.chdir(base_directory)
	return 1
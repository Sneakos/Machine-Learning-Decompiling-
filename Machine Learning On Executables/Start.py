import os
import pefile
from Functions.Pe_Functions import get_text, strip_text_directory
from Functions.Mass_Compiler import mass_compile_gcc, mass_compile_clang
from Functions.Prediction import predict_compiler

clear_function = lambda: os.system('cls')
cmd = ''
exit_commands = ['exit', 'quit', 'stop', 'q']

logo = open('Logo.txt', 'r+')
for l in logo.readlines():
	print(l,end='')
logo.close()

while cmd not in exit_commands:
	cmd = input('[*]')
	cmd = cmd.lower()  # functions are case insensitive
	
	if cmd == 'clear':
		clear_function()

	elif cmd == 'mass compile':
		compiler = ''
		print("Which compiler do you want (clang, gcc, both)?")
		compiler = input('   [*Compiler->]')

		if compiler == 'clang':
			mass_compile_clang()

		elif compiler == 'gcc':
			mass_compile_gcc()

		elif compiler == 'both':
			mass_compile_clang()
			mass_compile_gcc()
		else:
			print("[!] That is not a recognized compiler")

	elif cmd == 'strip text':
		directory = input('   [*directory->]')
		strip_text_directory(directory)

	elif cmd == 'detect compiler':
		directory = input('   [*Path->]')
		predict_compiler(directory)

	elif cmd == 'help':
		help_file = open('Function_Help.txt', 'r+')
		for l in help_file.readlines():
			print(l, end='')

		help_file.close()

	elif cmd in exit_commands:
		pass

	else:
		print("[!] Unknown Command")
		help_file = open('Function_Help.txt', 'r+')
		for l in help_file.readlines():
			print(l, end='')

		help_file.close()

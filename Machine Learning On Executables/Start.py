import os
import pefile
from Functions.Pe_Functions import get_text, strip_text_directory
from Functions.Mass_Compiler import mass_compile_gcc, mass_compile_clang

clear_function = lambda: os.system('cls')
cmd = ''
exit_commands = ['exit', 'quit', 'stop', 'q']

while cmd not in exit_commands:
	cmd = input('[*]')
	
	if cmd == 'clear':
		clear_function()

	elif cmd == 'mass compile':
		compiler = ''
		print("Which compiler do you want (clang, gcc, both)?")
		compiler = input('  [*Compiler->]')

		if compiler == 'clang':
			mass_compile_clang()

		elif compiler == 'gcc':
			mass_compile_gcc()

		elif compiler == 'both':
			mass_compile_clang()
			mass_compile_gcc()
		else:
			print("[!] That is not a recognized compiler")

	elif cmd in exit_commands:
		pass

	else:
		# clear_function()
		print("[!] Unknown Command")

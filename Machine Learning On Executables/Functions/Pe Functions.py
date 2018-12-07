import pefile
import os

def get_text(exe_file):
	data = []
	print(os.getcwd())

	pe = pefile.PE(exe_file)
	for b in pe.sections[0].get_data():
		data.append(hex(b))

	return data
	
print(get_text("C:\\Users\\Herbie\\Desktop\\ForLoop.exe"))
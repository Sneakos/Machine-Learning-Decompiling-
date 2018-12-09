import pefile
import os

def get_text(exe_file):
	data = []
	location = os.getcwd() + '\\Pe File Data\\'
	file_name = str(exe_file) + "_text_section"
	file_name = file_name.split("\\")

	file_name = location + str(file_name[-1])

	pe = pefile.PE(exe_file)
	for b in pe.sections[0].get_data():
		data.append(hex(b))

	print("The .text section is " + str(len(data)) + " bytes long.")
	data = ' '.join(data)

	save_file = open(file_name + ".txt", 'w')
	save_file.write(data)
	save_file.close()

	print("The data is saved to: ")
	print(file_name)
	return data

def strip_text_directory(dir):
	if os.path.isdir(dir):
		d = dir
		dir_name = d.split('\\')
		dir_name = dir_name[-1]
		new_dir = os.getcwd() + '\\Pe File Data\\' + dir_name

		if not os.path.isdir(new_dir):
			os.mkdir(new_dir)

		for i in os.listdir(dir):
			# print(i)
			data = []
			location = dir
			file_name = str(i) + "_text_section"
			file_name = file_name.split("\\")

			file_name = str(file_name[-1])

			try:
				pe = pefile.PE(dir + "\\" + i)

				for b in pe.sections[0].get_data():
					data.append(hex(b))

				data = ' '.join(data)

				save_file = open(new_dir + "\\" +  file_name + ".txt", 'w')
				save_file.write(data)
				save_file.close()

				print("The data is saved to: ")
				print(file_name)
			except:
				print("There are invalid files in the directory. Make sure all are PE files.")
				break
	else:
		print("This is not a valid directory.")

# strip_text_directory('C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables')
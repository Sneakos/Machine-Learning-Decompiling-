import os

base_directory = "C:\\Users\\User\\Desktop\\Small C Dataset\\"

gcc_path = "C:\\MinGW\\bin\\gcc.exe "
vs_x86_path = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.15.26726\\bin\\Hostx86\\x86\\cl.exe"

# compile with GCC
os.chdir("C:\\MinGW\\bin")
for file in os.listdir(base_directory + '\\Source Code'):
    command_string = gcc_path + "\"" + base_directory + "Source Code\\" + file + "\""
    command_string += " -o "
    command_string += ("\"" + base_directory + "Gcc Executables\\" + file[:-2] + "\"")

    os.system(command_string)
    print(str(file[:-2]) + ".exe GCC" )
    print("--------------------------------------")

# compile with Visual Studio
# os.chdir("C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.15.26726\\bin\\Hostx86\\x86\\")
# for file in os.listdir(base_directory + '\\Source Code'):
#     command_string = 'cl.exe ' + '"' +base_directory +'Source Code\\' + file + '"'
#     print(command_string)
#     os.system(command_string)


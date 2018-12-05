import numpy as np
import os


def get_longest_sample():
    longest = 0
    for exe in os.listdir(exe_dir):
        e = open((exe_dir + "\\" + str(exe)), 'rb')
        bytes = []
        for b in e.read():
            bytes.append(b)
        # print(len(bytes))
        if len(bytes) > longest:
            longest = len(bytes)
    return longest

# global variables
exe_dir = 'C:\\Users\\User\\Desktop\\Executables'
num_samples = len(os.listdir(exe_dir))
longest_sample = get_longest_sample()
features = 1


def prepare_data():
    dataset = np.zeros((num_samples, longest_sample, features), dtype='float')

    for i, exe in enumerate(os.listdir(exe_dir)):
        executable = []
        file = open((exe_dir + "\\" + str(exe)), 'rb')
        for byte in file.read():
            executable.append((byte / 255.0))  # range between 0-1

        for j in range(longest_sample - len(executable)):
            executable.append((90 / 255.0))  # pad the exe with NOP instruction

        executable = np.reshape(executable, (longest_sample,1))
        dataset[i] = executable

    return dataset

dat = prepare_data()
for i in dat[5]:
    print(i)

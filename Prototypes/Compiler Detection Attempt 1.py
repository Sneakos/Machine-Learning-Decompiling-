# import keras
import os
import numpy as np
import random
from keras.layers import CuDNNLSTM, Embedding, Dropout, Dense
from keras import Sequential

def get_longest_sample(exe_dir):
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

# (class_0, class_1, number osf samples, length of longest sample, features)
def prepare_binary_data(exe_dir_0, exe_dir_1 ,n_samp, l_samp, l):

	features = 1
	dataset = np.zeros((n_samp, l_samp, features), dtype='float')

	for i, exe in enumerate(os.listdir(exe_dir_0)):
		executable = []
		file = open((exe_dir_0 + "\\" + str(exe)), 'rb')
		for byte in file.read():
			# executable.append((byte / 255.0))  # range between 0-1
			executable.append(byte)

		for j in range(l_samp - len(executable)):
			# executable.append((90 / 255.0))  # pad the exe with NOP instruction
			executable.append(90)

		executable = np.reshape(executable, (l_samp,1))
		dataset[i] = executable
		l.append(0)

	base = len(os.listdir(exe_dir_0))

	for i, exe in enumerate(os.listdir(exe_dir_1)):
		executable = []
		file = open((exe_dir_1 + "\\" + str(exe)), 'rb')
		for byte in file.read():
			# executable.append((byte / 255.0))  # range between 0-1
			executable.append(byte)

		for j in range(l_samp - len(executable)):
			# executable.append((90 / 255.0))  # pad the exe with NOP instruction
			executable.append(90)

		executable = np.reshape(executable, (l_samp,1))
		dataset[i + base] = executable
		l.append(1)

	return dataset

class_1_dir = 'C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables\\Mass Compiler\\Clang Executables'
class_0_dir = 'C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables\\Mass Compiler\\GCC Executables'

number_samples = len(os.listdir(class_0_dir)) + len(os.listdir(class_0_dir))

all_samples = []
lables = []
sample_len = 0
features = []

if get_longest_sample(class_0_dir) > get_longest_sample(class_1_dir):
	sample_len = get_longest_sample(class_0_dir)
else:
	sample_len = get_longest_sample(class_1_dir)

data = prepare_binary_data(class_0_dir, class_1_dir,number_samples ,sample_len, lables)

# shuffle the dataset
shuffle_data = np.zeros((number_samples, sample_len, 1), dtype='float')
shuffle_lables = []

shuffled_indexes = []

print(len(lables))


for i in range(number_samples):
	shuffled_indexes.append(i)

random.shuffle(shuffled_indexes)

for i, index in enumerate(shuffled_indexes):
	shuffle_lables.append(lables[shuffled_indexes[i]])
	shuffle_data[i] = data[shuffled_indexes[i]]


print(shuffle_data)
print(shuffle_lables)

shuffle_lables = np.asarray(shuffle_lables)
np.reshape(shuffle_lables, (1, number_samples))

print(shuffle_lables.shape)
shuffle_lables = np.reshape(shuffle_lables, (len(shuffle_lables), 1))


model = Sequential()

model.add(CuDNNLSTM(128, input_shape=(sample_len, 1), return_sequences=True))
model.add(CuDNNLSTM(128))
# model.add(CuDNNLSTM(128, input_shape=(sample_len, 1)))
model.add(Dropout(0.2))
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['binary_accuracy'])

model.summary()
model.fit(shuffle_data, shuffle_lables, epochs=10, batch_size=2)
model.save('attempt_1.h5')

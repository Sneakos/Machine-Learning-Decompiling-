import pefile
import os
import numpy as np
import random
from keras.layers import CuDNNLSTM, Embedding, Dropout, Dense, Conv1D, MaxPool1D, GlobalMaxPooling1D
from keras import Sequential
from keras import optimizers

dir_class_0 = 'C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables\\Mass Compiler\\Clang Executables'
dir_class_1 = 'C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables\\Mass Compiler\\GCC Executables'

data_set_len = len(os.listdir(dir_class_0)) + len(os.listdir(dir_class_1))

data_set = np.zeros((data_set_len, 1024))
labels = []

# class zero preparation
for i, exe in enumerate(os.listdir(dir_class_0)):
	pe = pefile.PE(dir_class_0 + '\\' + exe)

	h = []
	for b in pe.header:
		h.append(b)

	h = np.reshape(h, (1024))
	data_set[i] = h
	labels.append(0)

base = len(os.listdir(dir_class_0))

# class one preparation
for i, exe in enumerate(os.listdir(dir_class_1)):
	pe = pefile.PE(dir_class_1 + '\\' + exe)
	h = []
	for b in pe.header:
		h.append(b)

	h = np.reshape(h, (1024))
	data_set[i + base] = h
	labels.append(1)

shuffle_index = []
for i in range(data_set_len):
	shuffle_index.append(i)

random.shuffle(shuffle_index)


shuffle_lables = np.zeros((data_set_len))
shuffle_data = np.zeros((data_set_len, 1024))
for i, index in enumerate(shuffle_index):
	shuffle_lables[i] = labels[shuffle_index[i]]
	shuffle_data[i] = data_set[shuffle_index[i]]

print(shuffle_data.shape)
print(len(shuffle_lables))
print(type(labels))
print(type(labels[0]))

optimizers.Adam(lr=0.001, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)

model = Sequential()

model.add(Embedding(256, 128, input_length=1024))
model.add(Conv1D(16, 3, activation='relu'))
model.add(MaxPool1D(5))
model.add(Conv1D(16, 3, activation='relu'))
model.add(GlobalMaxPooling1D())
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='binary_crossentropy',optimizer='adam', metrics=['accuracy'])
print(model.layers[0].get_weights()[0])

# exit()
model.fit(x=shuffle_data, y=shuffle_lables, batch_size=1, epochs=5)

path = 'C:\\Users\\Herbie\\Desktop\\Validation Set\\GCD_clang.exe'
pe = pefile.PE(path)
h = []

for i, b in enumerate(pe.header):
	h.append(b)

h = np.reshape(h, (1, 1024))

print(h.shape)

model.summary()

print(path)
print("Class 0 - Clang")
print("Class 1 - GCC")

print(model.predict(h))

model.save('Covnet.h5')

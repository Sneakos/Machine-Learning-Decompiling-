# from keras import Model, Sequential
# from keras.layers import LSTM, Dense
import numpy as np

samples = 2
sample_len = 0
len_added = 0

f = open('Hello.exe', 'rb')
exe_1 = []

for b in f.read():
    exe_1.append(int(b) / 255.0)

f = open('Hello2.exe', 'rb')
exe_2 = []

for b in f.read():
    exe_2.append(int(b)/255.0)

if len(exe_1) > len(exe_2):
    sample_len = len(exe_1)
else:
    sample_len = len(exe_2)

print(len(exe_1))
print(len(exe_2))

exe_1.append(int(0x90) / 255.0)
exe_1.append(int(0x90) / 255.0)

model_input = np.zeros((samples, sample_len, 1),dtype='int16')

exe_1 = np.reshape(exe_1,(len(exe_1),1))
exe_2 = np.reshape(exe_2,(len(exe_2),1))

print(np.shape(exe_1))
print(model_input[0].shape)

model_input[0] = exe_1
model_input[1] = exe_2

print(model_input[1])

print(model_input.shape)

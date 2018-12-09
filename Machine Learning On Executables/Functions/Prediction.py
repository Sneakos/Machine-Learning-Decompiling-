from keras.models import load_model
import pefile
import numpy as np


def predict_compiler(exe_path):
	pe = pefile.PE(exe_path)
	h = []

	for i, b in enumerate(pe.header):
		h.append(b)

	h = np.reshape(h, (1, 1024))

	model = load_model('C:\\Users\\Herbie\\Desktop\\Machine Learning On Executables\\ML Models\\Binary Classification\\Compiler Prediction.h5')

	d = model.predict(h)

	if d[0][0] > .7:
		print('This exe is GCC - (confidence: ' + str(d[0][0]) + ')')
	elif d[0][0] < .3:
		print('This exe is clang - (confidence: ' + str(1 - d[0][0]) + ')')
	else:
		print()

import serial
ser_input = serial.Serial('/dev/ttyACM0', 9600)

while 1: 
	if (ser_input.inWaiting()>0):
		data = ser_input.readline()
		print data
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
#timeout = 0.5

while 1: 

	#start = time.time()
	#while (time.time() - start < timeout):
	ser.write("a")
	print "forward"
	#print (ser.readline())
	time.sleep(5)
	start = time.time()
	#while (time.time() - start < timeout):
	ser.write("b")
	print "backward"
	#print (ser.readline())
	time.sleep(5)
	start = time.time()
	#while (time.time() - start < timeout):
	ser.write("c")
	print "left"
	#print (ser.readline())
	time.sleep(5)
	start = time.time()
	#while (time.time() - start < timeout):
	ser.write("d")
	print "right"
	#print (ser.readline())
	time.sleep(5)

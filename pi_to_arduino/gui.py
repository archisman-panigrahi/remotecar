import serial
try:
        import RPi.GPIO as GPIO
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(3,GPIO.OUT)
        p = GPIO.PWM(3,100)
        p.start(40)
except ImportError:
        print ("Cannot import GPIO. Are you on Raspi?")
try:
	import tkinter as tk
	from tkinter import *
except ImportError:
	import Tkinter as tk
	from Tkinter import *



ser = serial.Serial('/dev/ttyACM0', 9600)

def forward():
	ser.write("a")
	if (w1.get() == 0):
            w1.set(20)
            speed(20)
	print ("forward")
def backward():
	ser.write("b")
	if (w1.get() == 0):
            w1.set(20)
            speed(20)
	print ("backward")
def left():
	ser.write("c")
	if (w1.get() == 0):
            w1.set(20)
            speed(20)
	print ("left")
def right():
	ser.write("d")
	if (w1.get() == 0):
            w1.set(20)
            speed(20)
	print ("right")
def speed(val):
	print (val)
        p.start(float(val))
def stop():
	speed(0)
	w1.set(0)

root = tk.Tk()
root.title("		Direction		")

frame = tk.Frame(root)
frame.pack()

slogan = tk.Button(frame,
                   text="Forward",
                   fg="black",
                   height="10",
                   width="15",
                   command=forward)
slogan.pack(side=tk.TOP)

slogan = tk.Button(frame,
                   text="Backward",
                   fg="black",
                   height="10",
                   width="15",
                   command=backward)
slogan.pack(side=tk.BOTTOM)

slogan = tk.Button(frame,
                   text="Left",
                   fg="blue",
                   height="10",
                   width="15",
                   command=left)
slogan.pack(side=tk.LEFT)

slogan = tk.Button(frame,
                   text="Right",
                   fg="green",
                   height="10",
                   width="15",
                   command=right)
slogan.pack(side=tk.RIGHT)

slogan = tk.Button(frame,
                   text="Stop",
                   fg="red",
                   height="10",
                   width="15",
                   command=stop)
slogan.pack(side=tk.BOTTOM)

root.update()
width = root.winfo_width()

w1 = Scale(root, from_=0, to=100,length = 0.8*width, tickinterval=10, orient=HORIZONTAL,command=speed)
w1.set(40)
w1.pack()

root.mainloop()

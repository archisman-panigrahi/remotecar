import serial
try:
	import tkinter as tk
except ImportError:
	import Tkinter as tk

from Tkinter import *
ser = serial.Serial('/dev/ttyACM0', 9600)

def forward():
	ser.write("a")
	print ("forward")
def backward():
	ser.write("b")
	print ("backward")
def left():
	ser.write("c")
	print ("left")
def right():
	ser.write("d")
	print ("right")
def speed(val):
	print (val)
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
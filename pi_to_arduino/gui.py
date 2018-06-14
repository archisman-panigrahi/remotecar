import serial
try:
	import tkinter as tk
except ImportError:
	import Tkinter as tk

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

root = tk.Tk()
root.title("		Direction		")
frame = tk.Frame(root)
frame.pack()


slogan = tk.Button(frame,
                   text="Forward",
                   fg="red",
                   command=forward)
slogan.pack(side=tk.LEFT)
slogan = tk.Button(frame,
                   text="Backward",
                   fg="green",
                   command=backward)
slogan.pack(side=tk.LEFT)
slogan = tk.Button(frame,
                   text="Left",
                   fg="blue",
                   command=left)
slogan.pack(side=tk.LEFT)
slogan = tk.Button(frame,
                   text="Right",
                   fg="yellow",
                   command=right)
slogan.pack(side=tk.LEFT)

root.mainloop()
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
                   height="10",
                   width="15",
                   command=forward)
slogan.pack(side=tk.TOP)
slogan = tk.Button(frame,
                   text="Backward",
                   fg="green",
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
                   fg="violet",
                   height="10",
                   width="15",
                   command=right)
slogan.pack(side=tk.RIGHT)

root.mainloop()
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
def center(win):
        """
        centers a tkinter window
        :param win: the root or Toplevel window to center
        """
        win.update_idletasks()
        width = win.winfo_width()
        frm_width = win.winfo_rootx() - win.winfo_x()
        win_width = width + 2 * frm_width
        height = win.winfo_height()
        titlebar_height = win.winfo_rooty() - win.winfo_y()
        win_height = height + titlebar_height + frm_width
        x = win.winfo_screenwidth() // 2 - win_width // 2
        y = win.winfo_screenheight() // 2 - win_height // 2
        win.geometry('{}x{}+{}+{}'.format(width, height, x, y))
        win.deiconify()
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
                   height="15",
                   width="22",
                   command=forward)
slogan.pack(side=tk.TOP)

slogan = tk.Button(frame,
                   text="Backward",
                   fg="black",
                   height="15",
                   width="22",
                   command=backward)
slogan.pack(side=tk.BOTTOM)

slogan = tk.Button(frame,
                   text="Left",
                   fg="blue",
                   height="15",
                   width="22",
                   command=left)
slogan.pack(side=tk.LEFT)

slogan = tk.Button(frame,
                   text="Right",
                   fg="green",
                   height="15",
                   width="22",
                   command=right)
slogan.pack(side=tk.RIGHT)

slogan = tk.Button(frame,
                   text="Stop",
                   fg="red",
                   height="15",
                   width="22",
                   command=stop)
slogan.pack(side=tk.BOTTOM)

root.update()
width = root.winfo_width()

w1 = Scale(root, from_=0, to=100,length = 0.8*width, width = width/5, tickinterval=10, orient=HORIZONTAL,command=speed)
w1.set(40)
w1.pack()
center(root)
root.mainloop()

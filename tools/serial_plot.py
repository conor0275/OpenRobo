import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3',115200)

data=[]

while True:
    line = ser.readline().decode()
    try:
        val = float(line)
        data.append(val)

        if len(data)>100:
            data.pop(0)

        plt.clf()
        plt.plot(data)
        plt.pause(0.01)

    except:
        pass
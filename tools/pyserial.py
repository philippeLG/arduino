#!/usr/bin/python
import serial
ser = serial.Serial('/dev/ttyUSB0', 9600)
while 1:
  val = int(ser.read(15))
  print val


import numpy as np

import cv2

import serial

face_cascade = cv2.CascadeClassifier('tennisballdetect.xml')

cap = cv2.VideoCapture(0)

while 1:

ret, img = cap.read()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray, 1.3, 5)

print(faces)

    for (x, y, w, h) in faces:

    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

detect=(x+y)/2

    print(detect)

cv2.imshow('img', img)

k = cv2.waitKey(30) & 0xff

if k == 27:

    break

cap.release()

cv2.destroyAllWindows()

# Module -2: Trigger Pyserial

if detect > 0:

     ser = serial.Serial('COM1', 9600)

     print(ser)

     ser.write('Y')

else:

   ser = serial.Serial('COM1', 9600)

   print(ser)

   ser.write('N')

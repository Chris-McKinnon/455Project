import cv2

face_detect = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

cap = cv2.VideoCapture(0)

while cap.isOpened():
    (_,frame) = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    face=0
    face_detected=0
    area=0
    i=0
    faces = face_detect.detectMultiScale(gray,1.1, 4 )
    for (x,y, w, h) in faces:
        if h*w > area:
            face_detected=1
            area = h*w
            face=(x,y,w,h)
        i+=1
   # print(frame.shape)

    if face_detected != 0:
        x,y,w,h = face
        middle_face = (x+x+w)/2
        if abs(middle_face-(640/2))<20:
            print("shoot")
    
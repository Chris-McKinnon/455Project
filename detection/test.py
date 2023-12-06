import cv2

cam = cv2.VideoCapture(0)

while True:
	(ret,frame) = cam.read()
	cv2.imshow("Preview",frame)
	
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
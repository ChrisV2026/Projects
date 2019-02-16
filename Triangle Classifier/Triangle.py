#Christopher Vishnu
#October 16th 2105
#Length of each side
#Slope of each side
#Find perimeter
#Find area
#Classify the triangle
#Test data x1 = -5, y1 = -3, x2 = 6, y2 = 10, x3 = 7, y3 = -2

def length (a,b):
   return (a**2 + b **2)**0.5

def distance(x1, y1, x2, y2):
   return length(x2-x1, y2-y1)

def slope(x1, y1, x2 ,y2):
   return (y2 - y1) / (x2 - x1)

def triPerimeter(x1,y1,x2,y2,x3,y3):
   return distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3)

def triArea(a, b, c):
    return (((a + b + c) / 2) * ((b + c - a) / 2) * ((a + c - b) / 2) * ((a + b - c) / 2)) ** 0.5

##def radtodeg(angle):
##    length = len(angle)
##    num1 = float(angle[1:18])
##    num2 = float(angle[19:length - 2])     
##    angle = math.degrees(num1 - num2)

    
def main():
   import cmath
   import math
   ma = 0
   mb = 0
   mc = 0
   
   while ma == mb and ma == mc:
       x1 = float(input("Please input coordinate x1 "))
       y1 = float(input("Please input coordinate y1 "))
       x2 = float(input("Please input coordinate x2 "))
       y2 = float(input("Please input coordinate y2 "))
       x3 = float(input("Please input coordinate x3 "))
       y3 = float(input("Please input coordinate y3 "))

       if x2 - x1 != 0 and x3 - x2 != 0 and x1 - x3 != 0:  
          ma = slope(x1, y1, x2, y2)
          mb = slope(x2, y2, x3 , y3)
          mc = slope(x3, y3, x1, y1)
          if ma == mb and ma == mc:
              print("This is collinear and does not form a triangle")
              print ("Please re-enter your coordinates")
              print ("")
   
   a = distance(x1,y1,x2,y2)
   b = distance(x2,y2,x3,y3)
   c = distance(x3,y3,x1,y1)
   P = triPerimeter(x1,y1,x2,y2,x3,y3)
   A = triArea(a, b, c)

   anglea = str(cmath.acos((b**2 + c**2 - a**2) / (2*b*c)))
   angleb = str(cmath.acos((a**2 + c** 2 - b**2) / (2*a*c)))
   anglec = str(cmath.acos((a**2 + b**2 - c**2) / (2*a*b)))

##   anglea = radtodeg(anglea)
##   angleb = radtodeg(angleb)
##   anglec = radtodeg(anglec)

   length = len(anglea)
   for i in range (0,length):
       z = anglea[i:i + 1]
       z = ord(z)
       if z == 45:
          num1 = float(anglea[1:i])
          num2 = float(anglea[i+1:length - 2])
          angle1 = math.degrees(num1 - num2)
          
           

   length = len(angleb)
   for i in range (0,length):
       z = angleb[i:i + 1]
       z = ord(z)
       if z == 45:
           num1 = float(angleb[1:i])
           num2 = float(angleb[i+1:length - 2])     
           angle2 = math.degrees(num1 - num2)
   
   length = len(anglec)
   for i in range (0,length):
       z = anglec[i:i + 1]
       z = ord(z)
       if z == 45:
           num1 = float(anglec[1:i])
           num2 = float(anglec[i+1:length - 2])     
           angle3 = math.degrees(num1 - num2)
                               
   A = int(A + 0.5)
   P = int(P + 0.5)
   a = int(a + 0.5)
   b = int(b + 0.5)
   c = int(c + 0.5)
   angle1 = int(angle1 + 0.5)
   angle2 = int(angle2 + 0.5)
   angle3 = int(angle3 + 0.5)

   print ("")
   if x2 - x1 == 0: 
      mb = slope(x2, y2, x3 , y3)
      mc = slope(x3, y3, x1, y1)
      print ("The slope line a is undefined")
      print ("The slope of side b", mb)
      print ("The slope of side c",mc)
   elif x3 - x2 == 0:    
      ma = slope(x1, y1, x2, y2)
      mc = slope(x3, y3, x1, y1)
      print ("The slope of side a", ma)
      print ("The slope line b is undefined")
      print ("The slope of side c",mc)
   elif x1 - x3 == 0:     
      ma = slope(x1, y1, x2, y2)
      mb = slope(x2, y2, x3 , y3)
      print ("The slope of side a", ma)
      print ("The slope of side b", mb)
      print ("The slope of line c is undefined") 
   else:   
      ma = slope(x1, y1, x2, y2)
      mb = slope(x2, y2, x3 , y3)
      mc = slope(x3, y3, x1, y1)
      print ("The slope of side A", ma)
      print ("The slope of side B", mb)
      print ("The slope of side C", mc)

   if ma == mb and ma == mb:
       print("This is collinear and does not form a triangle")
    
   print ("") 
   print ("The length of side A", a)
   print ("The length of side B", b)
   print ("The length of side C", c)

   print ("") 
   print ("Angle a is", angle1, "degrees")
   print ("Angle b is", angle2, "degrees")
   print ("Angle c is", angle3, "degrees")

   print ("")
   print ("The perimeter of the triangle is", P)
   print ("The area of the triangle is", A)

   print ("") 
   if ma * mb == -1 or mb * mc == -1 or ma * mc == -1:
      print("This is a right angled triangle")
   if a == b and a == c:
      print ("This is an equilateral triangle")
   if a == b and a != c or b == c and b != a or a == c and a != b:
      print ("This is an isosceles triangle")
   if a != b and a != c and b != c:
       print ("This is a scalene triangle")

   if angle1 < 90 and angle2 < 90 and angle3 < 90:
      print ("This is an acute triangle")
   if angle1 > 90 or angle2 > 90 or angle3 > 90:
      print ("This is an obtuse triangle")
    
main()

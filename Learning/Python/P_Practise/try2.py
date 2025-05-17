class C:
   def __init__(self,x,y):
     self.x = x
     self.y = y
   def add(self):
     return self.x + self.y 
   def mul(self):
     return self.x * self.y
class D(C):
   def __init__(self,x,y,z):
      C.__init__(self,x,y)
      self.z = z
   def add(self):
     return C.add(self) + self.z
   def mul(self):
     return C.mul(self) * self.z
   
"""这个是没有设置精灵类的版本"""

import random

import pygame
 
from pygame.constants import * #可以导入pygame.constants的所有方法

class enemyPlane1():
   def __init__(self,screen): 
      self.enplane1 = pygame.image.load("./picture/enemy1.png") #敌机1图片 57*43
      
      self.x = 0
      self.y = 0

      self.speed = 4  # 速度

      self.screen = screen #记录当前的窗口对象    
      
      self.bullets = [] # 子弹列表

      self.direction = 'right' #敌机初始移动方向
   def display(self):   
      self.screen.blit(self.enplane1,(self.x, self.y)) #显示飞机

      for bullet in self.bullets: #遍历所有子弹
         
         bullet.display() #显示子弹  
         
         bullet.move()
   def auto_fire(self):
      random_num = random.randint(1,10)
      if random_num == 8:

         bullet = EnemyBullet1(self.screen,self.x,self.y) #创建子弹对象

         self.bullets.append(bullet)

   def auto_move(self):#敌机向下移动
      
      if self.direction == 'right':
         self.x += self.speed

      elif self.direction == 'left':
         self.x -= self.speed
      if self.x > 456-57:
         self.direction = 'left'
      elif self.x < 0:
         self.direction = 'right'

# 子弹类
class EnemyBullet1():
   def __init__(self,screen,x,y):
      self.x = x+58/2-3
      self.y = y+43
      
      self.image = pygame.image.load("./picture/zidan1.png") #加载子弹图片  
      
      self.screen = screen

      self.speed = 10
      
   def display(self):
      self.screen.blit(self.image,(self.x, self.y)) #显示子弹
   def move(self):#子弹向上移动
      self.y += self.speed       
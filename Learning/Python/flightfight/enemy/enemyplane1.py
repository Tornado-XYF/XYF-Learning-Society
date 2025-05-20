
import random

import pygame
 
from pygame.constants import * #可以导入pygame.constants的所有方法

class enemyPlane1(pygame.sprite.Sprite):
   def __init__(self,screen): 
      pygame.sprite.Sprite.__init__(self)

      self.enplane1 = pygame.image.load("./picture/enemy1.png") #敌机1图片 57*43
      
      self.rect = self.enplane1.get_rect() #让敌机的图片成为一个矩形
      self.rect.topleft = [0,0]

      self.speed = 4  # 速度

      self.screen = screen #记录当前的窗口对象    
      
      self.bullets = pygame.sprite.Group() # 子弹列表

      self.direction = 'right' #敌机初始移动方向
   def display(self):   
      self.screen.blit(self.enplane1,self.rect) #显示飞机

      self.bullets.update() #更新子弹坐标

      self.bullets.draw(self.screen)#显示子弹
   def auto_fire(self):
      random_num = random.randint(1,10)
      if random_num == 8:

         bullet = EnemyBullet1(self.screen,self.rect.left,self.rect.top) #创建子弹对象

         self.bullets.add(bullet)

   def auto_move(self):#敌机向下移动
      
      if self.direction == 'right':
         self.rect.right += self.speed

      elif self.direction == 'left':
         self.rect.left -= self.speed

      if self.rect.right > 456:
         self.direction = 'left'
      elif self.rect.left < 0:
         self.direction = 'right'
   def update(self):
      self.auto_move()
      self.auto_fire()
      self.display()
# 子弹类
class EnemyBullet1(pygame.sprite.Sprite):
   def __init__(self,screen,x,y):
      pygame.sprite.Sprite.__init__(self)
      
            
      self.image = pygame.image.load("./picture/zidan1.png") #加载子弹图片  
      
      self.rect = self.image.get_rect()
      self.rect.topleft = [x+58/2-3,y+43]

      self.screen = screen

      self.speed = 10
   
   def update(self):#子弹向上移动
      self.rect.top += self.speed

      if self.rect.top > 685:
         self.kill()         # 超出界面则删除子弹对象   
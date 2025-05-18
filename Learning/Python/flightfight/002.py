import time 

import pygame

from pygame.constants import * #可以导入pygame.constants的所有方法

from enemy.enemyplane1 import * # 敌机一号

from HeroPlane.Original import * #英雄飞机

from BGM.bgm import * #背景音乐

def main():
   """完成整个程序的控制"""
         #1创建一个窗口
   sound = Gamesound()
   sound.playBGM()
   screen = pygame.display.set_mode((456,665),0,32)
   bg = pygame.image.load("./picture/BGP3.png")
   player = CommonPlane(screen)
   enemy1 = enemyPlane1(screen) # 创建敌人飞机对象
#2创建一个背景图片
   while True:
      #3将背景图片贴到窗口
      screen.blit(bg,(0,0)) #blit是将图片贴到窗口的意思，第一个参数是图片，第二个参数是坐标
   
      #获取事件，比如按键等
      for event in pygame.event.get():
         #判断事件类型
         if event.type == QUIT: #QUIT是退出的意思，这个事件是当点击窗口的关闭按钮的时候触发的
            pygame.quit()#执行pygame退出
            exit()  #python退出
      player.key_control() # 监听键盘事件
      player.display()# 显示飞机
      enemy1.display()#显示敌机
      enemy1.auto_move()#敌机自动移动
      enemy1.auto_fire()#自动射击
      time.sleep(0.02)
      pygame.display.update()#4显示窗口内容
#这串代码可以判断出是直接运行这个文件，还是被引入执行的，这样可以让程序只有在直接运行这个文件的时候才执行main函数，被引入执行的话就不执行main函数了
if __name__ == '__main__':
   main()
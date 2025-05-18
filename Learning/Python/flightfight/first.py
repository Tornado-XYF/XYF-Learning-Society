import time 

import pygame

from pygame.constants import * #可以导入pygame.constants的所有方法

def main():
   """完成整个程序的控制"""
#1创建一个窗口
   screen = pygame.display.set_mode((456,665),0,32)

#2创建一个背景图片
   bg = pygame.image.load(".\picture\BGP3.png")
   player = pygame.image.load(".\picture\player.png") #飞机图片
   x = 210
   y = 600
   speed = 10
   while True:
      #3将背景图片贴到窗口
      screen.blit(bg,(0,0)) #blit是将图片贴到窗口的意思，第一个参数是图片，第二个参数是坐标
      screen.blit(player,(x, y)) #飞机图
   
      #获取事件，比如按键等
      for event in pygame.event.get():
         #判断事件类型
         if event.type == QUIT: #QUIT是退出的意思，这个事件是当点击窗口的关闭按钮的时候触发的
            pygame.quit()#执行pygame退出
            exit()  #python退出
        # 以下是监听键盘事件
      key_pressed = pygame.key.get_pressed() #key指键盘，get_pressed是按住
      
      if key_pressed[K_w] or key_pressed[K_UP]:
            print("上")
            y-=speed
      if key_pressed[K_a] or key_pressed[K_LEFT]:
            print("左")
            x-=speed
      if key_pressed[K_d] or key_pressed[K_RIGHT]:
            print("右")
            x+=speed
      if key_pressed[K_s] or key_pressed[K_DOWN]:
            print("下")
            y+=speed
      if key_pressed[K_SPACE]:
            print("空格")
      time.sleep(0.01)
      pygame.display.update()#4显示窗口内容
#这串代码可以判断出是直接运行这个文件，还是被引入执行的，这样可以让程序只有在直接运行这个文件的时候才执行main函数，被引入执行的话就不执行main函数了
if __name__ == '__main__':
   main()
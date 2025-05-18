import pygame

class Gamesound():
    def __init__(self):
        pygame.mixer.init() #音乐模块初始化
        pygame.mixer.music.load('./BGM/周杰伦 - 龙战骑士.flac')
        pygame.mixer.music.set_volume(0.3) #声音大小

    def playBGM(self):
        pygame.mixer.music.play(-1)#循环播放音乐，-1表示无限循环
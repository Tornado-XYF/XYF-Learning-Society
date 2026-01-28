# linux 命令

## ls命令

1. ls 命令用于显示当前目录下的文件和子目录。
2. ls -a 命令用于显示所有文件（包括隐藏文件）。
3. ls -l 命令用于显示文件的详细信息（权限、所有者、大小、修改时间等）。

## pwd命令

1. pwd 命令用于显示当前工作目录的路径。

## cd命令

1. cd 命令用于切换当前工作目录。
2. cd /path/to/directory 命令用于切换到指定目录。
3. cd .. 命令用于切换到上一级目录
4. cd ../path/to/directory 命令用于切换到上一级目录的指定子目录。
5. cd ~ 命令用于切换到用户的主目录。

## 目录操作

### mkdir命令,创建目录

1. mkdir 命令用于创建新目录。
2. mkdir directory_name 命令用于创建名为 directory_name 的新目录。
3. mkdir -p path/to/directory 命令用于创建多级目录（如果路径不存在）。

### rm命令,删除文件或目录

1. rm 命令用于删除文件或目录。
2. rm file.txt 命令用于删除名为 file.txt 的文件。
3. rm -rf directory_name 命令用于递归删除目录及其内容（谨慎使用）。

### cp命令,复制文件或目录

1. cp 命令用于复制文件或目录。
2. cp source_file.txt destination_file.txt 命令用于将 source_file.txt 复制到 destination_file.txt。如果目标文件已存在，将被覆盖。

### mv命令，移动或重命名文件或目录

1. mv 命令用于移动或重命名文件或目录。
2. mv source_file.txt destination_file.txt 命令用于将 source_file.txt 移动到 destination_file.txt。如果目标文件已存在，将被覆盖。
3. mv directory_name new_directory_name 命令用于将目录重命名为 new_directory_name。

### tar命令,压缩和解压文件

1. tar 命令用于压缩和解压文件。
2. tar -zcvf archive.tar.gz directory_name 命令用于将 directory_name 目录压缩为 archive.tar.gz 文件。
3. tar -zxvf archive.tar.gz 命令用于解压 archive.tar.gz 文件到当前目录。
4. tar -cvf archive.tar directory_name 命令用于将 directory_name 目录归档为 archive.tar 文件。
5. tar -xvf archive.tar 命令用于解压 archive.tar 文件到当前目录。

### 软链接 即快捷方式

软链接特点：

1. 删除软链接不会影响原文件或目录。
2. 删除原文件或目录后，软链接将变为无效。
使用ls -l命令可以查看软链接的详细信息，包括指向的目标文件或目录。

使用方法：

1. ln -s /path/to/target softlink_name 命令用于创建指向 /path/to/target 的软链接，链接名称为 softlink_name。

## 添加用户/修改密码/删除

sudo 表示以管理员身份执行

sudo useradd -m username 命令用于添加新用户

sudo passwd username 命令用于设置新用户的密码或者修改

sudo userdel username 命令用于删除用户

### 超级用户root

首次使用root用户需要设置密码

sudo passwd root 命令用于设置root用户的密码

切换root用户
su - root

退出root用户
exit

### 用户组

创建用户组
sudo groupadd groupname

创建用户并添加到用户组
sudo useradd -m -g groupname username

修改现有用户的用户组
sudo usermod -g groupname username

查看用户和用户组
cat /etc/group
cat /etc/passwd

## 桌面登录root用户

1. 登录普通用户，用终端切换到root用户
su - root

2. 编辑gdm-autologin文件
gedit /etc/pam.d/gdm-autologin

在这一行前面添加注释符号#
`#auth required pam_succeed_if.so user != root quiet_success`
3. 编辑gdm-password文件
gedit /etc/pam.d/gdm-password
在这一行前面添加注释符号#
`#auth required pam_succeed_if.so user != root quiet_success`
4. 关闭虚拟机重启，登录root用户

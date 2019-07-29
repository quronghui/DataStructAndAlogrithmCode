### 15_Include_makefile

1. 为了编写不同目录下Makefile 文件
   - 方法：每个文件下一个Makefile
   - 缺点：
     - 但是子目录文件的make clean，要进入子目录才能进行;
     - 更新子目录下的文件，需要重新进入子目录更新；
   - 所以：不建议使用
对于原来的版本，效率仍然感人。
恰巧看着java BigInteger的源码看起来并灭有大多难以理解的代码。
于是尝试着从java的BigInteger复制出来C++版本，但是似乎也是一个不小的任务。
作为之前的续集，决定先把原来的版本逻辑分离，并采用新的储存方式，似乎可以节省一些空间。
并期望可以提高性能。
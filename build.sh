gcc main.c -o build/main \
-I/opt/homebrew/include/ \
-D_THREAD_SAFE \
-L/opt/homebrew/lib \
-lSDL2 \
-Wall \
-Wextra \
-Iinclude
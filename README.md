# Memetic Algorithm

## How to build:
1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
4. `./main`

## List of know problem:
1. Memory leak.
  * Reproduce: `valgrind --leak-check=full ./main`
  * Possible output: 
  
>  LEAK SUMMARY:  
> ==4230==    definitely lost: 504 bytes in 9 blocks  
> ==4230==    indirectly lost: 2,664 bytes in 57 blocks  
> ==4230==      possibly lost: 0 bytes in 0 blocks  
> ==4230==    still reachable: 0 bytes in 0 blocks  
> ==4230==         suppressed: 0 bytes in 0 blocks  

2. Poor solution for restrincting of size of tree.
  * The size of tree is now restricted to the number of nodes.  

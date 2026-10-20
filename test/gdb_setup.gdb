set startup-with-shell off
set breakpoint pending on
set environment LD_PRELOAD /home/alerusso/Desktop/ft_malloc/libft_malloc.so

break posix_memalign
break aligned_alloc
break malloc_usable_size

run
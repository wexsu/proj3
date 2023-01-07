#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_get_cpu_number 700

/*struct getcpu_cache
{
    unsigned long blolb[128/sizeof(long)];
}*/

int getcpu( unsigned *cpu, unsigned *node )
{
    return syscall( SYS_getcpu, cpu, node, NULL );
}

/*int get_cpu_number( unsigned *cpu )
{
    return syscall( __NR_get_cpu_number, cpu );
}*/

int main()
{
    unsigned cpu;
    unsigned node;

    if( getcpu( &cpu, &node )==-1 )
    {
        printf( "getcpu failed\n" );
        return 1;
    }

    printf( "cpu = %u, node = %u \n", cpu, node );

    return 0;
}

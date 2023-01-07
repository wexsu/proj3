#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_get_cpu_number 700

int getcpu( unsigned *cpu, unsigned *node )
{
    return syscall( SYS_getcpu, cpu, node, NULL );
}

int get_cpu_number( unsigned *cpu )
{
    return *cpu = syscall( __NR_get_cpu_number );
}

int main(void)
{
    unsigned cpu;
    unsigned node;

    if( get_cpu_number(&cpu)==-1 )
    {
        printf( "getcpu failed\n" );
        return 1;
    }
    
    printf( "mysys: cpu = %u \n", cpu );
    

    if( getcpu( &cpu, &node )==-1 )
    {
        printf( "getcpu failed\n" );
        return 1;
    }

    printf( "getcpu: cpu = %u, node = %u \n", cpu, node );

    return 0;
}

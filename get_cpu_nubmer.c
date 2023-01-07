#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/init_task.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

SYSCALL_DEFINE0(get_cpu_number){
    unsigned   recent_used_cpu;
    recent_used_cpu=current->cpu;
    return recent_used_cpu;
}

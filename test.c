#include <linux/kernel.h>
#include <linux/linkage.h>
#include <asm/uaccess.h> // used to copy the result from kernel space to user space

asmlinkage long sys_csci3753_mult(int number1, int number2, long *result)
{
    long temp;

    printk(KERN_INFO "multiplying: %d * %d\n", number1, number2);
    temp = number1 * number2;
    printk(KERN_INFO "result: %ld\n", temp);

    if (copy_to_user(result, &temp, sizeof(long))) {
        printk(KERN_ERR "kernel failed to copy result to user space\n");
        return -1;
    }

    return 0;
}

# A Kernel Seedling

This kernel module shows the current number of processes that are Executening.

## Building

Step 1: Execute the command "make" to build the module.
Step 2: Execute the command "sudo insmod proc_count.ko" to insert the modle into the kernel.

## Running

Step 1: Execute "cat /proc/count" to view the contents of the /proc/count file. The expected 
output will be an integer indicating the current number of running processes.

## Cleaning Up

Step 1: Execute the command "sudo rmmod proc_count" to remove the model from the kernel. 
Step 2: Execute the command "make clean" to get rid of the object and executable files.

## Testing

I tested the module on kernel version 5.14.8

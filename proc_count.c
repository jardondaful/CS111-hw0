#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

//helper function that shows number of processes running
static int displaying_num_processes_running(struct seq_file *cat_file, void *v)
{
  struct task_struct *p;
  int num = 0;
  
  for_each_process(p) 
  {
    num = num + 1;
  }
  
  seq_printf(cat_file, "%d\n", num);
  return 0;
}

static int __init proc_count_init(void)
{
  //using helper function for  registration
  proc_create_single("count", 0777, NULL, displaying_num_processes_running);
  
  pr_info("proc_count: init\n");
  
  return 0;
}

static void __exit proc_count_exit(void)
{
  remove_proc_entry("count", NULL);
  
  pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Jordan Lin");
MODULE_DESCRIPTION("This program shows the current number of processes running.");
MODULE_LICENSE("GPL");
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched/signal.h>

static int 
prtree_show(struct seq_file *m, void *v)
{
  struct task_struct *task; //Pointer to the task whose info will be printed

  //Loop over the tasks using the macro for_each_process
  for_each_process(task) {
    seq_printf(m,"%9d %9d\n", task->real_parent->pid, task->pid);
  }

  return 0;
}

static int
prtree_open(struct inode *inode, struct file *file)
{
  return single_open(file, prtree_show, NULL);
}

static const struct file_operations prtree_fops = {
  .owner	= THIS_MODULE,
  .open	= prtree_open,
  .read	= seq_read,
  .llseek	= seq_lseek,
  .release	= single_release,
};

static int __init 
prtree_init(void)
{
  printk(KERN_INFO "Loading pstree module.\n");
  proc_create("pstree", 0, NULL, &prtree_fops);
  return 0;
}


  static void __exit
prtree_exit(void)
{
  printk(KERN_INFO "Unloading pstree module.\n");
  remove_proc_entry("pstree", NULL);
}

module_init(prtree_init);
module_exit(prtree_exit);

MODULE_LICENSE("GPL"); 

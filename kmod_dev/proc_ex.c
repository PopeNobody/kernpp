#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#define BUFSIZE  100
 
 
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liran B.H");
 
 
int pstree_show(struct seq_file *m, void *v) {
  int ret=0;
  printk(KERN_INFO "pstree_show(%p,%p)", m, v);
  seq_printf(m,"this is a test.  (%p)\n",m);
  seq_printf(m,"this is another.  (%p)\n",v);
  return ret;
};
struct proc_dir_entry *ent;
static int simple_init(void)
{
	ent = proc_create_single("pstree",0664,NULL,&pstree_show);
	return 0;
}
 
static void simple_cleanup(void)
{
}
 
module_init(simple_init);
module_exit(simple_cleanup);

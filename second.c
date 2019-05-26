#include <linux/module.h>          
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/sched/signal.h>
#include <asm/pgtable.h>
#include <asm/page.h>  
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/fs_struct.h>
#include <linux/fdtable.h>
#include <linux/rcupdate.h>
#include <linux/dcache.h>
#include <linux/slab.h>
#include <linux/radix-tree.h>
#include <linux/pagemap.h>
#include <linux/buffer_head.h>

MODULE_LICENSE("Dual BSD/GPL");              
MODULE_AUTHOR("Yusuf Samsum and Firat Yildiz");

static int processid = 0;
module_param(processid, int, 0);

static int __init hello_init(void){
 
  struct task_struct *task = current;
  struct task_struct *current_task;

  for_each_process(current_task) {
    if (current_task->pid == processid)
      break;
  }
  printk("Given process: %s [%d]\n",current_task->comm , current_task->pid);
 
  struct fs_struct *current_fs = current_task->fs;

  struct files_struct * current_files = current_task->files;
 
  struct fdtable *fdt = current_files -> fdt;

  struct file ** fds = fdt -> fd;

  char *cwd;
  char *pwd;
  char buf[100];
  char wdbuf[100];
  int i = 0;
 
  while( fds[i] != NULL ){

    // file path
    struct path files_path = fds[i]->f_path;

    cwd = d_path(&files_path,buf,100*sizeof(char));

    // d_inode
    struct dentry * directory = files_path.dentry;

    struct inode * inode = directory -> d_inode;

    // name

    struct qstr d_name = directory->d_name;

    // user id

    unsigned int uid = inode -> i_uid.val;

    // inode number

    unsigned long ino_number = inode -> i_ino;

    // current file position pointer

    long long file_position = fds[i]->f_pos;

    // access process mode

    unsigned int process_mode = fds[i]->f_mode;

    // file length

    long long file_length = inode -> i_size;

    // number of allocated blocks

    unsigned no_of_block = inode -> i_blocks;

    // current working directory from fs field of the task struct

    struct path current_path = current_fs -> pwd;

    pwd = d_path(&current_path,wdbuf,100*sizeof(char));


    // printing all the stuff

    printk("File Descriptor Number: %d Current File Position ptr: %lld",i,file_position);

    printk( "User id: %d", uid);

    printk( "Process Access Mode: %d", process_mode);
   
    printk( "Directory Name: %s", d_name.name);

    //printk( "Current Working Directory: %s",cwd); it is cancelled because it is not from fs field of task_struct
   
    printk( "Inode Number: %ld", ino_number);
   
    printk("File length: %lld", file_length);
   
    printk( "Number of Blocks Allocated: %d", no_of_block);
   
    printk("Current working directory: %s", pwd);


    // cached pages

    struct address_space * mapping = inode -> i_mapping;

    unsigned long page_number = mapping->nrpages;

    printk( "Number of page: %ld", page_number);

    int k = 0;
    for (; k < page_number; ++k)
    {
      struct page * my_page = find_get_page(mapping, k);

      struct buffer_head * bf_head = (struct buffer_head *)(my_page -> private);

      //atomic_t buffer_count = bf_head -> b_count;

      //printk( "Buffer count: %d", buffer_count );

      printk( "Start of block number is: %ld", bf_head -> b_blocknr);

      struct block_device * b_dev = bf_head -> b_bdev;

      unsigned long block_is_in = b_dev -> bd_dev;

      printk( "The storage device ID is in: %d", block_is_in);

    }

    i++;
  }

  unsigned long * open_fds = fdt -> open_fds;

  // testing
  //atomic_t count = current_files -> count;
  //printk( "Count is: %d", count );
 
  return 0;
}

static void __exit hello_exit(void){
printk( KERN_ALERT "Goodbye, Module will miss you");
}

module_init(hello_init);
module_exit(hello_exit);

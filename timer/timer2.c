#include <linux/module.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("kinoshita kazumi <e145702@ie.u-ryukyu.ac.jp>");
MODULE_DESCRIPTION("timer kernel module : periodic timer");

struct timer_list mytimer;

#define MYTIMER_TIMEOUT_SECS 10

static void mytimer_fn(unsigned long arg)
{
	printk(KERN_ALERT "10 secs passed.\n");
	mod_timer(&mytimer, jiffies + MYTIMER_TIMEOUT_SECS*HZ);
}

static int mymodule_init(void)
{
	init_timer(&mytimer);
	mytimer.expires = jiffies + MYTIMER_TIMEOUT_SECS*HZ;
	mytimer.data = 0;
	mytimer.function = mytimer_fn;
	add_timer(&mytimer);

	return 0;
}

static void mymodule_exit(void)
{
	del_timer(&mytimer);
}

module_init(mymodule_init);
module_exit(mymodule_exit);


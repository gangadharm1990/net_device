#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/module.h> 
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/skbuff.h>  
#include <linux/udp.h>
#include <linux/ip.h>
#include <linux/in.h>
#include <linux/string.h>
#include <linux/init.h>
#include <linux/net.h>
#include <linux/netdevice.h>
#include <linux/socket.h>
#include <linux/sockios.h>
#include <linux/inet.h>
#include <linux/inetdevice.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/if_arp.h>
#include <linux/icmp.h>
#include <linux/netlink.h>
#include <linux/mroute.h>
#include <net/checksum.h>
#include <net/inet_ecn.h>
#include <net/xfrm.h>
#include <net/route.h>
#include <net/sock.h>
#include <net/ip.h>
#include <net/tcp.h>
#include <net/arp.h>
#include <net/udp.h>
#include <net/icmp.h>
#include <net/inetpeer.h>
#include <net/protocol.h>
#include <net/flow.h>
#include <asm/types.h>
//#include <arpa/inet.h>
#include <linux/inet.h>

static int mymodule_init(void)
{
	struct in_device *in_dev;
	struct in_ifaddr *if_info;
	struct net_device *dev = dev_get_by_name(&init_net,"eth0");
	while(dev)
	{
		printk("Dev name = %s and index is %d\n",dev->name, dev->ifindex);
		printk("dev state is %d\n",dev->state);
		if(netif_running(dev))
		{
			printk("device up\n");
		}
		else
			printk("device down\n");

		if(test_bit(__LINK_STATE_NOCARRIER, &dev->state)) { printk("NOCARRIER set\n"); } else { printk("NOCARRIER NOT-set\n"); }
		dev = next_net_device(dev);
	}
	return 0;
}
	
static void exit_module(void)
{
	printk("%s module removed",__FILE__);
}	

module_init(mymodule_init);
module_exit(exit_module);

MODULE_AUTHOR("Gangadhara");
MODULE_LICENSE("GPLv2");
	 



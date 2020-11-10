
"""

2001:638:709:a::/64 2001:638:709:f::/64 2001:638:709:b::/64
.------------------..------------------..------------------.
h1 ------ s1 ------ r1 ------ s0 ------ r2 ------ s2 ------ h2
eth0            eth0 eth1            eth0 eth1            eth0

"""


from mininet.net import Mininet

from mininet.node import Controller, RemoteController, OVSKernelSwitch, UserSwitch

from mininet.cli import CLI

from mininet.log import setLogLevel

from mininet.link import Link, TCLink
 

def topology():

        net = Mininet( controller=RemoteController, link=TCLink, switch=OVSKernelSwitch )

 

        # Add hosts and switches

        h1 = net.addHost( 'h1', mac='00:00:00:00:00:01', ip=None)
        h2 = net.addHost( 'h2', mac='00:00:00:00:00:02', ip=None)
        r1 = net.addHost( 'r1')
        r2 = net.addHost( 'r2')
        s1 = net.addSwitch( 's1')
        s2 = net.addSwitch( 's2')
        s0 = net.addSwitch( 's0')
        c0 = net.addController( 'c0', controller=RemoteController, ip='127.0.0.1', port=6633 )

 

        net.addLink( h1, s1)
        net.addLink( r1, s1)
        net.addLink( r1, s0)
        net.addLink( h2, s2)
        net.addLink( r2, s2)
        net.addLink( r2, s0)


        net.build()

       



        h1.cmd("ip addr add 2001:638:709:a::1/64 brd + dev h1-eth0")
        h2.cmd("ip addr add 2001:638:709:b::1/64 brd + dev h2-eth0")

        r1.cmd("ifconfig r1-eth0 0")
        r1.cmd("ifconfig r1-eth1 0")
        r1.cmd("ifconfig r1-eth0 hw ether 00:00:00:00:01:01")
        r1.cmd("ifconfig r1-eth1 hw ether 00:00:00:00:01:02")
        r1.cmd("ip addr add 2001:638:709:a::f/64 brd + dev r1-eth0")
        r1.cmd("ip addr add 2001:638:709:f::1/64 brd + dev r1-eth1")
        r1.cmd("echo 1 > /proc/sys/net/ipv6/ip_forward")

        s1.cmd("ovs-ofctl add-flow s1 priority=1,arp,actions=flood")
        s1.cmd("ovs-ofctl add-flow s1 priority=65535,ip,dl_dst=00:00:00:00:01:01,actions=output:1")
        s1.cmd("ovs-ofctl add-flow s1 priority=10,ip,nw_dst=2001:638:709:a::0/64,actions=output:2")

        r2.cmd("ifconfig r2-eth0 0")
        r2.cmd("ifconfig r2-eth1 0")
        r2.cmd("ifconfig r2-eth0 hw ether 00:00:00:00:02:01")
        r2.cmd("ifconfig r2-eth1 hw ether 00:00:00:00:02:02")
        r2.cmd("ip addr add 2001:638:709:f::2/64 brd + dev r2-eth0")
        r2.cmd("ip addr add 2001:638:709:b::f/64 brd + dev r2-eth1")
        r2.cmd("echo 1 > /proc/sys/net/ipv6/ip_forward")

        s0.cmd("ovs-ofctl add-flow s0 priority=1,arp,actions=flood")
        s0.cmd("ovs-ofctl add-flow s0 priority=65535,ip,dl_dst=00:00:00:00:01:02,actions=output:1")
        s0.cmd("ovs-ofctl add-flow s0 priority=10,ip,nw_dst=2001:638:709:f::0/64,actions=output:2")

        s2.cmd("ovs-ofctl add-flow s2 priority=1,arp,actions=flood")
        s2.cmd("ovs-ofctl add-flow s2 priority=65535,ip,dl_dst=00:00:00:00:02:01,actions=output:1")
        s2.cmd("ovs-ofctl add-flow s2 priority=10,ip,nw_dst=2001:638:709:b::0/64,actions=output:2")


        c0.start()
        s1.start( [c0] )
        s2.start( [c0] )
        s0.start( [c0] )

        CLI( net )
        net.stop()

      

if __name__ == '__main__':

    setLogLevel( 'info' )

    topology() 
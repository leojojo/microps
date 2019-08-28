sudo ip tuntap add mode tap user $USER name tap0
sudo ip addr add 172.16.100.10/24 dev tap0
sudo ip link set tap0 up
ip a

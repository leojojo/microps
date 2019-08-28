## sock_echo
### server
```
./test/create_tap.sh
sudo ./apps/sock_echo tap0 static 172.16.100.100 255.255.255.0
```

### client
```
nc 172.16.100.100 7 -u
```

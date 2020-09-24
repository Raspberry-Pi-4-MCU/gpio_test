## mmap for linux

- build:
```
make
```

- test:
```
sudo make test
```

- clean:
```
make clean
```

- get gpio base address:
```
cat /proc/iomem | grep gpio
```

[Raspberry pi 4 datasheet](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/rpi_DATA_2711_1p0.pdf)
## For Wifi:

### Firmware:
plattformio.ini example:

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
build_flags = -I conf
board_microros_distro = humble
board_microros_transport = wifi ;needed for WiFi
lib_deps =
    https://github.com/micro-ROS/micro_ros_platformio
```

### Agent:
```sh
ros2 run micro_ros_agent micro_ros_agent udp4 -p 8888
```

## For Serial:

plattformio.ini example:

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
build_flags = -I conf
board_microros_distro = humble
monitor_speed = 115200
lib_deps =
    https://github.com/micro-ROS/micro_ros_platformio
```
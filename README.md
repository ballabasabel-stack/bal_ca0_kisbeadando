# `bal_ca0_kisbeadando` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/ballabasabel-stack/bal_ca0_kisbeadando
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select bal_ca0_kisbeadando --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch bal_ca0_kisbeadando launch_example1.launch.py
```

### Ez egy random vonalfüggvény
### Ezzel a kóddal jelenítem meg a programot
``` r
ros2 run rqt_plot rqt_plot
```

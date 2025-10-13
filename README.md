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
### Általános szerkezet és cél
A projekt célja egy egyszerű ROS 2 csomag létrehozása, amely Python nyelvű node-okat indít, amelyek egymással kommunikálnak témák (topics) segítségével és egy szinusz illetve egy koszinusz jelet hoznak létre. Egy “trigger” (kiváltó) mechanizmust valósít meg: van egy publisher, ami üzeneteket küld, és egy subscriber, ami ezeket fogadja, majd valamilyen reakciót hajt végre.

A launch_example1.launch.py útindító fájl gondoskodik róla, hogy mindkét node elinduljon egyetlen parancs segítségével.

A setup.py, setup.cfg és package.xml fájlok a Python csomag / ROS2 csomag metaadatait és függőségeit definiálják.

### trig_publisher.py
Fő funkció:
Egy ROS 2 node, ami időközönként publikál üzeneteket egy témára (topic).

Az üzenet tartalmaz egy “trigger” információt.

Néhány részlet:

A node inicializálása után létrehoz egy publisher-t egy adott topic névre, egy adott üzenettípusra (pl. std_msgs.msg.String vagy más).

Egy timer (időzítő) callback függvény hívódik meg ismétlődően, amely elkészíti az üzenetet és elküldi a topic-ra.

Ez az a komponens, amely kiváltja az eseményt, amire a subscriber reagál.

### trig_supscriber.py
Fő funkció:

Egy ROS 2 node, ami feliratkozik ugyanarra a topicra, amelyre a publisher küld.

Amikor új üzenetet kap, meghív egy callback függvényt, amely feldolgozza az üzenetet, és adott esetben további műveletet hajt végre.

### package.xml
Ez a ROS2 csomag metaadatait tartalmazó XML fájl (pl. csomagnév, verzió, leírás, szerző, licenc, ROS csomagfüggőségek).

# ❖ UC-main
The main repository for projects

⦿ `Pull Request for development`

``` bash
# by git without submodules
git clone https://github.com/ZhixiangLiu-SunGrid/UC-main.git

# by git with submodules
git clone --recursive https://github.com/ZhixiangLiu-SunGrid/UC-main.git
````

⦿ `Hooks Setup`: Ensure you have the necessary access permissions on your OS.

|     Winsows     |      Linux      |
| --------------- |:---------------:|
|  win_setup.bat  |  linux_setup.sh |

``` bash
# for Windows
right click "win_setup.bat" in "hooks/" folder & click "Run as Administrator"

# for Linux
$ cd UC-main/hooks && chmod +x linux_setup.sh && ./linux_setup.sh
````

⦿ `PLCnext Target setup`: Ensure that the PLCnext target is reset every time the project is pulled.
``` bash
Right Click project "UnitCtrl(Linux)" ==> PLCnext technology ==> Set Targets
````

⦿ `Click here to cite the UC-tool and UC-core submodules`    
👉[UC-tool](https://github.com/ZhixiangLiu-SunGrid/UC-tool)  
👉[UC-core](https://github.com/ZhixiangLiu-SunGrid/UC-core)